#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

const ll N = 1e6 + 5;

ll n, k;
ll a, b;

ll x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> a >> b;
    ll s = a + 1;
    x = 1, y = n * k;
    for (ll i = -2; i < n; i++){
        ll t = i * k + b + 1;
        if (t <= 0 || t > n * k)
            continue;
        ll m = abs (t - s);
        m = n * k / __gcd (m, n * k);
        x = max (x, m);
        y = min (y, m);
    }
    b = (k - 1 + k - b) % k + 1;
    for (ll i = -2; i < n; i++){
        ll t = i * k + b + 1;
        if (t <= 0 || t > n * k)
            continue;
        ll m = abs (t - s);
        m = n * k / __gcd (m, n * k);
        x = max (x, m);
        y = min (y, m);
    }
    cout << y << " " << x << endl;
    return 0;
}