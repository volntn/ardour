/*
    Copyright (C) 2016 Paul Davis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __ardour_push2_track_mix_layout_h__
#define __ardour_push2_track_mix_layout_h__

#include <vector>

#include "layout.h"

namespace ARDOUR {
	class Stripable;
}

namespace ArdourCanvas {
	class Text;
}

namespace ArdourSurface {

class Push2Knob;

class TrackMixLayout : public Push2Layout
{
   public:
	TrackMixLayout (Push2& p, ARDOUR::Session&);
	~TrackMixLayout ();

	void set_stripable (boost::shared_ptr<ARDOUR::Stripable>);

	void render (ArdourCanvas::Rect const &, Cairo::RefPtr<Cairo::Context>) const;

	void show ();

	void button_upper (uint32_t n);
	void button_lower (uint32_t n);

	void strip_vpot (int, int);
	void strip_vpot_touch (int, bool);

   private:
	boost::shared_ptr<ARDOUR::Stripable> stripable;
	PBD::ScopedConnectionList stripable_connections;
	bool _dirty;

	std::vector<ArdourCanvas::Text*> upper_text;
	std::vector<ArdourCanvas::Text*> lower_text;

	Push2Knob* knobs[8];

	void stripable_property_change (PBD::PropertyChange const& what_changed);

	PBD::ScopedConnection selection_connection;
	void selection_changed ();

	void drop_stripable ();
	void name_changed ();
	void color_changed ();
};

} /* namespace */

#endif /* __ardour_push2_track_mix_layout_h__ */
