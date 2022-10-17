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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    vector<array<int,3>> es(m);
    ufind uf(n), uf2(n);
    ll sum = 0;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; sum ^= w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        es[i] = {w, u, v};
    }
    sort(es.begin(), es.end());
    for(int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    set<int> s;
    for(int i = 0; i < n; ++i) s.insert(i);
    vector<int> vis(n);
    queue<int> q;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(vis[i]) continue;
        q.push(i); s.erase(i);
        vector<int> b;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = 1;
            b.push_back(u);
            int j = 0;
            auto it = s.begin();
            while(it != s.end()) {
                int v = *it;
                while(j < g[u].size() && g[u][j].first < v) ++j;
                if(j == g[u].size() || g[u][j].first != v) {
                    q.push(v); it = s.erase(it);
                } else {
                    ++it;
                }
            }
        }
        for(int u : b) uf.merge(u, b[0]);
        cnt += b.size() - 1;
    }
    ll ans = 0, mn = 2e9;
    for(auto [w, u, v] : es) {
        if(!uf.same(u, v)) {
            ans += w;
            uf.merge(u, v);
            uf2.merge(u, v);
        }
        if(!uf2.same(u, v)) {
            mn = min(mn, (ll)w);
        }
    }
    if(cnt + m == 1ll * n * (n - 1) / 2) {
        ans += min(mn, sum);
    }
    cout << ans << '\n';
}