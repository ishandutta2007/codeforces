#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct segtree {
    struct node {
        ll sum = 0, tag = -1;
        void upd(int l, int r, ll v) {
            sum = tag = v;
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.sum = x.sum | y.sum;
        return ret;
    }
    void pushdown(int l, int r, int rt) {
        int m = (l + r) / 2;
        if(a[rt].tag != -1) {
            a[rt << 1].upd(l, m, a[rt].tag);
            a[rt << 1 | 1].upd(m+1, r, a[rt].tag);
            a[rt].tag = -1;
        }
    }
    void build(int l, int r, int rt) {
        if(l == r) {
            return;
        }
        int m = (l + r) / 2;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
    }
    template <typename T>
    void build(int l, int r, int rt, const vector<T> &v) {
        if(l == r) {
            return;
        }
        int m = (l + r) / 2;
        build(l, m, rt << 1, v);
        build(m + 1, r, rt << 1 | 1, v);
        a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
    }
    segtree(int n):n(n), a(n << 2) {
        build(0, n - 1, 1);
    }
    template <typename T>
    segtree(const vector<T> &v):n(v.size()), a(v.size() << 2) {
        build(0, n - 1, 1, v);
    }

    int n;
    vector<node> a;
    template <typename... V>
    void update(int L, int R, int l, int r, int rt, const V&... v) {
        if(L <= l && r <= R) {
            a[rt].upd(l, r, v...);
            return;
        }
        pushdown(l, r, rt);
        int m = (l + r) / 2;
        if(L <= m) update(L, R, l, m, rt << 1, v...);
        if(m < R) update(L, R, m+1, r, rt << 1 | 1, v...);
        a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
    }
    template <typename... V>
    void upd(int L, int R, const V&... v) {
        update(L, R, 0, n - 1, 1, v...);
    }
    node query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return a[rt];
        node ret;
        pushdown(l, r, rt);
        int m = (l + r) / 2;
        if(L <= m) ret = merge(ret, query(L, R, l, m, rt << 1));
        if(m < R) ret = merge(ret, query(L, R, m+1, r, rt << 1 | 1));
        return ret;
    }
    node qry(int L, int R) {
        return query(L, R, 0, n - 1, 1);
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
    vector<vector<int>> g(n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> sz(n), id(n);
    int tot = 0;
    function<void(int,int)> dfs = [&](int u, int fa) {
        id[u] = tot++;
        sz[u] = 1;
        for(int v : g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            sz[u] += sz[v];
        }
    };
    dfs(0, -1);
    segtree st(n);
    for(int i = 0; i < n; ++i) {
        st.upd(id[i], id[i], 1ll << a[i]);
    }
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int u, x;
            cin >> u >> x;
            --u, --x;
            st.upd(id[u], id[u] + sz[u] - 1, 1ll << x);
        } else {
            int u;
            cin >> u;
            --u;
            int ans = __builtin_popcountll(st.qry(id[u], id[u] + sz[u] - 1).sum);
            cout << ans << '\n';
        }
    }
}