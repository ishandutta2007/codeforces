#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

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
        return Point(x - a.x, y - a.y);
    }
    Point operator * (double k) const
    {
        return Point(x * k, y * k);
    }
    double len()
    {
        return sqrt(x * x + y * y);
    }

    void scan()
    {
        scanf("%lf%lf", &x, &y);
    }
};

const int IT = 1000;
Point A, B, v, w;
double vw;
double l = 0, r = 1e12;
double t;

bool check(double x)
{
    if (x < t)
    {
        Point X = A - v * x;
        return X.len() / vw < x;
    }
    else
    {
        Point X = A - v * t - w * (x - t);
        return X.len() / vw < x;
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    A.scan();
    B.scan();
    A = B - A;
    scanf("%lf%lf", &vw, &t);
    v.scan();
    w.scan();

    for (int it = 0; it < IT; it++)
    {
        double x = (l + r) / 2;
        if (check(x))
            r = x;
        else
            l = x;
    }
    printf("%.14lf\n", l);

    return 0;
}