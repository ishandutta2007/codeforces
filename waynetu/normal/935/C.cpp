#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class c> struct rge { c bg, ed; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
#define imie(...) #__VA_ARGS__" = " << (__VA_ARGS__) << " "
struct debug {
~debug() { cerr << endl; }
template <class c> typename \
enable_if <sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename \
enable_if <sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class c, class b> debug &operator<<(pair<c, b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> debug &operator<<(rge<c> d) { *this << "[ "; for (auto it = d.bg; it != d.ed; ++it) *this << ", " + 2 * (it == d.bg) << *it; return *this << " ]"; }
};

const double eps = 1e-9;
double sq(double x) { return x * x; }
double dist(int x1, int y1, int x2, int y2) { return sqrt(sq(x1 - x2) + sq(y1 - y2));}

void solve(int x, int y, int cx, int cy, int R) {
    double d = dist(x, y, cx, cy);
    double dx = x - cx, dy = y - cy;
    dx /= d; dy /= d;
    dx *= (d + R) / 2; dy *= (d + R) / 2;
    double rx = cx + dx, ry = cy + dy;
    double r = (d + R) / 2;
    cout << fixed << setprecision(20) << rx << ' ' << ry << ' ' << r << endl;
}

int main() {
    int R, x1, y1, x2, y2; cin >> R >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2) {
        double r = 1.0 * R / 2 ;
        cout << fixed << setprecision(20) << x1 + r << ' ' << y1 << ' ' << r - eps << endl;
        return 0;
    }
    if (dist(x1, y1, x2, y2) < R) solve(x1, y1, x2, y2, R);
    else solve(x1, y1, x1 + R, y1, R);
    return 0;
}