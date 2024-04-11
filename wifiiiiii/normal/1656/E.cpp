#include<bits/stdc++.h>
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
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> ans(n);
        int rt = -1;
        for(int i = 0; i < n; ++i) {
            if(g[i].size() > 1) {
                rt = i;
                break;
            }
        }
        function<void(int, int, int)> dfs = [&](int u, int fa, int f) {
            ans[u] = g[u].size();
            if(f) ans[u] = -ans[u];
            for(int v : g[u]) {
                if(v == fa) continue;
                dfs(v, u, f ^ 1);
            }
        };
        dfs(rt, -1, 0);
        for(int i = 0; i < n; ++i) cout << ans[i] << ' '; cout << '\n';
    }
}