#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-9;
bool eq(double x, double y)
{
    return fabs(x - y) < eps;
}
bool ls(double x, double y)
{
    return x < y && !eq(x, y);
}
bool lseq(double x, double y)
{
    return x < y || eq(x, y);
}

struct Point
{
    double x, y;

    Point() : x(), y() {}
    Point (double _x, double _y) : x(_x), y(_y) {}

    Point operator + (const Point &a) const
    {
        return Point(x + a.x, y + a.y);
    }
    Point operator - (const Point &a) const
    {
        return Point (x - a.x, y - a.y);
    }
    Point operator * (const double &k) const
    {
        return Point(x * k, y * k);
    }
    Point operator / (const double &k) const
    {
        return Point(x / k, y / k);
    }
    double operator % (const Point &a) const
    {
        return x * a.x + y * a.y;
    }
    double operator * (const Point &a) const
    {
        return x * a.y - y * a.x;
    }
    double sqrLen() const
    {
        return *this % *this;
    }
    double len() const
    {
        return sqrt(sqrLen());
    }
    double distTo(const Point &a) const
    {
        return (*this - a).len();
    }

    Point norm() const
    {
        return *this / len();
    }

    void scan()
    {
        scanf("%lf%lf", &x, &y);
    }

    bool operator == (const Point &a) const
    {
        return eq(x, a.x) && eq(y, a.y);
    }
    bool operator < (const Point &a) const
    {
        if (!eq(x, a.x)) return x < a.x;
        return ls(y, a.y);
    }
};

bool cmp(const Point &a, const Point &b)
{
    double x = a * b;
    if (!eq(x, 0)) return x > 0;
    return a.sqrLen() < b.sqrLen();
}

const int N = 100100;
int n;
Point a[N];
Point P;

void graham()
{
    sort(a, a + n, cmp);
    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while(m > 1 && lseq(0, (a[i] - a[m - 1]) * (a[m - 1] - a[m - 2])))
            m--;
        a[m++] = a[i];
    }
    n = m;
}

bool intersectLines(Point A, Point a, Point B, Point b, Point &M)
{
    if (eq(a * b, 0))
        return false;

    double y = ((A - B) * a) / (b * a);
    M = B + b * y;

    return true;
}

int main()
{
    scanf("%d", &n);
    P.scan();
    for (int i = 0; i < n; i++)
        a[i].scan();
    double x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        x = max(x, a[i].x);
        y = max(y, a[i].y);
    }
    a[n++] = Point(x, 0);
    a[n++] = Point(0, y);

    graham();

    for (int i = 0; i < n - 1; i++)
    {
        if (lseq(0, a[i] * P) && lseq(0, P * a[i + 1]))
        {
            Point M;
            if (!intersectLines(a[i], (a[i + 1] - a[i]).norm(), Point(), P, M))
                throw;
            printf("%.13lf\n", P.len() / M.len());
            return 0;
        }
    }
    throw;

    return 0;
}