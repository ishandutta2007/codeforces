#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <complex>

using Real = long double;

using Point = std::complex<Real>;
using Segment = std::pair<Point, Point>;
using Polygon = std::vector<Point>;

template <class T>
T sq(T x) { return x * x; }

bool operator<(const Point& a, const Point& b) {
    return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
}

std::istream& operator>>(std::istream& is, Point& p) {
    Real x, y;
    is >> x >> y;
    p = Point(x, y);
    return is;
}

constexpr Real EPS = 1e-10;

// 
int compare(Real a, Real b) {
    if (std::abs(a - b) < EPS) return 0;
    return a - b > 0 ? 1 : -1;
}

Real dist(Point a, Point b) {
    return std::abs(a - b);
}

Real length(Segment s) {
    return dist(s.first, s.second);
}

Real dot(Point x, Point y) {
    return std::real(std::conj(x) * (y));
}

Point proj(Segment s, Point p) {
    Real ratio = dot(s.second - s.first, p - s.first) / sq(length(s));
    return s.first + (s.second - s.first) * ratio;
}

Real dist(Segment s, Point p) {
    Point t = proj(s, p);
    return dist(p, t);
}

constexpr Real INF = 1e10;

void solve() {
    int n;
    std::cin >> n;

    Polygon poly(n);
    for (auto& p : poly) std::cin >> p;

    Real ans = INF;
    for (int i = 0; i < n; ++i) {
        auto p = poly[i],
             q = poly[(i + 1) % n],
             r = poly[(i + 2) % n];
        auto s = Segment(p, r);
        ans = std::min(ans, dist(s, q) / 2);
    }

    std::cout << std::fixed << std::setprecision(10)
              << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}