#define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>

typedef long long ll;

template <typename T>
struct point { // or vector2d
    T x, y;
    point (T x1, T y1) : x (x1), y (y1) {};
    point operator+(point p) { return point(x+p.x, y+p.y); }
    void operator+=(point p) { x+=p.x; y+=p.y; }
    point operator-(point p) { return point(x-p.x, y-p.y); }
    void operator-=(point p) { x-=p.x; y-=p.y; }
    point operator*(T a)     { return point(x*a, y*a);}
    void operator*=(T a)     { x *= a; y *= a; }
    T norm()                 { return x * x + y * y; }
    T dot  (point p)         { return x*p.x + y*p.y; }
    T cross(point p)         { return x*p.y - y*p.x; }
    ll dist(point<T> p1)     { return sqr(x-p1.x) + sqr(y-p1.y); } // note ll
};

typedef point<ll> pt;

int main() {
    int n;
    std::cin >> n;
    std::vector<ll> a (n);
//    if (n <= 2) {std::cout << "Yes\n"; return 0;}
    std::cin >> a[0];
    for (int i = 1; i < n; ++i) {
        std::cin >> a[i];
        a[i] -= a[0]; // at least -2*10^9, at most 2*10^9
    }
    a[0] = 0;
    std::vector<bool> processed (n, false);
    for (int pt_to0 = 1; pt_to0 < n; ++pt_to0) {
        if (processed[pt_to0]) continue;
        processed[pt_to0] = true;
        std::vector<pt> remain;
        for (int pti = 1; pti < n; ++pti) {
            if (pt_to0 * a[pti] != pti * a[pt_to0])
                remain.emplace_back(pti, a[pti]);
        }
        if (remain.empty()) {
            std::cout << "No\n";
            return 0;
        } // all points on a line
        for (int i = 1; i < remain.size(); ++i) remain[i] -= remain[0];
        remain[0] = pt(0,0);

        pt x (pt_to0, a[pt_to0]);
        for (int i = 1; i < remain.size(); ++i) {
            if (remain[i].cross(x) != 0) goto cont_outer;
        }
        std::cout << "Yes\n";
        return 0;
        cont_outer:;
    }
    // special case: pt 0 is on a different line not containing any ! pts
    pt pt1 (1, a[1]), pt2 (2, a[2]); // guaranteed
    for (int i = 3; i < n; ++i) {
        pt pti (i, a[i]);
        if ((pti - pt1).cross(pt2 - pt1) != 0) goto fail;
    }
    std::cout << "Yes\n"; // if pt1 is also on the line then all points are collinear -> returned long ago
    return 0;
    fail:std::cout << "No\n";
}