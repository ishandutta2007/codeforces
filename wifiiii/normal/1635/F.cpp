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

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n, numeric_limits<T>::max()) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = min(x + 1, n); i > 0; i -= i & -i) a[i - 1] = min(a[i - 1], v);
    }
    T qry(int x) {
        T ret = numeric_limits<T>::max();
        for(int i = x + 1; i <= n; i += i & -i) ret = min(ret, a[i - 1]);
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<int> stk(n + 1); int tp = 0;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; ++i) {
        while(tp && b[stk[tp]] > b[i]) --tp;
        if(tp) l[i] = stk[tp];
        else l[i] = -1;
        stk[++tp] = i;
    }
    tp = 0;
    for(int i = n - 1; i >= 0; --i) {
        while(tp && b[stk[tp]] > b[i]) --tp;
        if(tp) r[i] = stk[tp];
        else r[i] = -1;
        stk[++tp] = i;
    }
    vector<vector<int>> upd(n);
    for(int i = 0; i < n; ++i) {
        if(l[i] != -1) {
            upd[i].push_back(l[i]);
        }
        if(r[i] != -1) {
            upd[r[i]].push_back(i);
        }
    }
    vector<ll> c(n);
    for(int i = 0; i + 1 < n; ++i) {
        c[i] = 1ll * (a[i + 1] - a[i]) * (b[i] + b[i + 1]);
    }
    stable st(c, [&](ll i, ll j) {return min(i, j);});
    vector<ll> ans(q);
    vector<vector<pair<int,int>>> qs(n);
    for(int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        qs[y].push_back({x, i});
        ans[i] = st.qry(x, y - 1);
    }
    fenwick<ll> fen(n);
    for(int i = 0; i < n; ++i) {
        for(int x : upd[i]) {
            fen.add(x, 1ll * (a[i] - a[x]) * (b[i] + b[x]));
        }
        for(auto [x, id] : qs[i]) {
            ans[id] = min(ans[id], fen.qry(x));
        }
    }
    for(int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
}