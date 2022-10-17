#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct edge {
    int v, vis, rev, id;
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<vector<edge>>> g(n + 1, vector<vector<edge>>(2));
    vector<int> deg(n + 1), sum(n + 1), ans(m);
    vector<pair<int,int>> es(m);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        es[i] = {u, v};
        g[u][w-1].push_back({v, 0, (int)g[v][w-1].size(), i});
        g[v][w-1].push_back({u, 0, (int)g[u][w-1].size() - 1, i});
        deg[u] += 1;
        deg[v] += 1;
        sum[u] += w;
        sum[v] += w;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(deg[i] % 2 == 1) {
            g[n][0].push_back({i, 0, (int)g[i][0].size(), -1});
            g[i][0].push_back({n, 0, (int)g[n][0].size() - 1, -1});
        }
    }
    for(int i = 0; i < n; ++i) if(sum[i] & 1) cnt += 1;
    vector<int> vis(n + 1);
    function<void(int,int)> dfs = [&](int u, int p) {
        vis[u] = 1;
        for(int w : {p, p^1}) {
            for(auto &[v, vis, rev, id] : g[u][w]) {
                if(vis) continue;
                vis = g[v][w][rev].vis = 1;
                dfs(v, w);
                if(id != -1) {
                    if(es[id] == make_pair(v, u)) {
                        ans[id] = 1;
                    } else {
                        ans[id] = 2;
                    }
                }
            }
        }
    };
    for(int i = 0; i <= n; ++i) {
        if(!vis[i]) dfs(i, 0);
    }
    cout << cnt << '\n';
    for(int i = 0; i < m; ++i) cout << ans[i];
    cout << '\n';
}