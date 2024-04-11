#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#ifdef UMQRA
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
    #define getTime() fprintf(stderr, "Running time:%.3lf seconds\n", (double)(clock()) / CLOCKS_PER_SEC)
#else
    #define eprintf(...)
    #define getTime()
#endif
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

const ll mod = (ll)1e9 + 9;
ll add(ll a, ll b)
{
    if (a + b < 0)
        return a + b + mod;
    if (a + b >= mod)
        return a + b - mod;
    return a + b;
}

ll mult(ll a, ll b)
{
    return (a * b) % mod;
}

ll myPow(ll a, ll k)
{
    if (k == 0)
        return (ll)1;
    if (k & (ll)1)
        return mult(myPow(a, k - 1), a);
    else
    {
        ll t = myPow(a, k / 2);
        return mult(t, t);
    }
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    ll k, n, m;
    cin >> n >> m >> k;
    ll l1 = -1, r1 = (ll)1e9;
    while (r1 - l1 > 1)
    {
        ll m1 = (l1 + r1) / 2;    
        ll newS = m - m1 * k;
        ll newL = n - m1 * k;
        if (newS < 0 || newL <= 0)
            r1 = m1;
        else
        {                  
            ll tt = newL / k;         
            if (newL - tt >= newS)
                r1 = m1;
            else
                l1 = m1;
        }
    }
                       
    ll ans = mult(add(myPow(2, r1 + 1), -2), k);
    ans = add(ans, m - k * r1);
    cout << ans;
    return 0;
}