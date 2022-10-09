#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll fc[maxn], nv[maxn];

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

ll bnm(ll a, ll b) {
    if (a < b || b < 0) return 0;
    ll r = (fc[a] * nv[b]) % mod;
    r = (r * nv[a - b]) % mod;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    fc[0] = 1; nv[0] = 1;
    for (ll i = 1; i < maxn; i++) {
        fc[i] = (i * fc[i - 1]) % mod; nv[i] = inv(fc[i]);
    }

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n + 2, 0);
        for (ll i = 1; i <= n; i++) cin >> a[i];
        vector<ll> ps = a, ss = a;
        for (ll i = 1; i <= n; i++) ps[i] += ps[i - 1];
        for (ll i = n; i >= 1; i--) ss[i] += ss[i + 1];

        ll ans = 1;
        map<ll, ll> freq_ps, freq_ss;
        ll curr_ways = 1;
        for (ll i = 1; i <= n; i++) freq_ps[ps[i]]++;

        for (ll i = n; i >= 1; i--) {
            if (i != n) {
                ll a = freq_ps[ss[i + 1]];
                ll b = freq_ss[ss[i + 1]];
                if (a != 0) curr_ways = (curr_ways * inv(bnm(a + b - 1, b))) % mod;
                if (a != 0 && ss[i] != ss[i + 1]) {
                    curr_ways = (curr_ways * (bnm(a + b, b))) % mod;
                }
            }

            freq_ps[ps[i]]--; freq_ss[ss[i]]++;
            ll a = freq_ps[ss[i]];
            ll b = freq_ss[ss[i]];
            if (a != 0) curr_ways = (curr_ways * bnm(a + b - 1, b)) % mod;
            if (a != 0) ans = (ans + curr_ways) % mod;
            // cout << "i, curr_ways =" _ i _ curr_ways * (a != 0) << nl;
        }

        cout << ans << nl;
    }

    return 0;
}