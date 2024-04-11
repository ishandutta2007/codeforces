#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if(b<a) {a=b; return 1;} return 0;}
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

const int maxn = 600'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

vi e[maxn+5];

template<const int maxn> struct Union_Set
{
    array<int,maxn+5> fa;
    int tot = 0;
    void init(int n) 
    {
        rep(i,1,n*2) fa[i] = i;
        tot = n;
    }
    int getfa(int x) {return fa[x]==x ? x : fa[x]=getfa(fa[x]);}
    bool check(int x,int y) {return getfa(x)!=getfa(y);}
    bool merge(int x,int y)
    {
        int fx = getfa(x), fy = getfa(y);
        if(fx==fy) return 0;
        tot++;
        e[tot].pb(fx); fa[fx] = tot;
        e[tot].pb(fy); fa[fy] = tot;
        return 1;
    }
};
Union_Set<maxn+5> us;

template<class T,const T INF,const int maxn> struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<T,maxn*4+5> a;
    array<int,maxn*4+5> id;
    void pu(int i) 
    {
        a[i] = max(a[ls],a[rs]);
        if(a[i]==a[ls]) id[i] = id[ls];
        else id[i] = id[rs];
    }
    void build(int i,int l,int r,T *vec)
    {
        if(l==r) 
        {
            a[i] = vec[l];
            id[i] = l;
        }
        else
        {
            int mid = (l+r)>>1;
            build(ls,l,mid,vec);
            build(rs,mid+1,r,vec);
            pu(i);
        }
    }
    void upd(int i,int l,int r,int ql,int qr,T x)
    {
        if(ql<=l && r<=qr)
        {
            a[i] = x;
            return;
        }
        if(qr<l || r<ql) return;
        int mid = (l+r)>>1;
        upd(ls,l,mid,ql,qr,x);
        upd(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    pair<T,int> ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return pair<T,int>{a[i],id[i]};
        if(qr<l || r<ql) return pair<T,int>{INF,-1};
        int mid = (l+r)>>1;
        auto resl = ask(ls,l,mid,ql,qr);
        auto resr = ask(rs,mid+1,r,ql,qr);
        if(resl.FI>=resr.FI) return resl;
        else return resr;
    }
    #undef ls
    #undef rs
};
Segtree<int,-inf,maxn> seg;

int main()
{
    int n,m,Q; scanf("%d%d%d",&n,&m,&Q);
    static int a[maxn+5];
    static pii ed[maxn+5];
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,m) scanf("%d%d",&ed[i].FI,&ed[i].SE);
    vector<pii> q(Q);
    for(auto &[op,x]: q) scanf("%d%d",&op,&x);
    static int ban[maxn+5];
    for(auto [op,x]: q) if(op==2) ban[x] = 1;
    us.init(n);
    rep(i,1,m) if(ban[i]==0) us.merge(ed[i].FI,ed[i].SE);
    per(i,0,Q-1)
    {
        auto &[op,x] = q[i];
        if(op==2) us.merge(ed[x].FI,ed[x].SE);
        else x = us.getfa(x);
    }

    static int tin[maxn+5],tout[maxn+5];
    int dfn = 0;
    function<void(int)> dfs = [&](int now) {
        tin[now] = ++dfn;
        for(auto v: e[now]) dfs(v);
        tout[now] = dfn;
    };
    int N = us.tot;
    rep(i,1,N) if(us.getfa(i)==i) dfs(i);

    static int vec[maxn+5];
    rep(i,1,n) vec[tin[i]] = a[i];
    seg.build(1,1,N,vec);
    for(auto [op,now]: q) if(op==1)
    {
        int l = tin[now], r = tout[now];
        auto [val,pos] = seg.ask(1,1,N,l,r);
        printf("%d\n",val);
        seg.upd(1,1,N,pos,pos,0);
    }
    return 0;
}