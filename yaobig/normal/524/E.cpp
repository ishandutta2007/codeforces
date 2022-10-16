#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template<typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template<typename A> string to_string(A v) 
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

void debug_out() {cerr << endl;} 
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

template<class T> struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<T,maxn*4+5> a;
    void pu(int i) { a[i] = min(a[ls],a[rs]); }
    void build(int i,int l,int r)
    {
        if(l==r) a[i] = 0;
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    void upd(int i,int l,int r,int ql,int qr,const T &x)
    {
        if(ql<=l && r<=qr)
        {
            a[i] = x;
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        upd(ls,l,mid,ql,qr,x);
        upd(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    T ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return a[i];
        if(qr<l || r<ql) return inf;
        int mid=(l+r)>>1;
        return min(ask(ls,l,mid,ql,qr),ask(rs,mid+1,r,ql,qr));
    }
    #undef ls
    #undef rs
};
Segtree<int> seg;

const int MAXQ = 200000;

int main()
{
    static int x[MAXQ+5],y[MAXQ+5];
    static int x1[MAXQ+5],y1[MAXQ+5],x2[MAXQ+5],y2[MAXQ+5];
    
    int n,m,k,q; scanf("%d%d%d%d",&n,&m,&k,&q);
    rep(i,1,k) scanf("%d%d",&x[i],&y[i]);
    rep(i,1,q) scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    
    static int ans[MAXQ+5];
    auto solve = [&](int n,int m) {
        static vi pool[maxn+5],qpool[maxn+5];
        rep(i,1,m) pool[i].clear();
        rep(i,1,m) qpool[i].clear();
        rep(i,1,k) pool[y[i]].pb(i);
        rep(i,1,q) qpool[y2[i]].pb(i);
        seg.build(1,1,n);
        rep(Y,1,m) 
        {
            for(auto id: pool[Y]) seg.upd(1,1,n,x[id],x[id],Y);
            for(auto id: qpool[Y]) ans[id] |= seg.ask(1,1,n,x1[id],x2[id])>=y1[id];
        }
    };
    solve(n,m);
    rep(i,1,k) swap(x[i],y[i]);
    rep(i,1,q) swap(x1[i],y1[i]), swap(x2[i],y2[i]);
    solve(m,n);
    rep(i,1,q) puts(ans[i]?"YES":"NO");
    return 0;
}