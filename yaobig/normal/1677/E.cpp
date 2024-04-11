#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) {a = b; return 1;} return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) {a = b; return 1;} return 0; }
using namespace std;

string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1,c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }
template<class A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
// using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

template<class T, int maxn> struct SparseTable
{
    T st[__lg(maxn) + 1][maxn + 5];
    void init(int n, T a[]) // index starts from 1.
    {
        rep(i,1,n) st[0][i] = a[i];
        rep(i,1,__lg(n)) rep(j,1,n-(1<<i)+1) st[i][j] = max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
    }
    T ask(int l, int r)
    {
        int k = __lg(r-l+1);
        return max(st[k][l], st[k][r-(1<<k)+1]);
    }
};

template<class T, int maxn> struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<T, maxn*4+5> a,lz;
    void push(int i, int l, int r, T x)
    {
        a[i] += x * (r - l + 1);
        lz[i] += x;
    }
    void pu(int i) {a[i] = a[ls] + a[rs];}
    void pd(int i, int l, int r)
    {
        if(lz[i])
        {
            int mid = (l+r)>>1;
            push(ls, l, mid, lz[i]);
            push(rs, mid + 1, r, lz[i]);
            lz[i] = 0;
        }
    }
    void build(int i, int l, int r)
    {
        lz[i] = 0;
        if(l == r) a[i] = 0;
        else
        {
            int mid = (l+r)>>1;
            build(ls, l, mid);
            build(rs, mid + 1, r);
            pu(i);
        }
    }
    void add(int i,int l,int r,int ql,int qr,T x)
    {
        if(ql <= l && r <= qr)
        {
            push(i, l, r, x);
            return;
        }
        if(qr < l || r < ql) return;
        int mid = (l+r)>>1;
        pd(i,l,r);
        add(ls, l, mid, ql, qr, x);
        add(rs, mid+1, r, ql, qr, x);
        pu(i);
    }
    T ask(int i,int l,int r,int ql,int qr)
    {
        if(ql <= l && r <= qr) return a[i];
        if(qr < l || r < ql) return 0;
        int mid = (l+r)>>1;
        pd(i, l, r);
        return ask(ls, l, mid, ql, qr) + ask(rs, mid + 1, r, ql, qr);
    }
    #undef ls
    #undef rs
};

int main()
{
    int n, q; scanf("%d%d",&n,&q);
    static int a[maxn+5];
    rep(i,1,n) scanf("%d",&a[i]);
    static pii b[maxn+5];
    rep(i,1,n) b[i] = {a[i], i};
    
    static SparseTable<pii, maxn> st;
    st.init(n, b);
    
    vi pos(n+5);
    static vi fac[maxn+5];
    rep(i,1,n) pos[a[i]] = i;
    rep(i,1,n) for(int j = i; j <= n; j += i) fac[j].pb(i);

    struct node {int l, r, x;};
    vector<node> pool[maxn+5];

    function<void(int, int)> build = [&](int l, int r)
    {
        if(l > r) return;
        auto [val, i] = st.ask(l, r);
        build(l, i - 1);
        build(i + 1, r);
        vector<pii> vec;
        for(auto x: fac[val])
        {
            int y = val / x;
            int j = pos[x], k = pos[y];
            if(j < k && l <= j && j <= r && l <= k && k <= r) vec.pb({min(j, i), max(k, i)});
        }
        sort(all(vec));
        vector<pii> tmp; swap(vec, tmp);
        for(auto [x, y]: tmp) 
        {
            while(sz(vec) && vec.back().SE >= y) vec.pop_back();
            if(sz(vec) == 0 || vec.back().FI < x) vec.pb({x, y});
        }
        int last = l;
        for(auto [x, y]: vec) 
        {
            pool[y].pb(node{last, x, 1});
            pool[r + 1].pb(node{last, x, -1});
            last = x + 1;
            // debug(i, l, x, y, r);
        }
    };
    build(1, n);

    static vector<pii> qpool[maxn+5];
    static vector<ll> ans(q + 1);
    rep(i,1,q)
    {
        int l,r; scanf("%d%d",&l,&r);
        qpool[r].pb({l,i});
    }

    static Segtree<ll, maxn> K, B;
    K.build(1, 1, n);
    B.build(1, 1, n);
    rep(y,1,n)
    {
        for(auto [l, r, val]: pool[y]) K.add(1, 1, n, l, r, val), B.add(1, 1, n, l, r, -(y-1) * val);
        for(auto [l, id]: qpool[y]) ans[id] = K.ask(1, 1, n, l, n) * y + B.ask(1, 1, n, l, n);
    }
    rep(i,1,q) printf("%lld\n", ans[i]);
    return 0;
}