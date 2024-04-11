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
ll dp[maxn], nc[maxn], l[maxn], r[maxn];
vector<ll> adj[maxn];

void dfs(ll s) {
    for (auto u : adj[s]) {
        dfs(u); dp[s] += dp[u]; nc[s] += nc[u];
    }
    dp[s] = min(dp[s], r[s]);
    if (dp[s] < l[s]) dp[s] = r[s], nc[s]++;
}

void rst() {
    ll i;
    for (i = 1; i <= n; i++) adj[i].clear(), dp[i] = 0, nc[i] = 0;
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
        cin >> n; rst();
        for (i = 2; i <= n; i++) {
            cin >> a; adj[a].pb(i);
        }
        for (i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
        }

        dfs(1);

        cout << nc[1] << nl;
    }

    return 0;
}