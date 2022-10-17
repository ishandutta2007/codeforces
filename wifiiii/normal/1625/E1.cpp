#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 1. 
// 2.  x x*(x+1)/2
// 3. 

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick() {}
    fenwick(int n): n(n), a(n) {}
    void init(int _n) {
        n = _n;
        a.resize(n);
    }
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
};

struct segtree {
    struct node {
        ll sum = 0, add = 0;
        void upd(int l, int r, ll v) {
            sum = sum + (r - l + 1) * v;
            add = add + v;
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.sum = x.sum + y.sum;
        return ret;
    }
    void pushdown(int l, int r, int rt) {
        int m = (l + r) / 2;
        a[rt << 1].upd(l, m, a[rt].add);
        a[rt << 1 | 1].upd(m+1, r, a[rt].add);
        a[rt].add = 0;
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
            a[rt].sum = v[l];
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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> match(n, -1);
    stack<int> stk;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '(') {
            stk.push(i);
        } else {
            if(!stk.empty()) {
                int p = stk.top(); stk.pop();
                match[p] = i;
                match[i] = p;
            }
        }
    }
    vector<vector<int>> g(n + 1);
    vector<ll> dp(n + 1); vector<int> f(n + 1, -1);
    vector<fenwick<int>> fen(n + 1);
    function<void(int)> dfs = [&](int u) {
        dp[u] = 1ll * g[u].size() * (g[u].size() + 1) / 2;
        for(int v : g[u]) {
            f[v] = u;
            dfs(v);
        }
        fen[u].init(g[u].size());
        for(int i = 0; i < g[u].size(); ++i) fen[u].add(i, 1);
    };
    function<void(int,int)> build = [&](int l, int r) {
        for(int j = l + 1; j < r; ++j) {
            g[l].push_back(j);
            build(j, match[j]);
            j = match[j];
        }
    };
    for(int i = 0; i < n; ++i) {
        if(match[i] == -1) continue;
        build(i, match[i]);
        g[n].push_back(i);
        i = match[i];
    }
    dfs(n);
    segtree st(dp);
    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        if(t == 2) {
            ll ans = st.qry(l, r).sum;
            if(f[l] == -1) {
                cout << ans + 1 << '\n';
            } else {
                int fa = f[l];
                int lp = lower_bound(g[fa].begin(), g[fa].end(), l) - g[fa].begin(),
                    rp = lower_bound(g[fa].begin(), g[fa].end(), r) - g[fa].begin() - 1;
                int sz = fen[fa].qry(rp) - fen[fa].qry(lp - 1);
                ans += 1ll * sz * (sz + 1) / 2;
                cout << ans << '\n';
            }
        } else {
            st.upd(l, l, -dp[l]);
            if(f[l] != -1) {
                int fa = f[l];
                int p = lower_bound(g[fa].begin(), g[fa].end(), l) - g[fa].begin();
                fen[fa].add(p, -1);
            }
        }
    }
}