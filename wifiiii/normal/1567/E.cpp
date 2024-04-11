#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
    struct node {
        ll sum = 0, add = -1;
        void upd(int l, int r, ll v) {
            sum = v * (r - l + 1);
            add = v;
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.sum = x.sum + y.sum;
        return ret;
    }
    void pushdown(int l, int r, int rt) {
        int m = (l + r) / 2;
        if(a[rt].add != -1) {
            a[rt << 1].upd(l, m, a[rt].add);
            a[rt << 1 | 1].upd(m+1, r, a[rt].add);
            a[rt].add = -1;
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
    void update(int L, int R, const V&... v) {
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
    node query(int L, int R) {
        return query(L, R, 0, n - 1, 1);
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(n);
    for(int i = n - 1; i >= 0; --i) {
        if(i + 1 < n && a[i] <= a[i+1]) b[i] = b[i+1];
        else b[i] = i;
    }
    segtree s(b);
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y;
            cin >> x >> y;
            --x;
            int rb = x;
            if(x + 1 < n && y <= a[x + 1]) {
                rb = s.query(x + 1, x + 1).sum;
            }
            int lb = x;
            if(x - 1 >= 0) {
                int z = s.query(x - 1, x - 1).sum;
                int lo = 0, hi = x - 1;
                while(lo < hi) {
                    int mid = (lo + hi) / 2;
                    if(s.query(mid, mid).sum == z) hi = mid;
                    else lo = mid + 1;
                }
                lb = lo;
                if(y >= a[x - 1]) {
                    s.update(lb, x - 1, rb);
                }
                if(y < a[x - 1]) {
                    s.update(lb, x - 1, x - 1);
                }
            }
            s.update(x, x, rb);
            a[x] = y;
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            // [l, r]
            // find maximum x <= r, b[x] >= r
            int lo = l, hi = r;
            while(lo < hi) {
                int mid = (lo + hi) / 2;
                if(s.query(mid, mid).sum >= r) hi = mid;
                else lo = mid + 1;
            }
            ll ans = 1ll * (r - lo + 1) * r;
            if(l <= lo - 1) ans += s.query(l, lo - 1).sum;
            ans -= 1ll * (l + r) * (r - l + 1) / 2;
            ans += r - l + 1;
            cout << ans << "\n";
        }
    }
}