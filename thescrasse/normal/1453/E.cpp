// 1453E
// Dog Snacks

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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dp[maxn], bsl, bsm, bsu;
vector<ll> adj[maxn];
bool visited[maxn];

void dfs(ll s, ll k) {
    ll mn, mx1, mx2;
    mn = INF; mx1 = -INF; mx2 = -INF;
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        dfs(u, k);
        mn = min(mn, dp[u]);
        if (dp[u] >= mx1) {
            mx2 = mx1; mx1 = dp[u];
        } else if (dp[u] >= mx2) {
            mx2 = dp[u];
        }
    }

    if (mn == INF) dp[s] = 0;
    else if (mx1 >= k || mx2 >= k - 1) flag[0] = 0;
    else if (mx1 == k - 1) dp[s] = k;
    else dp[s] = mn + 1;

    // cout << k _ s _ mn _ mx1 _ mx2 _ dp[s] << nl;
}

void init(ll s, ll k) {
    for (i = 1; i <= n; i++) {
        visited[i] = false; dp[i] = 0;
    }
    visited[s] = true; dfs(s, k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 1; i <= n; i++) adj[i].clear();
        for (i = 0; i < n - 1; i++) {
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }

        bsl = 0; bsu = 1000000;
        while (bsl != bsu) {
            bsm = (bsl + bsu) / 2; flag[0] = 1;
            init(1, bsm);
            if (flag[0] == 1) bsu = bsm;
            else bsl = bsm + 1;
        }

        cout << bsl << nl;
    }

    return 0;
}