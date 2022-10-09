#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1996488706
#define hmod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll x[maxn], y[maxn], s[maxn], dp[maxn][2], c[maxn];
vector<array<ll, 2>> v;
vector<ll> adj[maxn];

void fx(ll &x, ll p) {
    if ((x + p) % 2) x = (x + hmod) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> s[i];
        v.pb({x[i], i});
    }
    x[n + 1] = x[n] + 1;

    for (i = 1; i <= n; i++) {
        array<ll, 2> o = {y[i], -INF};
        auto it = lower_bound(v.begin(), v.end(), o);
        c[i] = (*it)[0] - y[i]; y[i] = (*it)[1];
        adj[y[i]].pb(i);
    }

    dp[n][0] = s[n] + 1; dp[n][1] = s[n];
    for (i = n - 1; i >= 1; i--) {
        dp[i][0] = (2 * dp[i + 1][0]) % mod;
        for (auto u : adj[i + 1]) dp[i][0] = (dp[i][0] - 2 * dp[u][1] + 2 * (ll)mod) % mod;
        dp[i][0] = (dp[i][0] - (s[i] ^ 1) + mod) % mod;
        fx(dp[i][0], s[i] ^ 1);
        dp[i][1] = dp[i][0] / 2;
    }

    /* for (i = 1; i <= n; i++) {
        cout << x[i + 1] - x[i] _ c[i] _ dp[i][0] _ dp[i][1] << nl;
    } */

    res = x[1] % mod;
    for (i = 1; i <= n; i++) {
        res += (dp[i][1] * c[i]); res %= mod;
        res += ((dp[i][0] - dp[i][1] + mod) * (x[i + 1] - x[i])) % mod;
    }

    res %= hmod;
    cout << res << nl;

    return 0;
}