#include <bits/stdc++.h>
using namespace std;

struct Path {
    bool is_path, is_null, is_chain;
    int u, v, hd;

    Path() : is_null(false) {}
    Path(bool null) : is_null(null) {}
    Path(int u) : u(u), v(u), hd(u), is_path(true), is_null(false), is_chain(true) {}
};

int main() {
    int n;
    scanf("%d", &n);
    vector<int> p(n), pos(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int pr;
        scanf("%d", &pr);
        g[pr - 1].push_back(i);
    }

    vector<int> dep(n), tin(n), tout(n);
    vector<vector<int>> fa(n);
    function<void(int, int)> Dfs = [&](int x, int p) {
        static int tk = 0;
        tin[x] = tk++;
        fa[x].push_back(p);
        dep[x] = ~p ? dep[p] + 1 : 0;
        for (int i = 1; (1 << i) <= dep[x]; ++i) fa[x].push_back(fa[fa[x][i - 1]][i - 1]);
        for (int u : g[x]) Dfs(u, x);
        tout[x] = tk;
    };

    auto IsAnc = [&](int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    };

    auto GetLCA = [&](int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = 0; i < fa[v].size(); ++i) {
            if ((dep[v] - dep[u]) >> i & 1) v = fa[v][i];
        }
        if (u == v) return u;
        for (int i = 19; i >= 0; --i) {
            if (i >= fa[u].size() || i >= fa[v].size()) continue;
            if (fa[u][i] != fa[v][i]) {
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    };

    Dfs(0, -1);

    auto Jump = [&](int v, int k) {
        for (int i = 0; i < fa[v].size(); ++i) {
            if (k >> i & 1) v = fa[v][i];
        }
        return v;
    };

    auto GetImmediate = [&](int u, int v) {
        if (u == v) return u;
        assert(dep[u] < dep[v]);
        return Jump(v, dep[v] - dep[u] - 1);
    };

    const Path kNull(true);

    auto Insert = [&](Path &p, int u) {
        int r = GetLCA(p.hd, u);
        if (dep[p.u] > dep[p.v]) swap(p.u, p.v);
        if (r != p.hd) {
            if (!p.is_chain) {
                p.is_path = false;
                return;
            }
            p.hd = r;
            p.u = u;
            if (u != r) p.is_chain = false;
            return;
        }
        if (p.is_chain) {
            if (IsAnc(p.v, u)) p.v = u;
            else if (!IsAnc(u, p.v) && GetLCA(u, p.v) != p.u) p.is_path = false;
            else if (!IsAnc(u, p.v)) p.is_chain = false, p.u = u;
        } else {
            if (IsAnc(p.u, u)) p.u = u;
            else if (IsAnc(p.v, u)) p.v = u;
            else if (!IsAnc(u, p.u) && !IsAnc(u, p.v)) p.is_path = false;
        }
    };

    auto Merge = [&](const Path &a, const Path &b) {
        if (a.is_null) return b;
        if (b.is_null) return a;
        Path res;
        if (!a.is_path || !b.is_path) {
            res.is_path = false;
            return res;
        }
        // printf("Merge a = (%d,%d), b = (%d,%d)\n", a.u, a.v, b.u, b.v);
        res = a;
        Insert(res, b.u);
        Insert(res, b.v);
        // printf("res = (%d,%d) is_path = %d\n", res.u, res.v, (int)res.is_path);
        return res;
    };

    vector<Path> tree(n * 4);

    auto BuildTree = [&]() {
        auto BuildTreeImpl = [&](auto self, int l, int r, int o = 0) {
            if (r - l == 1) {
                tree[o] = Path(pos[l]);
                return;
            }
            int m = (l + r) >> 1;
            self(self, l, m, o * 2 + 1);
            self(self, m, r, o * 2 + 2);
            tree[o] = Merge(tree[o * 2 + 1], tree[o * 2 + 2]);
        };
        BuildTreeImpl(BuildTreeImpl, 0, n);
    };

    auto Modify = [&](int p, int v) {
        auto ModifyImpl = [&](auto self, int l, int r, int p, int v, int o = 0) {
            if (r - l == 1) {
                tree[o] = Path(v);
                return;
            }
            int m = (l + r) >> 1;
            if (p < m) self(self, l, m, p, v, o * 2 + 1);
            else self(self, m, r, p, v, o * 2 + 2);
            tree[o] = Merge(tree[o * 2 + 1], tree[o * 2 + 2]);
        };
        ModifyImpl(ModifyImpl, 0, n, p, v);
    };

    auto Query = [&]() {
        auto QueryImpl = [&](auto self, int l, int r, const Path &f, int o = 0) {
            if (r - l == 1) {
                Path g = Merge(f, tree[o]);
                if (g.is_path) return r;
                return l;
            }
            Path mg = Merge(f, tree[o * 2 + 1]);
            int m = (l + r) >> 1;
            if (mg.is_path) return self(self, m, r, mg, o * 2 + 2);
            return self(self, l, m, f, o * 2 + 1);
        };
        return QueryImpl(QueryImpl, 0, n, kNull);
    };

    BuildTree();

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            Modify(p[u], v);
            Modify(p[v], u);
            swap(p[u], p[v]);
        } else {
            int res = Query();
            printf("%d\n", res);
        }
    }
    return 0;
}