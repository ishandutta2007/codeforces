#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
    struct node {
        int mn = 1e9, add = 0;
        void upd(int l, int r, int v) {
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
            a[rt].mn = 0;
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
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
        a.resize(m);
        segtree st(m + 1);
        for(int i = 1; i <= m; ++i) st.upd(i, i, i);
        vector<int> pos(m);
        vector<vector<int>> b(m);
        for(int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            b[i].resize(k);
            ll s = 0;
            for(int j = 0; j < k; ++j) {
                cin >> b[i][j];
                s += b[i][j];
            }
            int avg = (s + k - 1) / k;
            pos[i] = upper_bound(a.begin(), a.end(), avg, greater<int>()) - a.begin() - 1;
            st.upd(pos[i] + 1, m, -1);
        }
        vector<int> ans;
        for(int i = 0; i < m; ++i) {
            ll s = 0;
            for(auto j : b[i]) {
                s += j;
            }
            int k = b[i].size();
            st.upd(pos[i] + 1, m, 1);
            for(auto j : b[i]) {
                int navg = (s - j + k - 1 - 1) / (k - 1);
                int npos = upper_bound(a.begin(), a.end(), navg, greater<int>()) - a.begin() - 1;
                st.upd(npos + 1, m, -1);
                if(st.qry(0, m).mn >= 0) {
                    ans.push_back(1);
                } else {
                    ans.push_back(0);
                }
                st.upd(npos + 1, m, 1);
            }
            st.upd(pos[i] + 1, m, -1);
        }
        for(int i : ans) cout << i;
        cout << '\n';
    }
}