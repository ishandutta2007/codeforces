#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int ll
struct segtree {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    struct node {
        ll sum = 0;
        ll lmn = 0, rmn = 0, lmx = 0, rmx = 0, mxx = 0, mnn = 0;
    };
    node merge(const node &x, const node &y) {
        node ret;
        ret.sum = x.sum + y.sum;
        ret.lmn = min(x.lmn, x.sum + y.lmn);
        ret.rmn = min(y.rmn, y.sum + x.rmn);
        ret.lmx = max(x.lmx, x.sum + y.lmx);
        ret.rmx = max(y.rmx, y.sum + x.rmx);
        ret.mxx = max(x.mxx, y.mxx);
        ret.mnn = min(x.mnn, y.mnn);
        ret.mxx = max(ret.mxx, ret.lmx);
        ret.mxx = max(ret.mxx, ret.rmx);
        ret.mnn = min(ret.mnn, ret.lmn);
        ret.mnn = min(ret.mnn, ret.rmn);
        ret.mxx = max(ret.mxx, x.rmx + y.lmx);
        ret.mnn = min(ret.mnn, x.rmn + y.lmn);
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
            a[rt].sum = v[l];
            a[rt].lmx = a[rt].rmx = a[rt].mxx = max(a[rt].mxx, v[l]);
            a[rt].lmn = a[rt].rmn = a[rt].mnn = min(a[rt].mnn, v[l]);
            return;
        }
        int m = (l + r) / 2;
        build(l, m, rt << 1, v);
        build(m + 1, r, rt << 1 | 1, v);
        a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
    }
    segtree(int n):n(n), a(n << 3) {
        build(0, n - 1, 1);
    }
    template <typename T>
    segtree(const vector<T> &v):n(v.size()), a(v.size() << 2) {
        build(0, n - 1, 1, v);
    }

    int n;
    vector<node> a;
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

int32_t main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i],a[i]=b[i]-a[i];
    segtree st(a);
    while(m--) {
        int l,r;
        cin>>l>>r;
        --l,--r;
        auto p=st.query(l,r);
        if(p.sum==0 && p.lmn>=0) cout<<max(p.mxx,-p.mnn)<<'\n';
        else cout<<-1<<'\n';
    }
}