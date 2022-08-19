#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
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

    void scan()
    {
        scanf("%lf%lf", &x, &y);
    }

    Point operator + (const Point &a) const
    {
        return Point(x + a.x, y + a.y);
    }
    Point operator - (const Point &a) const
    {
        return Point(x - a.x, y - a.y);
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
};

const int N = 100100;
const double INF = 1e9;
const double PI = 4 * atan(1.);
int n;
Point a[N];
Point P;
double R1 = INF, R2 = 0;

Point getH(Point O, Point A, Point a)
{
    a = a.norm();
    return A + a * ((O - A) % a);
}

bool onSegm(Point A, Point B, Point C)
{
    return lseq((A - B) % (C - B), 0);
}

double distToSegm(Point P, Point A, Point B)
{
    Point H = getH(P, A, B - A);
    if (onSegm(A, H, B)) return H.distTo(P);
    return min(P.distTo(A), P.distTo(B));
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    P.scan();
    for (int i = 0; i < n; i++)
        a[i].scan();
    for (int i = 0; i < n; i++)
        R2 = max(R2, a[i].distTo(P));
    for (int i = 0; i < n; i++)
        R1 = min(R1, distToSegm(P, a[i], a[(i + 1) % n]));
    printf("%.10lf\n", PI * (R2 * R2 - R1 * R1));

    return 0;
}