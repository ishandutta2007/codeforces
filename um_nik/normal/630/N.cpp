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

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double D = b * b - 4 * a * c;
    D = sqrt(D);
    double x1 = (-b + D) / (2 * a), x2 = (-b - D) / (2 * a);
    if (x1 < x2) swap(x1, x2);
    printf("%.13lf\n%.13lf\n", x1, x2);
    
    return 0;
}