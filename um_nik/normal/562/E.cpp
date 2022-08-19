#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second 
#define mp make_pair

struct Point
{
    ll x, y;

    Point() : x(), y() {}
    Point(ll _x, ll _y) : x(_x), y(_y) {}

    void scan()
    {
        scanf("%lld%lld", &x, &y);
    }
    void eprint()
    {
        eprintf("%lld %lld\n", x, y);
    }

    Point operator + (Point a)
    {
        return Point(x + a.x, y + a.y);
    }
    Point operator - (const Point &a) const
    {
        return Point(x - a.x, y - a.y);
    }
    ll operator % (Point a)
    {
        return x * a.x + y * a.y;
    }
    ll operator * (Point a)
    {
        return x * a.y - y * a.x;
    }
    ll sqLen()
    {
        return *this % *this;
    }

    bool operator < (const Point &a) const
    {
        if (y != a.y) return y < a.y;
        return x < a.x;
    }
};

const int N = (int)1e5 + 100;
int n, m;
Point a[N], b[N], c[N];
Point minP;

bool cmp(const Point &A, const Point &B)
{
    Point v = A - minP;
    Point u = B - minP;
    ll x = v * u;
    if (x != 0) return x > 0;
    return v.sqLen() < u.sqLen();
}

void graham()
{
    minP = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < minP)
            minP = a[i];
    sort(a, a + n, cmp);
    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        while(sz > 1 && (a[i] - c[sz - 2]) * (a[i] - c[sz - 1]) <= 0)
            sz--;
        c[sz++] = a[i];
    }
    n = sz;
    for (int i = 0; i < n; i++)
        a[i] = c[i];
    return;
}

ll sgn(ll a)
{
    if (a < 0)
        return -1;
    if (a == 0)
        return 0;
    return 1;
}

bool intersectSegm(Point A, Point B, Point C, Point D)
{
    return sgn((B - A) * (C - A)) != sgn((B - A) * (D - A)) &&
           sgn((D - C) * (A - C)) != sgn((D - C) * (B - C));
}

int main()
{
#ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    scanf("%d%d", &m, &n);
    a[0].scan();
    for (int i = 0; i < m; i++)
        b[i].scan();
    for (int i = 0; i < n; i++)
        a[i].scan();
    a[n] = a[n + 1] = Point(0, 0);
    for (int i = 0; i < n; i++)
    {
        a[n].x = max(a[n].x, a[i].x);
        a[n + 1].y = max(a[n + 1].y, a[i].y);
    }
    n += 2;
    graham();

    minP = Point(0, 0);
    sort(b, b + m, cmp);

    int idx = 0;

    for (int i = 0; i < m; i++)
    {
        while (a[idx + 1] * b[i] > 0) idx++;
        if (intersectSegm(Point(0, 0), b[i], a[idx], a[idx + 1]))
        {
            printf("Max\n");
            return 0;
        }
    }
    printf("Min\n");

    return 0;
}