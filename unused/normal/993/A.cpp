#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

inline int diff(double lhs, double rhs) {
    if (lhs - eps < rhs && rhs < lhs + eps) return 0;
    return (lhs < rhs) ? -1 : 1;
}

inline bool is_between(double check, double a, double b) {
    if (a < b)
        return (a - eps < check && check < b + eps);
    else
        return (b - eps < check && check < a + eps);
}

struct Point {
    double x, y;
    bool operator==(const Point& rhs) const {
        return diff(x, rhs.x) == 0 && diff(y, rhs.y) == 0;
    }
    Point operator+(const Point& rhs) const {
        return Point{ x + rhs.x, y + rhs.y };
    }
    Point operator-(const Point& rhs) const {
        return Point{ x - rhs.x, y - rhs.y };
    }
    Point operator*(double t) const {
        return Point{ x * t, y * t };
    }
};

struct Line {
    Point pos, dir;
};

inline double inner(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

inline double outer(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

inline int ccw_line(const Line& line, const Point& point) {
    return diff(outer(line.dir, point - line.pos), 0);
}

inline int ccw(const Point& a, const Point& b, const Point& c) {
    return diff(outer(b - a, c - a), 0);
}

inline double dist(const Point& a, const Point& b) {
    return sqrt(inner(a - b, a - b));
}

inline double dist2(const Point &a, const Point &b) {
    return inner(a - b, a - b);
}

inline double dist(const Line& line, const Point& point, bool segment = false) {
    double c1 = inner(point - line.pos, line.dir);
    if (segment && diff(c1, 0) <= 0) return dist(line.pos, point);
    double c2 = inner(line.dir, line.dir);
    if (segment && diff(c2, c1) <= 0) return dist(line.pos + line.dir, point);
    return dist(line.pos + line.dir * (c1 / c2), point);
}

bool get_cross(const Line& a, const Line& b, Point& ret) {
    double mdet = outer(b.dir, a.dir);
    if (diff(mdet, 0) == 0) return false;
    double t2 = outer(a.dir, b.pos - a.pos) / mdet;
    ret = b.pos + b.dir * t2;
    return true;
}

bool get_segment_cross(const Line& a, const Line& b, Point& ret) {
    double mdet = outer(b.dir, a.dir);
    if (diff(mdet, 0) == 0) return false;
    double t1 = -outer(b.pos - a.pos, b.dir) / mdet;
    double t2 = outer(a.dir, b.pos - a.pos) / mdet;
    if (!is_between(t1, 0, 1) || !is_between(t2, 0, 1)) return false;
    ret = b.pos + b.dir * t2;
    return true;
}

Point pt1[4];
Point pt2[4];

bool inside(Point pts[], Point pt)
{
    int z[] = {
        ccw(pts[0], pts[1], pt),
        ccw(pts[1], pts[2], pt),
        ccw(pts[2], pts[3], pt),
        ccw(pts[3], pts[0], pt),
    };
    return z[0] == z[1] && z[0] == z[2] && z[0] == z[3] && z[0] == ccw(pts[0], pts[1], pts[2]);
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        int x, y;
        cin >> x >> y;
        pt1[i] = {x, y};
    }

    for (int i = 0; i < 4; i++)
    {
        int x, y;
        cin >> x >> y;
        pt2[i] = {x, y};
    }

    for (int i = 0; i < 4; i++)
    {
        if (inside(pt2, pt1[i]) || inside(pt1, pt2[i]))
        {
            printf("Yes\n");
            return 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Point dummy;
            if (get_segment_cross({pt1[i], pt1[i + 1 & 3] - pt1[i]}, {pt2[j], pt2[j + 1 & 3] - pt2[j]}, dummy))
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
}