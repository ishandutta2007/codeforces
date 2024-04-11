#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int x = 0;
        for(int i = 0; i < n; ++i) cin >> a[i], x ^= a[i];
        vector<vector<int>> g(n);
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(x == 0) {
            cout << "Yes" << '\n';
            continue;
        }
        if(k == 2) {
            cout << "No" << '\n';
            continue;
        }
        int ok = 0;
        vector<int> dp(n);
        function<int(int,int)> dfs = [&](int u, int fa) {
            dp[u] = a[u];
            int ret = 0;
            for(int v : g[u]) {
                if(v == fa) continue;
                ret += dfs(v, u);
                if(dp[v] == x) {
                    ret += 1;
                }
                if(ret && dp[v] == 0) {
                    ok = 1;
                }
                dp[u] ^= dp[v];
            }
            if(ret >= 2) ok = 1;
            return ret;
        };
        dfs(0, -1);
        cout << (ok ? "Yes" : "No") << '\n';
    }
}