#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

struct segtree {
    struct node {
        int mx = -1, lz = -1;
        void upd(int l, int r, int v) {
            mx = max(mx, v);
            lz = max(lz, v);
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.mx = max(x.mx, y.mx);
        return ret;
    }
    void pushdown(int l, int r, int rt) {
        int m = (l + r) / 2;
        a[rt << 1].upd(l, m, a[rt].lz);
        a[rt << 1 | 1].upd(m+1, r, a[rt].lz);
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
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];

        vector<int> b = a;
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        for(int &x : a) x = lower_bound(b.begin(), b.end(), x) - b.begin();

        vector<vector<int>> pos(n);
        for(int i = 0; i < n; ++i) pos[a[i]].push_back(i);

        segtree st(n);
        for(int i = 0; i < m; ++i) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            st.upd(l, r, r);
        }
        int lm = n - 1;
        vector<vector<pair<int,int>>> q(n);
        multiset<int> s;
        for(int i = 0; i < n; ++i) {
            int p = st.qry(i, i).mx;
            if(p == -1) continue;
            int z = *--upper_bound(pos[a[i]].begin(), pos[a[i]].end(), p);
            if(z != i) {
                int y = *--lower_bound(pos[a[i]].begin(), pos[a[i]].end(), z);
                int x = *upper_bound(pos[a[i]].begin(), pos[a[i]].end(), i);
                // l <= x
                lm = min(lm, x);
                // <=i ~ y  /  >=i ~ z
                q[i].push_back({y, z});
                s.insert(y);
            }
        }
        if(s.empty()) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 1e9;
        for(int l = 0; l <= lm; ++l) {
            ans = min(ans, *prev(s.end()) - l + 1);
            for(auto [y, z] : q[l]) {
                s.erase(s.find(y));
                s.insert(z);
            }
        }
        cout << ans << '\n';
    }
}