#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        deg[x]++;
        deg[y]++;
    }
    vector dp(n, vector<pair<int, int>>(2));
    vector<int> ans(n, 1);
    function<void(int, int)> dfs = [&](int v, int p) {
        dp[v][1].first = -1;
        dp[v][1].second = deg[v];
        dp[v][0].second = 1;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs(to, v);
            dp[v][1].first += dp[to][0].first;
            dp[v][1].second += dp[to][0].second;
            dp[v][0].first += dp[to][1].first;
            dp[v][0].second += dp[to][1].second;
        }
        dp[v][1] = min(dp[v][1], dp[v][0]);
    };
    dfs(0, -1);
    function<void(int, int, int)> dfs2 = [&](int v, int p, int k) {
        int me = 0;
        if (k == 0) {
            if (dp[v][0] != dp[v][1]) {
                me = 1;
                ans[v] = (int) g[v].size();
            }
        }
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs2(to, v, me);
        }
    };
    dfs2(0, -1, 0);
    if (n == 2) {
        dp[0][1].first = -2;
    }
    cout << -dp[0][1].first << " " << dp[0][1].second << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}