#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
    struct node {
        ll mn = 1e18, add = 0;
        void upd(int l, int r, ll v) {
            mn += v;
            add += v;
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.mn = min(x.mn, y.mn);
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
            a[rt].mn = v[l];
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
    int first_neg(int L, int R, int l, int r, int rt) {
        if(a[rt].mn >= 0) return n;
        if(l == r) return l;
        pushdown(l, r, rt);
        int m = (l + r) / 2, tmp;
        if(L <= m && (tmp = first_neg(L, R, l, m, rt << 1)) != n) return tmp;
        if(m < R) return first_neg(L, R, m+1, r, rt << 1 | 1);
        return n;
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
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<ll> b = a;
        for(int i = 1; i < n; ++i) a[i] = a[i] - a[i - 1];
        // divide it into two parts : odd and even
        vector<ll> o(n, 1e18), e(n, 1e18);
        for(int i = 0; i < n; i += 2) e[i] = a[i];
        for(int i = 1; i < n; i += 2) o[i] = a[i];
        segtree st0(e), st1(o);
        map<ll, vector<int>> mp0, mp1;
        for(int i = 0; i < n; i += 2) {
            mp0[a[i]].push_back(i);
        }
        for(int i = 1; i < n; i += 2) {
            mp1[a[i]].push_back(i);
        }
        ll tot0 = 0, tot1 = 0;
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            int r = min(st0.first_neg(i + 1, n - 1, 0, n - 1, 1), st1.first_neg(i + 1, n - 1, 0, n - 1, 1)) - 1;
            // find the number of j s.t. i <= j <= r, a[j] == 0
            vector<int> &v0 = mp0[-tot0], &v1 = mp1[-tot1];
            ans += upper_bound(v0.begin(), v0.end(), r) - upper_bound(v0.begin(), v0.end(), i - 1);
            ans += upper_bound(v1.begin(), v1.end(), r) - upper_bound(v1.begin(), v1.end(), i - 1);
            if(i % 2 == 0) {
                st0.upd(i, n - 1, -b[i]); tot0 -= b[i];
                st1.upd(i, n - 1, b[i]); tot1 += b[i];
            } else {
                st0.upd(i, n - 1, b[i]); tot0 += b[i];
                st1.upd(i, n - 1, -b[i]); tot1 -= b[i];
            }
        }
        cout << ans << '\n';
    }
}