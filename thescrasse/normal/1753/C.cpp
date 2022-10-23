#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll fxp(ll b, ll e) {
    ll r = 1, k = b;
    while (e != 0) {
        if (e % 2) r = (r * k) % mod;
        k = (k * k) % mod; e /= 2;
    }
    return r;
}

ll inv(ll x) {
    return fxp(x, mod - 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> v(n + 1, 0);
        ll a = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> v[i]; a += v[i];
        }
        ll b = n - a;

        ll x = 0;
        for (ll i = n - a + 1; i <= n; i++) x += v[i];

        ll res = 0;
        ll ab2 = (((a + b) * (a + b - 1)) / 2) % mod;
        for (ll i = x; i < a; i++) {
            ll ax = inv(a - i);
            ll ax2 = (ax * ax) % mod;
            res += (ab2 * ax2) % mod;
            res %= mod;

            // cout << "res =" _ res << nl;
        }

        cout << res << nl;
    }

    return 0;
}