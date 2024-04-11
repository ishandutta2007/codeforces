#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
using type = double;

struct pt {
    type x, y;
    pt(): x(0), y(0) {}
    pt(type x, type y): x(x), y(y) {}
    pt operator+(const pt& a) const { return pt(x + a.x, y + a.y); }
    pt operator-(const pt& a) const { return pt(x - a.x, y - a.y); }
    pt operator*(const type& t) const { return pt(x * t, y * t); }
    pt operator/(const type& t) const { return pt(x / t, y / t); }
    type operator*(const pt& a) const { return x * a.x + y * a.y; }
    type operator^(const pt& a) const { return x * a.y - y * a.x; }
    bool operator<(const pt& a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pt& a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pt& a) const { return x == a.x && y == a.y; }
    bool operator!=(const pt& a) const { return x != a.x || y != a.y; }
};

type orient(const pt& o, const pt& a, const pt& b) {
    type t = (a - o) ^ (b - o);
    return t / max(type(1), abs(t));
}

// if parallel and min(p1, p2) != max(q1, q2) and p1 != p2 and q1 != q2 ==> segment
// else ==> point

bool intersect(const pt& p1, const pt& p2, const pt& q1, const pt& q2) {
    if (q1 == q2 && p1 == p2) return p1 == q1;
    if (q1 == q2) return ((p2 - q1) ^ (p1 - q1)) == 0 && q1.x >= min(p1.x, p2.x) && q1.x <= max(p1.x, p2.x);
    if (p1 == p2) return ((q1 - p1) ^ (q2 - p1)) == 0 && p1.x >= min(q1.x, q2.x) && p1.x <= max(q1.x, q2.x);
    int c = (p2 - p1) ^ (q2 - q1);
    if (c == 0) {
        if (orient(p1, p2, q1)) return false;
        return (p1 - q1) * (p2 - q1) <= 0 || (p1 - q2) * (p2 - q2) <= 0 || (q1 - p1) * (q2 - p1) <= 0 || (q1 - p2) * (q2 - p2) <= 0;
    }
    return (orient(p1, p2, q1) * orient(p1, p2, q2) <= 0) && (orient(q1, q2, p1) * orient(q1, q2, p2) <= 0);
}

pt intersection(const pt& p1, const pt& p2, const pt& q1, const pt& q2) {
    double f1 = (p2 - p1) ^ (q1 - p1);
    double f2 = (p2 - p1) ^ (p1 - q2);
    double f = f1 + f2;
    if (fabs(f) < eps) return pt(nan(""), nan(""));
    return q1 * (f2 / f) + q2 * (f1 / f);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a1, b1, c1, a2, b2, c2; cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if (a1 == 0 && b1 == 0 && a2 == 0 && b2 == 0) {
        if (c1 == 0 && c2 == 0) cout << "-1" << endl;
        else cout << "0" << endl;
        return 0;
    }
    if (a1 == 0 && b1 == 0) {
        if (c1 == 0) cout << "-1" << endl;
        else cout << "0" << endl;
        return 0;
    }
    if (a2 == 0 && b2 == 0) {
        if (c2 == 0) cout << "-1" << endl;
        else cout << "0" << endl;
        return 0;
    }
    pt p1, p2, q1, q2;
    if (b1 != 0) p1 = pt(0.0, -(1.0 * c1) / (1.0 * b1)), p2 = pt(1.0, (1.0 * (-c1 - a1) / (1.0 * b1)));
    else if (a1 != 0) p1 = pt((-1.0 * c1) / (1.0 * a1), 0.0), p2 = pt((1.0 * (-c1 - b1) / (1.0 * a1)), 1.0);
    if (b2 != 0) q1 = pt(0.0, -(1.0 * c2) / (1.0 * b2)), q2 = pt(1, (1.0 * (-c2 - a2) / (1.0 * b2)));
    else if (a2 != 0) q1 = pt((-1.0 * c2) / (1.0 * a2), 0.0), q2 = pt((1.0 * (-c2 - b2) / (1.0 * a2)), 1.0);
    pt i = intersection(p1, p2, q1, q2);
    if (!intersect(p1, p2, q1, q2) && i.x != i.x) return cout << "0" << endl, 0;
    if (fabs((p1 - p2) ^ (q1 - q2)) < eps) cout << "-1" << endl;
    else cout << "1" << endl;
    return 0;
}