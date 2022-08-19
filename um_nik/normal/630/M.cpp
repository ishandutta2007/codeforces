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
    x %= 360;
    if (x < -45) x += 360;
    if (x >= 315) x -= 360;
    x += 44;
    cout << x / 90 << endl;
    
    return 0;
}