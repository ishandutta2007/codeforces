#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<pair<int,int>>> g(n);
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back({v, i});
            g[v].push_back({u, i});
        }
        int ok = 1, rt = -1;
        for(int i = 0; i < n; ++i) {
            if(g[i].size() > 2) {
                ok = 0;
            }
            if(g[i].size() == 1) {
                rt = i;
            }
        }
        if(ok == 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans(n);
        function<void(int, int, int)> dfs = [&](int u, int fa, int c) {
            for(auto [v, id] : g[u]) {
                if(v == fa) continue;
                ans[id] = c;
                dfs(v, u, 7 - c);
            }
        };
        dfs(rt, -1, 2);
        for(int i = 1; i < n; ++i) cout << ans[i] << " "; cout << '\n';
    }
}