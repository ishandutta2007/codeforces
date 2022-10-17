#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    segtree st(n + 1);
    for(int i = 0; i < n; ++i) {
        st.upd(i, i, a[i]);
        st.upd(i + 1, i + 1, -a[i]);
    }
    ll ans = 0;
    for(int i = n - 1; i >= k - 1; --i) {
        ll x = (st.qry(0, i).sum + k - 1) / k;
        if(x > 0) {
            ans += x;
            st.upd(i + 1, i + 1, x * k);
            st.upd(i - k + 1, i, -x);
        }
    }
    ll mx = 0;
    for(int i = 0; i < k; ++i) {
        ll x = (st.qry(0, i).sum + i) / (i + 1);
        mx = max(mx, x);
    }
    ans += mx;
    cout << ans << '\n';
}