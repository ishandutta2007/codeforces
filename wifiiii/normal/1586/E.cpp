#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), G(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for(int v : g[u]) {
            if(vis[v]) continue;
            G[u].push_back(v);
            G[v].push_back(u);
            dfs(v);
        }
    };
    dfs(0);
    vector<int> deg(n);
    int q;
    cin >> q;
    vector<pair<int,int>> ps;
    while(q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ps.push_back({u, v});
        deg[u]++, deg[v]++;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(deg[i] & 1) {
            cnt += 1;
        }
    }
    if(cnt) {
        cout << "NO" << endl;
        cout << cnt / 2 << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> path;
    function<int(int,int,int)> dfs2 = [&](int u, int fa, int x) -> int {
        if(u == x) return 1;
        for(int v : G[u]) {
            if(v == fa) continue;
            if(dfs2(v, u, x)) {
                path.push_back(v);
                return 1;
            }
        }
        return 0;
    };
    for(auto [u, v] : ps) {
        path.clear();
        dfs2(u, -1, v);
        path.push_back(u);
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for(int i : path) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }
}