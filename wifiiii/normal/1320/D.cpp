#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fpow(ll a,ll b,ll mod){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
const int p[2] = {223333333, 773333333};
const int mod[2] = {1000000033, 1000002233};
int inv[2] = {0, 0};
vector<ll> pw[2];
struct segtree {
    struct node {
        int lc = 0, rc = 0, len = 0;
        ll h[2] = {0, 0};
        void upd(int l, int r) {

        }
    };
    node merge(const node &x, const node &y) {
        node ret;
        if(x.len == 0) return y;
        if(y.len == 0) return x;
        ret.len = x.len + y.len;
        ret.lc = x.lc;
        ret.rc = y.rc;
        if(x.rc && y.lc) {
            ret.len -= 2;
            if(x.len == 1) ret.lc = 0;
            if(y.len == 1) ret.rc = 0;
            if(ret.len == 0) return ret;
        }
        for(int i = 0; i < 2; ++i) {
            ll xh = x.h[i], yh = y.h[i];
            if(x.rc && y.lc) {
                xh = (xh - 2) * inv[i] % mod[i];
                yh = yh - 2 * pw[i][y.len - 1];
            }
            ret.h[i] = ((xh * pw[i][y.len - (x.rc && y.lc)] % mod[i] + yh) % mod[i] + mod[i]) % mod[i];
        }
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
            a[rt].h[0] = a[rt].h[1] = v[l] + 1;
            a[rt].lc = a[rt].rc = v[l];
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
    int n;
    cin >> n;
    inv[0] = fpow(p[0], mod[0]-2, mod[0]);
    inv[1] = fpow(p[1], mod[1]-2, mod[1]);
    pw[0].resize(n+1);pw[1].resize(n+1);
    pw[0][0]=pw[1][0]=1;
    for(int i=1;i<=n;++i) pw[0][i]=pw[0][i-1]*p[0]%mod[0],pw[1][i]=pw[1][i-1]*p[1]%mod[1];
    string s;
    cin >> s;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) a[i] = s[i] - '0';
    segtree st(a);
    int q;
    cin >> q;
    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r;
        auto ans1 = st.qry(l, l + x - 1), ans2 = st.qry(r, r + x - 1);
        if(ans1.h[0] == ans2.h[0] && ans1.h[1] == ans2.h[1]) cout << "Yes\n";
        else cout << "No\n";
    }
}