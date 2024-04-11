#include<vector>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct Point {
    double x, y;

    Point (double x = 0, double y = 0) : x(x), y(y) {}

    void in() {
        scanf("%lf%lf", &x, &y);
    }

    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }

    double dis() const {
        return sqrt(x * x + y * y);
    }
};

int sign(const double &x, const double EPS = 1e-9) {
    return x < -EPS ? -1 : x > EPS;
}

double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

double det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

const int N = 100005;

int n;

Point o, p[N];

const double PI = acos(-1);

int main() {
    scanf("%d", &n);
    o.in();
    double mins = 1e100, maxs = 0;
    for (int i = 0; i < n; ++i) {
        p[i].in();
    }
    p[n] = p[0];
    for (int i = 0; i < n; ++i) {
        maxs = max(maxs, (p[i] - o).dis());
        mins = min(mins, (p[i] - o).dis());
        if (sign(dot(o - p[i], p[i + 1] - p[i])) >= 0 && sign(dot(o - p[i + 1], p[i] - p[i + 1])) >= 0) {
            mins = min(mins, fabs(det(p[i + 1] - p[i], o - p[i]) / (p[i] - p[i + 1]).dis()));
        }
    }
    printf("%.12f\n", PI * (maxs * maxs - mins * mins));
    return 0;
}