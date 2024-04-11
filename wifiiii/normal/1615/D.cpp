#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> g(n);
        vector<int> a(n);
        vector<tuple<int,int,int>> es, es2;
        for(int i = 1; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            if(w == -1) {
                es.push_back({u, v, -1});
            } else {
                es2.push_back({u, v, w});
                w = __builtin_popcount(w) & 1;
                g[u].push_back({v, w});
                g[v].push_back({u, w});
            }
        }
        for(int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        vector<int> vis(n);
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            function<void(int)> dfs = [&](int u) {
                vis[u] = 1;
                for(auto [v, w] : g[u]) {
                    if(vis[v]) {
                        if((a[u] ^ a[v]) != w) {
                            ok = 0;
                        }
                        continue;
                    }
                    a[v] = a[u] ^ w;
                    dfs(v);
                }
            };
            dfs(i);
        }
        if(ok == 0) {
            cout << "NO\n";
            continue;
        }
        for(auto &[u, v, w] : es) {
            w = a[u] ^ a[v];
        }
        cout << "YES\n";
        for(auto [u, v, w] : es) {
            cout << u + 1 << " " << v + 1 << " " << w << '\n';
        }
        for(auto [u, v, w] : es2) {
            cout << u + 1 << " " << v + 1 << " " << w << '\n';
        }
    }
}