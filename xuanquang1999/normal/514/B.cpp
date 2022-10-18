#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const int maxN = 1005;

bool isEqual(double a, double b) {
    return fabs(a-b) < EPS;
}

struct point {
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y) {}
    void read() {
        scanf("%lf%lf", &x, &y);
    }
};

struct vec {
    double x, y;
    vec(point p1, point p2) {
        x = p2.x-p1.x; y = p2.y-p1.y;
    }
};

double cross(vec v1, vec v2) {
    return v1.x*v2.y - v2.x*v1.y;
}

int CCW(point A, point B, point C) {
    double x = cross(vec(A, B), vec(A, C));
    if (isEqual(x, 0)) return 0;
    if (x > 0) return 1;
    return -1;
}

int n;
point p0, p[maxN];
bool isKilled[maxN];

int main() {
//    freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    p0.read();
    for(int i = 0; i < n; ++i) p[i].read();
//    printf("%.3f %.3f\n", p[0].x, p[0].y);

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if (!isKilled[i]) {
            ++ans;
            for(int j = 0; j < n; ++j) {
                if (CCW(p0, p[i], p[j]) == 0) isKilled[j] = true;
            }
        }
    }

    printf("%d", ans);

    return 0;
}