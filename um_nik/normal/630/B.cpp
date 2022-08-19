#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

ll getC(ll n, int k)
{
    if (k > n) return 0;
    ll res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

ll pw(ll x, ll p)
{
    if (p < 0) return 0;
    ll r = 1;
    while(p--)
        r *= x;
    return r;
}

double bin_pow(double x, int p)
{
    if (p == 0) return 1;
    if (p == 2) return x * x;
    if (p & 1) return x * bin_pow(x, p - 1);
    return bin_pow(bin_pow(x, p / 2), 2);
}

int main()
{
    double n;
    int p;
    cin >> n >> p;
    double ans = n * bin_pow(1.000000011, p);
    printf("%.15lf\n", ans);
    
    return 0;
}