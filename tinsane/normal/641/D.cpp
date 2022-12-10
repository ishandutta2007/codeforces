#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

typedef long double ldouble;
const int N = 100500;
const ldouble EPS = 1e-9;

ldouble eq(ldouble a, ldouble b)
{
    return abs(a - b) < EPS;
}

ldouble my_sqrt(ldouble a)
{
    if (a < 0)
        a = 0;
    return sqrtl(a);
}

ldouble scan_ldouble()
{
    double x;
    scanf("%lf", &x);
    return x;
}

int n;
ldouble x[N], y[N];
ldouble fa[N], fb[N];
ldouble Fa[N], Fb[N];
ldouble sumF[N];
ldouble prodF[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        x[i] = scan_ldouble();
    for (int i = 1; i <= n; i++)
        y[i] = scan_ldouble();

    for (int i = 1; i <= n; i++)
    {
        sumF[i] = sumF[i - 1] + x[i] + y[i];
        prodF[i] = x[i] + prodF[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        ldouble A = sumF[i];
        ldouble B = prodF[i];
        ldouble D = my_sqrt(A * A - 4 * B);
        ldouble x1 = (A + D) / 2;
        ldouble x2 = (A - D) / 2;

        fa[i] = x1 - Fa[i - 1];
        fb[i] = x2 - Fb[i - 1];
        Fa[i] = x1;
        Fb[i] = x2;
        ldouble val = fa[i] * Fb[i - 1] + fb[i] * Fa[i - 1] + fa[i] * fb[i];
        if (!eq(val, x[i]))
        {
            fa[i] = x2 - Fa[i - 1];
            fb[i] = x1 - Fb[i - 1];
            swap(Fa[i], Fb[i]);
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%.10lf ", (double)fa[i]);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%.10lf ", (double)fb[i]);
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    return 0;
}