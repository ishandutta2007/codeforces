#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool ans[maxn], v[maxn];

struct djset {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    void merge(int u, int v) { p[find(u)] = find(v); }
} djs;

vector<pair<int, int>> ti[maxn];
vector<int> G[maxn];
int a[maxn], b[maxn], pac[maxn], tim[maxn], tin[maxn], tout[maxn], t;

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
    djs.merge(u, v);
}

void dfs(int now, int fa) {
    tin[now] = ++t;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
    }
    tout[now] = t;
}

bool anc(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    int pid = 0, q = 0;
    djs.init();
    for (int i = 0; i < m; ++i) {
        int t, x, y; cin >> t >> x;
        if (t == 1) a[i] = x, cin >> b[i], add_edge(a[i], b[i]);
        if (t == 2) ++pid, pac[pid] = x, tim[i] = pid;
        if (t == 3) cin >> y, ++q, ti[y].emplace_back(x, q);
    }
    for (int i = 1; i <= n; ++i) {
        if (!tin[i]) dfs(djs.find(i), 0);
    }
    djs.init();
    for (int i = 0; i < maxn; ++i) {
        djs.merge(a[i], b[i]);
        int p = tim[i];
        for (auto j : ti[p]) {
            if (djs.find(pac[p]) == djs.find(j.first) && anc(j.first, pac[p])) ans[j.second] = true;
            else ans[j.second] = false;
        }
    }
    for (int i = 1; i <= q; ++i) cout << (ans[i] ? "YES" : "NO") << endl;
    return 0;
}