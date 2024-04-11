#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dat;
vector<pair<int,int>> hull;

using Point = pair<int, int>;
#define x first
#define y second

inline long long outer(Point a, Point b) {
    return a.x * 1ll * b.y - a.y * 1ll * b.x;
}

Point operator+(Point a, Point b)
{
    return {a.x+b.x, a.y+b.y};
}

Point operator-(Point a, Point b)
{
    return {a.x-b.x, a.y-b.y};
}

inline int ccw(const Point& a, const Point& b, const Point& c) {
    auto ret = outer(b - a, c - a);
    if (ret > 0) return 1;
    if (ret < 0) return -1;
    return 0;
}

// find convex hull
// O(n*logn)
vector<Point> convex_hull(vector<Point>& dat) {
    if (dat.size() <= 3) return dat;
    vector<Point> upper, lower;
    sort(dat.begin(), dat.end(), [](const Point& a, const Point& b) {
            return (a.x == b.x) ? a.y < b.y : a.x < b.x;
            });
    for (const auto& p : dat) {
        while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), p) >= 0) upper.pop_back();
        while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), p) <= 0) lower.pop_back();
        upper.emplace_back(p);
        lower.emplace_back(p);
    }
    upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
    return upper;
}

long long area2(Point p1, Point p2, Point p3)
{
    return abs(p1.x * 1ll * p2.y + p2.x * 1ll * p3.y + p3.x * 1ll * p1.y - (
        p1.y * 1ll * p2.x + p2.y * 1ll * p3.x + p3.y * 1ll * p1.x));
}

tuple<Point,Point,Point> mex;
long long marea = -1;

void update(int a, int b, int c)
{
    long long res = area2(hull[a], hull[b], hull[c]);
    if (res > marea)
    {
        marea = res;
        mex = make_tuple(hull[a], hull[b], hull[c]);
    }
}

int main()
{
    int n; long long s;
    scanf("%d%lld",&n,&s);
    dat.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&dat[i].x,&dat[i].y);
    }

    hull = convex_hull(dat);

    n = hull.size();
    for (int i = 0; i < n; i++) hull.push_back(hull[i]);

    for (int i = 0; i < n; i++)
    {
        int k1 = i; int k2 = i + 1;
        for (int j = i + 1; j < i + n; j++)
        {
            while (area2(hull[i], hull[k1], hull[j]) < area2(hull[i], hull[k1 + 1], hull[j])) k1++;
            while (area2(hull[i], hull[k2], hull[j]) < area2(hull[i], hull[k2 + 1], hull[j])) k2++;

            update(i, j, k1);
            update(i, j, k2);
        }
    }


    Point p1, p2, p3;
    tie(p1, p2, p3) = mex;

    Point a1, a2, a3;
    a1 = p1 + p2 - p3;
    a2 = p1 - p2 + p3;
    a3 = p2 + p3 - p1;

    printf("%d %d\n%d %d\n%d %d\n", a1.x, a1.y, a2.x, a2.y, a3.x, a3.y);
}