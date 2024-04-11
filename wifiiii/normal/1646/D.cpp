#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    if(n == 2) {
        cout << 2 << ' ' << 2 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return 0;
    }
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<vector<int>> dp(n, vector<int>(2)), dp2(n, vector<int>(2));
    function<void(int, int)> dfs = [&](int u, int fa) {
        dp[u][0] = 0, dp[u][1] = 1;
        dp2[u][0] = 0, dp2[u][1] = deg[u];
        for(int v : g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            dp[u][1] += dp[v][0];
            dp2[u][1] += dp2[v][0];
            dp[u][0] += max(dp[v][0], dp[v][1]);
            if(dp[v][0] > dp[v][1] || (dp[v][0] == dp[v][1] && dp2[v][0] < dp2[v][1])) {
                dp2[u][0] += dp2[v][0];
            } else {
                dp2[u][0] += dp2[v][1];
            }
        }
    };
    dfs(0, -1);
    vector<int> c(n);
    function<void(int, int, int)> dfs2 = [&](int u, int fa, int k) {
        c[u] = k;
        for(int v : g[u]) {
            if(v == fa) continue;
            if(k == 0) {
                dfs2(v, u, dp[v][1] > dp[v][0] || (dp[v][1] == dp[v][0] && dp2[v][1] < dp2[v][0]));
            } else {
                dfs2(v, u, 0);
            }
        }
    };
    dfs2(0, -1, dp[0][1] > dp[0][0] || (dp[0][1] == dp[0][0] && dp2[0][1] < dp2[0][0]));
    vector<int> ans(n);
    ll sum = 0; int cnt = n;
    for(int i = 0; i < n; ++i) {
        if(c[i] == 0) {
            --cnt;
            ans[i] = 1;
            for(int u : g[i]) {
                if(c[u]) ans[u] += 1;
            }
        }
    }
    for(int i = 0; i < n; ++i) sum += ans[i];
    cout << cnt << ' ' << sum << '\n';
    for(int i = 0; i < n; ++i) cout << ans[i] << ' '; cout << '\n';
}