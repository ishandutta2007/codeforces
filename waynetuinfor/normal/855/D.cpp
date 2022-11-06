#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, lg = 20;
vector<pair<int, int>> G[maxn];
int dep[maxn], p[lg][maxn], tid[maxn], t;
bool edge[2][lg][maxn];

struct dsu {
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
        if (sz[x] > sz[y]) swap(x, y);
        par[x] = y; sz[y] += sz[x];
    }
} dsu;

void dfs(int now, int fa, int d) {
    dep[now] = d; p[0][now] = fa;
    for (auto u : G[now]) if (u.first != fa) {
        dfs(u.first, now, d + 1);
        edge[u.second][0][u.first] = true;
        edge[u.second ^ 1][0][u.first] = false;
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = lg - 1; i >= 0; --i) {
        if (dep[p[i][b]] >= dep[a]) {
            b = p[i][b];
        }
    }
    if (a == b) return a;
    for (int i = lg - 1; i >= 0; --i) {
        if (p[i][a] != p[i][b]) {
            a = p[i][a]; b = p[i][b];
        }
        if (a == b) return a;
    }
    return p[0][a];
}

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < lg; ++j) {
            if ((1 << j) > dep[i]) break;
            p[j][i] = p[j - 1][p[j - 1][i]];
            for (int k = 0; k < 2; ++k) edge[k][j][i] = edge[k][j - 1][i] && edge[k][j - 1][p[j - 1][i]];
        }
    }
}

bool get(int a, int b, int e) {
    bool ret = true;
    for (int i = lg - 1; i >= 0; --i) {
        if (dep[p[i][a]] >= dep[b]) {
            ret &= edge[e][i][a];
            a = p[i][a];
        }
    }
    if (dep[a] > dep[b]) ret &= edge[e][0][a];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> root;
    // bool ok = (n == 150);
    memset(dep, -1, sizeof(dep));
    dsu.init();
    for (int i = 1; i <= n; ++i) {
        int par, tp; cin >> par >> tp;
        if (par == -1 && tp == -1) root.push_back(i);
        else G[par].emplace_back(i, tp), G[i].emplace_back(par, tp), dsu.merge(par, i);
    }
    // assert(root != -1);
    for (int i : root) dfs(i, 0, 0);
    init(n);
    int cnt = 0;
    int q; cin >> q; while (q--) {
        int tp, a, b; cin >> tp >> a >> b;
        // if (cnt == 15 && ok) cout << tp << endl;
        if (dsu.find(a) != dsu.find(b)) {
            cout << "NO" << endl;
            continue;
        }
        int l = lca(a, b);
        if (tp == 1) {
            if (l == a && get(b, l, 0) && a != b) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            if (get(a, l, 0) && get(b, l, 1) && l != b) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}