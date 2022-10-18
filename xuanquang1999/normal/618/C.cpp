#include <bits/stdc++.h>
#define double long double

using namespace std;

const double EPS = 1e-18;
const int maxN = 100005;

bool isEqual(double a, double b) {
    return fabs(a-b) < EPS;
}

struct point {
    double x, y, angle;
    int id;
    point() {x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y) {};
    bool inline operator < (const point &b) const {
        return (y < b.y || (isEqual(y, b.y) && x < b.x));
    }
};

double dist(point p1, point p2) {
    return hypot(p1.x-p2.x, p1.y-p2.y);
}

int n;
point p[maxN];

bool cmp(point a, point b) {
    return (a.angle < b.angle || (isEqual(a.angle, b.angle) && dist(a, p[0]) < dist(b, p[0])));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i+1;
    }

    int pivot = 0;
    for(int i = 1; i < n; ++i) {
        if (p[i] < p[pivot]) pivot = i;
    }
    swap(p[0], p[pivot]);
    for(int i = 1; i < n; ++i) p[i].angle = atan2(p[i].y-p[0].y, p[i].x-p[0].x);
    sort(p+1, p+n, cmp);

    for(int i = 2; i < n; ++i) {
        if (!isEqual(p[i].angle, p[1].angle)) {
            printf("%d %d %d\n", p[0].id, p[1].id, p[i].id);
            return 0;
        }
    }

    return 0;
}