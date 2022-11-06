#include <bits/stdc++.h>
#define int double
using namespace std;

const signed maxn = 300 + 5;

struct Point {
    int x, y;
    Point operator-(const Point& p) const {
        return (Point){ x - p.x, y - p.y };
    }
    int operator*(const Point& p) const {
        return x * p.y - y * p.x;
    }
} h, u;

struct Line {
    int a, b, c;
} l[maxn];

int n;

pair<Point, Point> f(signed);

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> h.x >> h.y >> u.x >> u.y;
    cin >> n;
    for (signed i = 0; i < n; ++i) cin >> l[i].a >> l[i].b >> l[i].c;
    Point vec = u - h;
    int ans = 0;
    for (signed i = 0; i < n; ++i) {
        int a = l[i].a, b = l[i].b, c = l[i].c;
        Point p1, p2;
        tie(p1, p2) = f(i);
        if (((p1 - u) * (p1 - p2)) * ((p1 - h) * (p1 - p2)) < 0) ++ans;
    }
    cout << ans << '\n';
    return 0;
}

pair<Point, Point> f(signed ind) {
    int a = l[ind].a, b = l[ind].b, c = l[ind].c;
    pair<Point, Point> ret;
#define INF 1000000
    if (b == 0) return make_pair((Point){ -c / a, -INF }, (Point){ -c / a, INF });
    return make_pair((Point){ -INF, -(a * -INF + c) / b }, (Point){ INF, -(a * INF + c) / b });
#undef INF
}