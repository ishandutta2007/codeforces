#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9 + 7;
ll p, k;

ll mult(ll x, ll y, ll mod)
{
    return (x * y) % mod;
}
ll bin_pow(ll x, ll q, ll mod)
{
    if (q == 0) return 1 % mod;
    if (q == 2) return mult(x, x, mod);
    if (q & 1) return mult(x, bin_pow(x, q - 1, mod), mod);
    return bin_pow(bin_pow(x, q / 2, mod), 2, mod);
}

int main()
{
    cin >> p >> k;

    if (k == 0)
    {
        cout << bin_pow(p, p - 1, MOD) << endl;
        return 0;
    }
    if (k == 1)
    {
        cout << bin_pow(p, p, MOD) << endl;
        return 0;
    }
    ll d = p - 1;
    for (ll x = 2; x * x <= d; x++)
    {
        if (bin_pow(k, x, p) == 1)
        {
            cout << bin_pow(p, (p - 1) / x, MOD) << endl;
            return 0;
        }
        while(d % x == 0)
        {
            ll t = d / x;
            if (bin_pow(k, t, p) == 1)
                d /= x;
            else
                break;
        }
    }
    cout << bin_pow(p, (p - 1) / d, MOD) << endl;

    return 0;
}