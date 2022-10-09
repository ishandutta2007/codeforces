#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 50010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll fc;
vector<ll> d[maxn];

ll fxp(ll b, ll e) {
    ll r;
    if (e == 0) return 1;
    if (e % 2) {
        r = fxp(b, e - 1); return (b * r) % mod;
    } else {
        r = fxp(b, e / 2); return (r * r) % mod;
    }
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

    cin >> n >> m;
    for (j = 1; j <= m; j++) d[j].pb(0);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> a; d[j].pb(a);
        }
    }
    for (j = 1; j <= m; j++) sort(d[j].begin(), d[j].end());

    fc = 1;
    for (i = 1; i <= n; i++) fc = (i * fc) % mod;
    for (i = 1; i <= m; i++) {
        k = 1;
        for (j = 1; j <= n; j++) {
            k *= max((ll)0, d[i][j] - j); k %= mod;
        }
        // cout << "i, k = " << i _ k << nl;
        res += (fc - k + mod); res %= mod;
    }

    res *= inv(fc); res %= mod;

    cout << res << nl;

    return 0;
}