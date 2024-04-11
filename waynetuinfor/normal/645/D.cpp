#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
pair<int, int> e[maxn];
int n, dp[maxn];
vector<vector<int>> G;
bool v[maxn];

void dfs(int now) {
    if (v[now]) return;
    v[now] = true;
    for (int u : G[now]) {
        dfs(u);
        dp[now] = max(dp[now], dp[u] + 1);
    }
}

bool check(int t) {
    G = vector<vector<int>>(maxn);
    memset(dp, 0, sizeof(dp));
    memset(v, false, sizeof(v));
    for (int i = 0; i < t; ++i) {
        G[e[i].second].push_back(e[i].first);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        dfs(i);
        ans = max(ans, dp[i]);
    }
    return ans >= n - 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m; cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> e[i].first >> e[i].second;
    int d = 1, ans = m + 1; while (d <= m) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << (ans == m + 1 ? -1 : ans) << endl;
    return 0;
}