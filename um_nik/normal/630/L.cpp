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
    ll x;
    cin >> x;
    ll a[10];
    for (int i = 0; i < 5; i++)
    {
        a[i] = x % 10;
        x /= 10;
    }
    for (int i = 4; i >= 0; i -= 2)
        x = 10 * x + a[i];
    for (int i = 1; i < 4; i += 2)
        x = 10 * x + a[i];
//    cout << x << endl;
    ll y = 1;
    for (int i = 0; i < 5; i++)
        y = (y * x) % (100000);
    printf("%05lld\n", y);
    
    return 0;
}