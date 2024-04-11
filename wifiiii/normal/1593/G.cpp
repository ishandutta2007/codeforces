#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct segtree {
    struct node {
        int first = 0, end = 0, len = 0;
        void upd(int l, int r) {

        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        if(x.len == 0) return y;
        if(y.len == 0) return x;
        if(x.end == y.first) {
            ret.len = abs(x.len - y.len);
            if(x.len <= y.len) {
                ret.first = x.first ^ 1;
                ret.end = y.end;
            } else {
                ret.first = x.first;
                ret.end = y.end ^ 1;
            }
        } else {
            ret.len = x.len + y.len;
            ret.first = x.first;
            ret.end = y.end;
        }
        assert((ret.end ^ ret.first) == (ret.len + 1) % 2);
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
            a[rt].first = v[l];
            a[rt].end = v[l];
            a[rt].len = 1;
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
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> a(n);
        for(int i = 0; i < n; ++i) a[i] = (s[i] == ')' || s[i] == '(');
        segtree st(a);
        int q;
        cin >> q;
        while(q--) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << st.qry(l, r).len / 2 << '\n';
        }
    }
}