#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct segtree {
    struct node {
        ll sum = 0, mn = 1e18, mx = -1e18, put = -1;
        int upd(int l, int r, ll v1, ll v2) {
            assert((v1 == -1) ^ (v2 == -1));
            if(v1 != -1) {
                if(mn == mx) {
                    mn %= v1;
                    mx %= v1;
                    put = mn;
                    sum = mn * (r - l + 1);
                    return 1;
                }
                return 0;
            } else {
                mx = mn = put = v2;
                sum = mn * (r - l + 1);
                return 1;
            }
            return 0;
        }
        int brk(int l, int r, ll v1, ll v2) {
            assert((v1 == -1) ^ (v2 == -1));
            if(v1 != -1 && mx < v1) return 1;
            return 0;
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.sum = x.sum + y.sum;
        ret.mn = min(x.mn, y.mn);
        ret.mx = max(x.mx, y.mx);
        return ret;
    }
    void pushdown(int l, int r, int rt) {
        if(a[rt].put != -1) {
            int m = (l + r) / 2;
            a[rt << 1].upd(l, m, -1, a[rt].put);
            a[rt << 1 | 1].upd(m+1, r, -1, a[rt].put);
            a[rt].put = -1;
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
            a[rt].sum = a[rt].mn = a[rt].mx = v[l];
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
        if(a[rt].brk(l, r, v...)) return;
        if(L <= l && r <= R && a[rt].upd(l, r, v...)) return;
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
    for(int i = 0; i < n; ++i) cin >> a[i];
    segtree st(a);
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << st.qry(l, r).sum << '\n';
        } else if(op == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            st.upd(l, r, x, -1);
        } else {
            int k, x;
            cin >> k >> x;
            --k;
            st.upd(k, k, -1, x);
        }
    }
}