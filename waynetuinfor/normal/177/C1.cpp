#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10;
vector<int> G[maxn], vtx;
bool v[maxn], used[maxn];

struct Dsu {
    int par[maxn], sz[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) par[i] = i, sz[i] = 1;
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        par[x] = y; sz[y] += sz[x];
    }
} dsu;

void dfs(int now) {
    v[now] = true;
    vtx.push_back(now);
    for (int u : G[now]) if (!v[u]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    dsu.init();
    int k; cin >> k; while (k--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    vector<pair<int, int>> edge;
    int m; cin >> m; while (m--) {
        int a, b; cin >> a >> b;
        // dsu.merge(a, b);
        edge.push_back(make_pair(min(a, b), max(a, b)));
    }
    sort(edge.begin(), edge.end());
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        vtx.clear();
        dfs(i);
        bool ok = true;
        for (int j = 0; j < vtx.size(); ++j) {
            for (int k = j + 1; k < vtx.size(); ++k) {
                int a = min(vtx[j], vtx[k]), b = max(vtx[j], vtx[k]);
                int ind = lower_bound(edge.begin(), edge.end(), make_pair(a, b)) - edge.begin();
                if (ind < edge.size()) if (edge[ind] == make_pair(a, b)) ok = false;
            }
        }
        if (ok) ans = max(ans, (int)vtx.size());
    }
    cout << ans << endl;
    return 0;
}