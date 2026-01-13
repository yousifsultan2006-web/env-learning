#include <bn_backdrop.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>

#include "bn_sprite_items_dot.h"

#define FLOOR (80 - 4)

int main() {
    bn::core::init();

    bn::backdrop::set_color(bn::color(0, 0, 31));

    auto dot = bn::sprite_items::dot.create_sprite(0, 0);
    
    bn::fixed speed = 5.0;

    bn::fixed dy = 0;
    bn::fixed gravity = .05;

    bn::fixed jump_strength = 3.0;

    while(true) {
        if(bn::keypad::left_held()) {
            dot.set_x(dot.x() - speed);
        }
        if(bn::keypad::right_held()) {
            dot.set_x(dot.x() + speed);
        }
        if(bn::keypad::a_pressed()) {
            dy -= jump_strength;
        }

        dy += gravity;

        dot.set_y(dot.y() + dy);

        if(dot.y() > FLOOR) {
            dot.set_y(FLOOR);
            dy = 0;
        }
        bn::core::update();
    }
}