#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

const double sqrtC = sqrt(2.);

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    double ans = 0;
    double m;
    double r;
    scanf("%lf%lf", &m, &r);
    for (int i = 0; i < m; i++)
    {
        double cl, cr;          
        cl = i;
        cr = m - i - 1;
        ans += 2 * r / (m * m);
        if (cl > 0)
            ans += (2 * r + sqrtC * r) / (m * m);
        if (cr > 0)
            ans += (2 * r + sqrtC * r) / (m * m);
        if (cl > 1)
            ans += (r * (cl - 1) * (cl) + r * (cl - 1) * sqrtC * 2.) / (m * m);
        if (cr > 1)
            ans += (r * (cr - 1) * (cr) + r * (cr - 1) * sqrtC * 2.) / (m * m);
    }

    printf("%.7lf", ans);

    return 0;
}