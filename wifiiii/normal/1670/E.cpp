#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int p;
        cin >> p;
        int n = 1 << p;
        vector<vector<pair<int,int>>> g(n + 1);
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back({v, i});
            g[v].push_back({u, i});
        }
        vector<int> dep(n + 1), ans(n + 1), anse(n);
        function<void(int, int)> dfs = [&](int u, int fa) {
            for(auto [v, id] : g[u]) {
                if(v == fa) continue;
                dep[v] = dep[u] ^ 1;
                if(dep[v]) {
                    anse[id] = v | n;
                    ans[v] = v;
                } else {
                    anse[id] = v;
                    ans[v] = v | n;
                }
                dfs(v, u);
            }
        };
        ans[n] = n;
        dfs(n, -1);
        cout << n << '\n';
        for(int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << '\n';
        for(int i = 1; i < n; ++i) cout << anse[i] << ' '; cout << '\n';
    }
}