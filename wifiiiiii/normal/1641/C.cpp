#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
    struct node {
        int mx = -1e9, fix = -1;
        void upd(int l, int r, int v) {
            mx = v;
            fix = v;
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.mx = max(x.mx, y.mx);
        return ret;
    }
    void pushdown(int l, int r, int rt) {
        int m = (l + r) / 2;
        if(a[rt].fix != -1) {
            a[rt << 1].upd(l, m, a[rt].fix);
            a[rt << 1 | 1].upd(m+1, r, a[rt].fix);
            a[rt].fix = -1;
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

struct segtree2 {
    struct node {
        int sum = 0, add = -1;
        void upd(int l, int r, int v) {
            sum = (r - l + 1) * v;
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
    vector<vector<int>> qs(q);
    for(int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if(op == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            qs[i] = {op, l, r, x};
        } else {
            int x;
            cin >> x;
            --x;
            qs[i] = {op, x};
        }
    }
    segtree st(n);
    segtree2 st2(n);
    for(int i = q - 1; i >= 0; --i) {
        if(qs[i][0] == 0 && qs[i][3] == 0) {
            int l = qs[i][1], r = qs[i][2];
            st.upd(l, r, i);
            st2.upd(l, r, 1);
        }
    }
    vector<int> know(n, 1e9);
    for(int i = 0; i < q; ++i) {
        if(qs[i][0] == 0 && qs[i][3] == 1) {
            int l = qs[i][1], r = qs[i][2];
            if(st2.qry(l, r).sum == r - l) {
                int lo = l, hi = r;
                while(lo < hi) {
                    int mid = (lo + hi) / 2;
                    if(st2.qry(l, mid).sum == mid - l) {
                        hi = mid;
                    } else {
                        lo = mid + 1;
                    }
                }
                int tt = st.qry(l, r).mx;
                know[lo] = min(know[lo], max(i, tt));
            }
        }
    }
    for(int i = 0; i < q; ++i) {
        if(qs[i][0] == 1) {
            int x = qs[i][1], p = st.qry(x, x).mx;
            if(p == -1e9) {
                if(know[x] < i) {
                    cout << "YES\n";
                } else {
                    cout << "N/A\n";
                }
            } else {
                if(p < i) {
                    cout << "NO\n";
                } else {
                    cout << "N/A\n";
                }
            }
        }
    }
}