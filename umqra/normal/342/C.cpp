#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

bool Eq(double a, double b)
{
    return fabs(a - b) < 1e-8;
}

bool LsEq(double a, double b)
{
    return a < b || Eq(a, b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int ans = 0;
    double r, h;
    scanf("%lf%lf", &r, &h);

    double curF = 0;
    while (1)
    {               
        double t = curF + (r / 2.);
        if (LsEq(t, h))
        {                       
            ans += 2;
            curF += r;
        }
        else
            break;
    }

    curF -= r;
    double d = r / 2. + sqrt(3.) / 2. * r;
    d -= (h - curF);           
    if (LsEq(d + r / 2., r))
        ans++;  
    printf("%d", ans);
    return 0;
}