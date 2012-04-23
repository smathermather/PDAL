/******************************************************************************
* Copyright (c) 2012, Michael P. Gerlek (mpg@flaxen.com)
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following
* conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in
*       the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of Hobu, Inc. or Flaxen Consulting LLC nor the
*       names of its contributors may be used to endorse or promote
*       products derived from this software without specific prior
*       written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
* OF SUCH DAMAGE.
****************************************************************************/

#ifndef INCLUDED_DRIVERS_NITF_WRITER_HPP
#define INCLUDED_DRIVERS_NITF_WRITER_HPP

#include <pdal/Writer.hpp>
#include <pdal/drivers/las/Writer.hpp>
#include <pdal/StreamFactory.hpp>


namespace pdal
{
class PointBuffer;

namespace metadata
{
class Entry;
}
namespace drivers
{
namespace las
{
class Writer;
}
}
}



namespace pdal
{
namespace drivers
{
namespace nitf
{


class PDAL_DLL Writer : public pdal::drivers::las::Writer
{
public:
    SET_STAGE_NAME("drivers.nitf.writer", "NITF Writer")

    Writer(Stage& prevStage, const Options&);
    Writer(Stage& prevStage, std::ostream*);
    ~Writer();

    virtual void initialize();
    virtual const Options getDefaultOptions() const;

    // for dumping
    virtual boost::property_tree::ptree toPTree() const;

    static const std::string s_nitfHeader()
    {
        return "LAS GOES HERE --->";
    }
    static const std::string s_nitfFooter()
    {
        return "<--- LAS WENT THERE";
    }

private:
    void ctor();

    virtual void writeBegin(boost::uint64_t targetNumPointsToWrite);
    virtual void writeBufferBegin(PointBuffer const&);
    virtual boost::uint32_t writeBuffer(const PointBuffer&);
    virtual void writeBufferEnd(PointBuffer const&);
    virtual void writeEnd(boost::uint64_t actualNumPointsWritten);

    Writer& operator=(const Writer&); // not implemented
    Writer(const Writer&); // not implemented
};


}
}
} // namespaces


#endif
