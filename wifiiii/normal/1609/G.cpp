#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// sum
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

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
    int kth(T x) { // min pos s.t. [0, pos] >= x
        assert(x >= 0);
        int lg = 31 - __builtin_clz(n), pos = 0;
        for(int i = 1 << lg; i; i >>= 1) {
            if(pos + i <= n && a[pos + i - 1] < x) {
                pos += i;
                x -= a[pos - 1];
            }
        }
        return pos;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n), da(n-1);
    ll sum = 0;
    for(int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    for(int i = 0; i < n - 1; ++i) da[i] = a[i + 1] - a[i];
    vector<ll> b(m), c(m);
    fenwick<ll> db(m - 1);
    for(int i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        sum += x;
        b[i] = x;
    }
    c[0] = b[0];
    for(int i = 1; i < m; ++i) c[i] = b[i] - b[i-1];
    segtree st(c);
    for(int i = 0; i + 1 < m; ++i) {
        db.add(i, b[i + 1] - b[i]);
        if(i + 2 < m) db.add(i + 1, b[i] - b[i + 1]);
    }
    while(q--) {
        int type, k, d;
        cin >> type >> k >> d;
        if(type == 1) {
            for(int i = n - k, j = 1; i < n; ++i, ++j) {
                a[i] += j * d, sum += j * d;
                if(i - 1 >= 0) da[i - 1] += d;
            }
        } else {
            k = m - k;
            db.add(max(0, k - 1), d);
            st.upd(k, m - 1, d);
            sum += 1ll * (m - k) * (m - k + 1) / 2 * d;
        }
        int l = 0;
        ll ans = 0;
        for(int i = 0; i + 1 < n; ++i) {
            ll dt = a[i + 1] - a[i];
            // first j >= l, db[j] >= dt
            int j = db.kth(dt);
            assert(j >= l);
            // l -> j
            ans += (j - l) * a[i];
            l = j;
            ans += st.qry(0, l).sum;
        }
        ans += (m - 1 - l) * a[n - 1];
        cout << ans + sum << '\n';
    }
}