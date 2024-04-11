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

const ll N = 210000;

ll n, k, a, b;

ll mas[N];

ll solve (ll l, ll r){
    ll mid = (l + r) / 2;
    ll p = 0, q = 0;
    for (ll i = 19; i >= 0; i--){
        if (p + (1 << i) > k)
            continue;
        if (mas[p + (1 << i)] < l)
            p += (1 << i);
    }
    for (ll i = 19; i >= 0; i--){
        if (q + (1 << i) > k)
            continue;
        if (mas[q + (1 << i)] <= r)
            q += (1 << i);
    }
    // (p + 1, q)
    if (p == q)
        return a;
    ll x = (r - l + 1) * (q - p) * b;
    if (l == r)
        return x;
    ll y = solve (l, mid) + solve (mid + 1, r);
    return min (x, y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> a >> b;
    n = (1 << n);
    for (ll i = 1; i <= k; i++)
        cin >> mas[i];
    sort (mas + 1, mas + k + 1);
    cout << solve (1, n) << endl;
    return 0;
}