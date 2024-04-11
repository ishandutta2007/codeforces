#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

struct pt { // or vector2d
    int x, y;
    pt (int x1, int y1) : x (x1), y (y1) {};
};

struct dancer {
    pt startpoint, velocity;
    int alt_time, id;
    dancer(pt s, pt v, int a, int i) : startpoint(s), velocity(v), alt_time (a), id (i) {};
    // actually alt_time can be calculated from startpoint
};

struct dancer_startpt {
    int x, y, id;
    dancer_startpt(int x, int y, int i) : x(x), y(y), id(i) {}
};

const int gr_vertical = 1, gr_horizontal = 2;

int main() {
    int n, w, h;
    std::cin >> n >> w >> h;
    std::vector<dancer> dancers;
    for (int i = 0; i < n; ++i) {
        int group, pos, time;
        std::cin >> group >> pos >> time;
        pt v = group == gr_vertical ? pt(0,1) : pt(1,0),
        start = group == gr_vertical ? pt(pos, 0) : pt(0, pos);
        start.x -= v.x * time; start.y -= v.y * time;
        // let t' = t + p.x + p.y (p : pos) then
        int alt_time;
//        if (v.x != 0) {
            // it must be 1
            alt_time = - start.y - start.x;
//        } else // the situation is the same
        dancers.emplace_back(start, v, alt_time, i);
    }
    std::sort(dancers.begin(), dancers.end(), [](const dancer& x, const dancer& y){
//        if (x.alt_time != y.alt_time)
            return x.alt_time < y.alt_time;
//        return x.v.x < y.v.x; // this way vx=0 (vertical) will be before vx=1 (horizontal)
    });

    int z = 0, pre;
    std::vector<pt> result (n, pt(0,0));
    while (z < dancers.size()) {
        pre = z; ++z;
        while (z < dancers.size() && dancers[z-1].alt_time == dancers[z].alt_time) ++z; // now z is the first in different group than pre
        // or an nonexistent group. We only consider dancers in range [pre, z)
        std::vector<pt> finish;
        std::vector<dancer_startpt> start;
        for (int i = pre; i < z; ++i) {
            const dancer d = dancers[i];
            if (d.velocity.x == 0) {
                // vertical
                start .emplace_back(d.startpoint.x, 0, d.id);
                finish.emplace_back(d.startpoint.x, h);
            } else {
                start .emplace_back(0, d.startpoint.y, d.id);
                finish.emplace_back(w, d.startpoint.y);
            }
        }
        std::sort(start .begin(), start .end(), [](dancer_startpt a, dancer_startpt b){return a.x-a.y<b.x-b.y;});
        std::sort(finish.begin(), finish.end(), [](pt a, pt b){return a.x-a.y<b.x-b.y;});

        for (int i = 0; i < start.size(); ++i) {
            result[start[i].id] = finish[i];
        }
    }
    for (int i = 0; i < n; ++i) std::cout << result[i].x << ' ' << result[i].y << '\n';
}