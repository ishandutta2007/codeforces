#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct ufind {
    vector<int> par, sz;
    ufind(int n) : par(n), sz(n, 1) {
        for(int i = 0; i < n; ++i) par[i] = i;
    }
    int find(int x) {
        if(x != par[x]) return par[x] = find(par[x]);
        return x;
    }
    int size(int x) {
        return sz[find(x)];
    }
    int same(int u, int v) {
        return find(u) == find(v);
    }
    int merge(int u, int v) {
        int x = find(u), y = find(v);
        if(x == y) return 0;
        if(sz[x] < sz[y]) swap(sz[x], sz[y]), swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        return 1;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> diff;
        ufind uf(n);
        while(m--) {
            int u, v;
            string s;
            cin >> u >> v >> s;
            --u, --v;
            if(s[0] == 'i') {
                diff.push_back({u, v});
            } else {
                uf.merge(u, v);
            }
        }
        vector<vector<int>> g(n);
        int ok = 1;
        for(auto [u, v] : diff) {
            if(uf.same(u, v)) {
                ok = 0;
                break;
            }
            g[uf.find(u)].push_back(uf.find(v));
            g[uf.find(v)].push_back(uf.find(u));
        }
        for(int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end());
            g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
        }
        vector<int> color(n), vis(n);
        vector<int> cnt(2);
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            cnt[color[u]] += uf.size(u);
            for(int v : g[u]) {
                if(vis[v]) {
                    if(color[v] == color[u]) ok = 0;
                    continue;
                }
                color[v] = color[u] ^ 1;
                dfs(v);
            }
        };
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(ok == 0) break;
            if(!vis[i] && uf.find(i) == i) {
                cnt[0] = cnt[1] = 0;
                dfs(i);
                ans += max(cnt[0], cnt[1]);
            }
        }
        if(ok == 0) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
}