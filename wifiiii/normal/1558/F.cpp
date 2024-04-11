#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    struct node {
        ll add = 0, mx = -1e18;
        void upd(int l, int r, int v) {
            add += v;
            mx += v;
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.mx = max(x.mx, y.mx);
        return ret;
    }
    void pushdown(int l, int r, int rt) {
        int m = (l + r) / 2;
        a[ls].upd(l, m, a[rt].add);
        a[rs].upd(m+1, r, a[rt].add);
        a[rt].add = 0;
    }
    void build(int l, int r, int rt) {
        if(l == r) {
            a[rt].mx = -1e9;
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

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T sum(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < a.size(); ++i) cin >> a[i];
        ll ans = 0;
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] > a[j];});
        vector<int> vis(n); int rightmost = n - 1;
        fenwick<int> fen(n);
        segtree st(n);
        for(int i : ord) {
            vis[i] = 1;
            while(rightmost >= 0 && vis[rightmost]) --rightmost;
            if(rightmost < 0) break;
            int tmp = fen.sum(i) + (i % 2 == 1) + (n - 1 - i - (fen.sum(n - 1) - fen.sum(i)));
            st.update(i, i, -st.query(i, i).mx + tmp);
            st.update(i + 1, n - 1, 1);
            if(i - 1 >= 0) st.update(0, i - 1, -1);
            ans = max(ans, st.query(0, rightmost).mx);
            fen.add(i, 1);
        }
        cout << ans << '\n';
    }
}