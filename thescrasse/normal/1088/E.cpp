// 1373F
// Network Coverage

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, w[maxn], dp[maxn], mx;
bool visited[maxn];
vector<ll> adj[maxn];

void dfs(ll s) {
    dp[s] = w[s];
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        dfs(u);
        if (dp[u] > 0) dp[s] += dp[u];
    }
    if (dp[s] == mx) {
        dp[s] = 0; res++;
    }
}

void init(ll s) {
    for (i = 1; i <= n; i++) visited[i] = false;
    visited[s] = true; dfs(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; mx = -INF;
    for (i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    res = 0; init(1);
    for (i = 1; i <= n; i++) mx = max(mx, dp[i]);
    init(1);

    /* for (i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << nl; */

    cout << mx * res << ' ' << res << nl;

    return 0;
}