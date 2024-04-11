#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for(int i = 1; i < n; ++i) {
            int p;
            cin >> p;
            --p;
            g[p].push_back(i);
        }
        vector<vector<int>> dp(n, vector<int>(2));
        string s;
        cin >> s;
        function<void(int)> dfs = [&](int u) {
            dp[u][s[u]=='B'?0:1] += 1;
            for(int v : g[u]) {
                dfs(v);
                dp[u][0] += dp[v][0];
                dp[u][1] += dp[v][1];
            }
        };
        dfs(0);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(dp[i][0] == dp[i][1]) ans += 1;
        }
        cout << ans << '\n';
    }
}