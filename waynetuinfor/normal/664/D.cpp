#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], b[maxn], n, m, cc;
char c[maxn];
vector<pair<int, int>> edge[maxn];
vector<int> ans, adj[maxn];
bool v[maxn];

struct dsu {
    int p[maxn], sz[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i, sz[i] = 1; }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { p[x = find(x)] = find(y); }
} dsu;

void dfs(int now) {
    v[now] = true;
    adj[cc].push_back(now);
    for (auto e : edge[now]) {
        if (!v[e.first]) dfs(e.first);
    }
}

void solve() {
    dsu.init();
    for (int i = 1; i <= n; ++i) {
        for (auto e : edge[i]) {
            if (c[e.second] == 'R') {
                dsu.merge(i << 1, e.first << 1);
                dsu.merge(i << 1 | 1, e.first << 1 | 1);
            } else {
                dsu.merge(i << 1, e.first << 1 | 1);
                dsu.merge(i << 1 | 1, e.first << 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dsu.find(i << 1) == dsu.find(i << 1 | 1)) return;
    }
    vector<int> now;
    for (int i = 1; i <= cc; ++i) {
        vector<int> t, f;
        t.push_back(adj[i][0]);
        for (size_t j = 1; j < adj[i].size(); ++j) {
            if (dsu.find(adj[i][j] << 1) == dsu.find(adj[i][0] << 1)) t.push_back(adj[i][j]);
            else f.push_back(adj[i][j]);
        }
        if (t.size() < f.size()) for (int j : t) now.push_back(j);
        else for (int j : f) now.push_back(j);
    }  
    if (now.size() < ans.size()) ans = now;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        edge[a[i]].emplace_back(b[i], i); edge[b[i]].emplace_back(a[i], i);
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) ++cc, dfs(i);
    }
    ans = vector<int>(n + 1);
    solve();
    for (int i = 0; i < m; ++i) {
        c[i] = (c[i] == 'R' ? 'B' : 'R');
    }
    solve();
    if (ans.size() == n + 1) return cout << "-1" << endl, 0;
    cout << ans.size() << endl;
    for (int u : ans) cout << u << ' '; cout << endl;
    return 0;
}