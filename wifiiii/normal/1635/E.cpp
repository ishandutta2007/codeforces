#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    vector<vector<int>> G(n);
    for(int i = 0; i < m; ++i) {
        int p, u, v;
        cin >> p >> u >> v;
        --u, --v;
        g[u].push_back({v, p});
        g[v].push_back({u, p});
    }
    vector<int> c(n), vis(n), deg(n), pos(n);
    vector<vector<int>> a(2);
    int ok = 1;
    function<void(int)> dfs = [&](int u) {
        a[c[u]].push_back(u);
        vis[u] = 1;
        for(auto [v, w] : g[u]) {
            if(vis[v]) {
                if(c[v] == c[u]) ok = 0;
                continue;
            }
            c[v] = c[u] ^ 1;
            dfs(v);
        }
    };
    int cur = 0;
    for(int i = 0; i < n; ++i) {
        if(vis[i]) continue;
        a[0].clear(), a[1].clear();
        dfs(i);
        if(!ok) break;
        for(int u : a[0]) {
            for(auto [v, w] : g[u]) {
                if(w == 1) G[u].push_back(v), deg[v]++;
                else G[v].push_back(u), deg[u]++;
            }
        }
        queue<int> q;
        for(int u : a[0]) if(deg[u] == 0) q.push(u);
        for(int u : a[1]) if(deg[u] == 0) q.push(u);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            pos[u] = cur++;
            for(int v : G[u]) {
                if(--deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        for(int u : a[0]) if(deg[u]) ok = 0;
        for(int u : a[1]) if(deg[u]) ok = 0;
        if(!ok) break;
    }
    if(!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for(int i = 0; i < n; ++i) {
            cout << (c[i] ? 'R' : 'L') << ' ' << pos[i] << '\n';
        }
    }
}