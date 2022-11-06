#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> edge;
vector<pair<int, int>> G[maxn];
int a[maxn], b[maxn], c[maxn], ans[maxn], tin[maxn], low[maxn], t;
bool v[maxn];

struct dsu {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { p[find(x)] = find(y); }
} dsu;

void dfs(int now) {
    tin[now] = low[now] = ++t;
    for (auto u : G[now]) if (!v[u.second]) {
        v[u.second] = true;
        if (tin[u.first]) {
            low[now] = min(low[now], tin[u.first]);
            continue;
        }
        dfs(u.first);
        low[now] = min(low[now], low[u.first]);
        if (low[u.first] > tin[now]) ans[u.second] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        edge.push_back(i);
    }
    sort(edge.begin(), edge.end(), [&](const int &i, const int &j) { return c[i] < c[j]; });
    dsu.init();
    fill(ans, ans + maxn, -1);
    for (size_t i = 0; i < edge.size(); ) {
        size_t ptr = i;
        while (ptr < edge.size() && c[edge[ptr]] == c[edge[i]]) {
            int u = dsu.find(a[edge[ptr]]), v = dsu.find(b[edge[ptr]]);
            if (u == v) ans[edge[ptr]] = 0;
            else G[u].emplace_back(v, edge[ptr]), G[v].emplace_back(u, edge[ptr]);
            ++ptr;
        }
        for (size_t j = i; j < ptr; ++j) {
            if (!v[edge[j]]) dfs(dsu.find(a[edge[j]]));
        }
        for (size_t j = i; j < ptr; ++j) {
            int u = dsu.find(a[edge[j]]), v = dsu.find(b[edge[j]]);
            tin[u] = low[u] = tin[v] = low[v] = 0;
            G[u].clear(); G[v].clear();
            dsu.merge(u, v);
        }
        i = ptr;
    } 
    for (int i = 0; i < m; ++i) {
        if (ans[i] == 0) cout << "none" << endl;
        else if (ans[i] == 1) cout << "any" << endl;
        else cout << "at least one" << endl;
    }
    return 0;
}