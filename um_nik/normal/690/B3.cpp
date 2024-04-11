#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

typedef long long ll;

struct Point
{
    ll x, y;
    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
    void read()
    {
        scanf("%lld%lld", &x, &y);
    }
    Point operator- (const Point& p) const
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator+ (const Point& p) const
    {
        return Point(x + p.x, y + p.y);
    }
    ll operator* (const Point& p) const
    {
        return x * p.y - y * p.x;
    }
    void print()
    {
        printf("%lld %lld\n", x, y);
    }
    ll len2() const
    {
        return x * x + y * y;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const ll INF = 1e9 + 10;
int n, m;
int min_x[N], max_x[N];
Point cells[M];
Point delta[] = { Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1) };
vector<Point> pts, hull;

bool in_seg(int l, int r, int x)
{
    return l <= x && x <= r;
}

void add_vertex(Point p)
{
    if (in_seg(min_x[p.y - 1], max_x[p.y - 1], p.x - 1) &&
            in_seg(min_x[p.y], max_x[p.y], p.x - 1) &&
            in_seg(min_x[p.y - 1], max_x[p.y - 1], p.x) &&
            in_seg(min_x[p.y], max_x[p.y], p.x))
        pts.push_back(p);
}

bool solve()
{
    scanf("%d%d", &n, &m);
    if (n == 0)
        return false;

    for(int i = 0; i < m; ++i)
    {
        cells[i].read();
        cells[i] = cells[i] - Point(1, 1);
        min_x[cells[i].y] = INF;
        max_x[cells[i].y] = -INF;
        min_x[cells[i].y - 1] = INF;
        max_x[cells[i].y - 1] = -INF;
        min_x[cells[i].y + 1] = INF;
        max_x[cells[i].y + 1] = -INF;
    }
    for(int i = 0; i < m; ++i)
    {
        int y = cells[i].y;
        min_x[y] = min(min_x[y], (int)cells[i].x);
        max_x[y] = max(max_x[y], (int)cells[i].x);
    }

    pts.clear();
    hull.clear();

    for(int i = 0; i < m; ++i)
        for(auto& d : delta)
            add_vertex(cells[i] + d);

    auto O = pts[0];
    for(auto& p : pts)
        p = p - O;
    sort(pts.begin() + 1, pts.end(), [] (const Point& f, const Point& s) { return f * s == 0 ? f.len2() < s.len2() : f * s > 0; });
    pts.emplace_back();
    for(auto p : pts)
    {
        for(; hull.size() > 1 && (hull.back() - hull[hull.size() - 2]) * (p - hull[hull.size() - 2]) <= 0; hull.pop_back());
        hull.push_back(p);
    }
    hull.pop_back();
    reverse(hull.begin() + 1, hull.end());
    printf("%d\n", (int)hull.size());
    for(auto p : hull)
        (O + p).print();

    return true;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    while(solve());

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}