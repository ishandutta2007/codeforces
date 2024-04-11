
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

template<typename T, typename F = function<T(const T &, const T &)>>
struct stable {
    int n;
    vector<vector<T>> st;
    F f;
    stable(const vector<T> &a, const F &f) : f(f), n(a.size()) {
        assert(n);
        int lg = 32 - __builtin_clz(n);
        st.resize(lg);
        st[0] = a;
        for(int i = 1; i < lg; ++i) {
            st[i].resize(n + 1 - (1 << i));
            for(int j = 0; j < n + 1 - (1 << i); ++j) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T qry(int l, int r) {
        // 0 <= l <= r < n
        int k = 31 - __builtin_clz(r - l + 1);
        return f(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

struct segbeats {
    struct node {
        ll sum = 0, mx = -1, mxse = -1, mxcnt = 1, tag = -1;
        int upd(int l, int r, ll k) {
            if(k >= mx) return 1;
            if(k > mxse) {
                sum += mxcnt * (k - mx);
                mx = tag = k;
                return 1;
            }
            return 0;
        }
        int brk(int l, int r, ll k) {
            return k >= mx;
        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        if(x.mx == -1) return y;
        if(y.mx == -1) return x;
        ret.sum = x.sum + y.sum;
        if(x.mx > y.mx) ret.mx = x.mx, ret.mxse = max(y.mx, x.mxse), ret.mxcnt = x.mxcnt;
        else if(x.mx < y.mx) ret.mx = y.mx, ret.mxse = max(x.mx, y.mxse), ret.mxcnt = y.mxcnt;
        else ret.mx = x.mx, ret.mxse = max(x.mxse, y.mxse), ret.mxcnt = x.mxcnt + y.mxcnt;
        return ret;
    }
    void pushdown(int l, int r, int rt) {
        int m = (l + r) / 2;
        if(a[rt].tag != -1) {
            a[rt << 1].upd(l, m, a[rt].tag);
            a[rt << 1 | 1].upd(m+1, r, a[rt].tag);
            a[rt].tag = -1;
        }
    }
    void build(int l, int r, int rt) {
        if(l == r) {
            a[rt].sum = a[rt].mx = 1e9;
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
    segbeats(int n):n(n), a(n << 2) {
        build(0, n - 1, 1);
    }
    template <typename T>
    segbeats(const vector<T> &v):n(v.size()), a(v.size() << 2) {
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
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    stable<int> st(a, [&](int i, int j) {return min(i, j);});
    vector<segbeats> sg;
    vector<int> sz;
    for(int i = 0; i < k; ++i) {
        segbeats s((n - i + k - 1) / k);
        sg.push_back(s);
        sz.push_back((n - i + k - 1) / k);
    }
    vector<vector<pair<int,int>>> qs(n);
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int len = (r - l) / k + 1;
        int lft = l / k;
        qs[l].push_back({lft + len - 1, i});
    }
    vector<ll> ans(q);
    for(int i = n - 1; i >= 0; --i) {
        int sid = i % k;
        int pos = i / k;
        if(i + k < n) sg[sid].upd(pos + 1, sz[sid] - 1, st.qry(i, i + k));
        for(auto [p, id] : qs[i]) {
            ll tmp = a[i];
            if(p > pos) tmp += sg[sid].qry(pos + 1, p).sum;
            ans[id] = tmp;
        }
    }
    for(int i = 0; i < q; ++i) cout << ans[i] << '\n';
}