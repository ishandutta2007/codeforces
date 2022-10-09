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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll bsl, bsm, bsu, dp[maxn], ps[maxn][17];
string s;

ll rs(ll l, ll r, ll c) {
    return (ps[r][c] - ps[l - 1][c]);
}

bool solve(ll x) {
    ll i, j, mk, rm;
    vector<ll> adj[17];

    for (i = 1; i <= n - x + 1; i++) {
        for (j = 0; j < k; j++) {
            if (rs(i, i + x - 1, j) == x) adj[j].pb(i);
        }
    }

    for (i = 0; i < (1 << k); i++) dp[i] = INF;
    dp[0] = -INF;

    for (mk = 1; mk < (1 << k); mk++) {
        for (i = 0; i < k; i++) {
            if (((mk >> i) & 1) == 0) continue;
            rm = mk ^ (1 << i);
            auto it = lower_bound(adj[i].begin(), adj[i].end(), dp[rm] + x);
            if (it != adj[i].end()) dp[mk] = min(dp[mk], (*it));
        }
    }

    if (dp[(1 << k) - 1] == INF) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k >> s; s = '#' + s;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < k; j++) {
            ps[i][j] = ps[i - 1][j];
            if (((ll)s[i] - 'a') == j || s[i] == '?') ps[i][j]++;
        }
    }

    bsl = 0; bsu = n;
    while (bsl != bsu) {
        bsm = (bsl + bsu + 1) / 2;
        if (solve(bsm)) bsl = bsm;
        else bsu = bsm - 1;
    }

    cout << bsl << nl;

    return 0;
}