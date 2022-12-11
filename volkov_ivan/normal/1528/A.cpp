#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int dp[N][2];
int l[N], r[N];
vector <int> g[N];

void init(int n) {
    for (int i = 1; i <= n; i++)
        g[i].clear();
}

void dfs(int v, int par = -1) {
    vector <int> childs;
    for (int u : g[v]) {
        if (u == par)
            continue;
        dfs(u, v);
        childs.push_back(u);
    }
    dp[v][0] = dp[v][1] = 0;
    if (childs.empty()) {
        return;
    }
    for (int u : childs) {
        dp[v][0] += max(abs(l[u] - l[v]) + dp[u][0], abs(r[u] - l[v]) + dp[u][1]);
        dp[v][1] += max(abs(l[u] - r[v]) + dp[u][0], abs(r[u] - r[v]) + dp[u][1]);
    }
}

void solve() {
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}