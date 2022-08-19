#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
using namespace std;


#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

const double PI = 4 * atan(1.);
const int IT = 200;

int n;
double R, v;

double solve()
{
    double w = v / R;
    double l, r;
    scanf("%lf%lf", &l, &r);
    double L = r - l;
    int z = (int)(L / (2 * PI * R));
    L -= z * (2 * PI * R);
    L /= 2;
    l = 0, r = PI * R / v;
    for (int it = 0; it < IT; it++)
    {
        double t = (l + r) / 2;
        double dL = R * (PI - w * t + sin(w * t));
        if (dL > L)
            l = t;
        else
            r = t;
    }
    double t1 = l;
    double t2 = 2 * PI * R / v - t1;
    double LL = v * (t2 - t1);
    return (LL + z * 2 * PI * R) / v;
}

int main()
{
#ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    freopen ("err.txt", "w", stderr);
#endif

    scanf("%d%lf%lf", &n, &R, &v);

    while(n--)
        printf("%.12lf\n", solve());

    return 0;
}