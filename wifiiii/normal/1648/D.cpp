#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
    struct node {
        ll mx = -1e18, add = -1e18;
        void upd(int l, int r, ll v) {
            mx = max(mx, v);
            add = max(add, v);
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.mx = max(x.mx, y.mx);
        return ret;
    }
    void pushdown(int l, int r, int rt) {
        int m = (l + r) / 2;
        a[rt << 1].upd(l, m, a[rt].add);
        a[rt << 1 | 1].upd(m+1, r, a[rt].add);
        a[rt].add = -1e18;
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

struct segtree2 {
    struct node {
        ll lmx = -1e18, rmx = -1e18, mx = -1e18;
        void upd(int l, int r, ll v) {
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.mx = max({x.mx, y.mx, x.lmx + y.rmx});
        ret.lmx = max(x.lmx, y.lmx);
        ret.rmx = max(x.rmx, y.rmx);
        return ret;
    }
    void pushdown(int l, int r, int rt) {
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
            a[rt].lmx = v[l].first, a[rt].rmx = v[l].second, a[rt].mx = v[l].first + v[l].second;
            return;
        }
        int m = (l + r) / 2;
        build(l, m, rt << 1, v);
        build(m + 1, r, rt << 1 | 1, v);
        a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
    }
    segtree2(int n):n(n), a(n << 2) {
        build(0, n - 1, 1);
    }
    template <typename T>
    segtree2(const vector<T> &v):n(v.size()), a(v.size() << 2) {
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
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    for(int i = 1; i <= n; ++i) cin >> b[i], b[i] += b[i - 1];
    for(int i = 1; i <= n; ++i) cin >> c[i], c[i] += c[i - 1];
    // 1 <= l <= r <= n, (a[l] - b[l - 1]) + (b[r] - c[r - 1]) + c[n]
    for(int i = 1; i <= n; ++i) a[i] -= b[i - 1];
    for(int i = 1; i <= n; ++i) b[i] -= c[i - 1];
    // a, b
    vector<tuple<int,int,int>> ss(q);
    for(auto &[l, r, k] : ss) cin >> l >> r >> k;
    sort(ss.begin(), ss.end());
    segtree st(n + 2);
    for(int i = 1; i <= n; ++i) st.upd(i, i, a[i]);
    for(auto [l, r, k] : ss) {
         st.upd(r + 1, r + 1, st.qry(l, r).mx - k);
    }
    vector<pair<ll,ll>> w(n + 1);
    for(int i = 1; i <= n; ++i) {
        ll l = st.qry(i, i).mx, r = b[i];
        w[i] = {l, r};
    }
    segtree2 st2(w);
    ll ans = -1e18;
    for(auto [l, r, k] : ss) {
        ans = max(ans, st2.qry(l, r).mx - k);
    }
    cout << ans + c[n] << '\n';
}