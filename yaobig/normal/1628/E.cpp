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

const int maxn = 300000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

struct edge {int u,v,w;};

namespace KruskalTree
{
    const int MAXN = maxn*2; 
    array<int,MAXN+5> fa,W;
    vi e[MAXN+5];
    int tot;
    int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
    void build(int n,vector<edge> E)
    {   // E should be an edge set of a tree.
        rep(i,1,n*2-1) fa[i] = i;
        rep(i,1,n*2-1) e[i].clear();
        tot = n;
        sort(all(E),[](const edge &a,const edge &b){return a.w<b.w;});
        for(auto [u,v,w]: E)
        {
            W[++tot] = w;
            u = getfa(u); fa[u] = tot; e[tot].pb(u);
            v = getfa(v); fa[v] = tot; e[tot].pb(v);
        }
    }
}
using KruskalTree::e;
using KruskalTree::W;

namespace HLD
{
    array<int,maxn*2+5> fa,sz,heavy,dfn,dep,top,id;
    int n,cnt;
    
    void dfs(int now)
    {
        sz[now] = 1;
        heavy[now] = -1;
        int mx=0;
        for(auto v: e[now]) if(dep[v]==0) 
        {
            dep[v] = dep[now]+1;
            fa[v] = now;
            dfs(v);
            sz[now] += sz[v];
            if(chmax(mx,sz[v])) heavy[now] = v;
        }
    }
    void getdfn(int now,int sp)
    {
        top[now] = sp;
        dfn[now] = ++cnt; id[cnt] = now;
        if(heavy[now]==-1) return;
        getdfn(heavy[now],sp);
        for(auto v: e[now]) if(v!=heavy[now] && v!=fa[now]) getdfn(v,v);
    }
    void init(int _n,int rt=1)
    {
        n = _n;
        rep(i,1,n) dep[i] = 0;
        dep[rt] = 1; cnt = 0;
        dfs(rt);
        getdfn(rt,rt);
    }
    int lca(int u,int v)
    {
        while(top[u]!=top[v])
        {
            if(dep[top[u]]<dep[top[v]]) swap(u,v);
            u=fa[top[u]];
        }
        if(dep[u]<dep[v]) return u;
        return v;
    }
}

struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<int,maxn*4+5> mx,mn,a,b,lz;
    void push(int i,int x)
    {
        lz[i] = x;
        if(x==1) mx[i] = a[i], mn[i] = b[i];
        else mx[i] = -inf, mn[i] = inf;
    }
    void pu(int i) 
    {
        mx[i] = max(mx[ls],mx[rs]);
        mn[i] = min(mn[ls],mn[rs]);
    }
    void pd(int i)
    {
        if(lz[i]!=-1)
        {
            push(ls,lz[i]);
            push(rs,lz[i]);
            lz[i] = -1;
        }
    }
    void build(int i,int l,int r,int *vec)
    {
        lz[i] = -1;
        if(l==r) 
        {
            a[i] = b[i] = vec[l];
            mx[i] = -inf; mn[i] = inf;
        }
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid,vec);
            build(rs,mid+1,r,vec);
            a[i] = max(a[ls],a[rs]);
            b[i] = min(b[ls],b[rs]);
            pu(i);
        }
    }
    void add(int i,int l,int r,int ql,int qr,const int &x)
    {
        if(ql<=l && r<=qr)
        {
            push(i,x);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        pd(i);
        add(ls,l,mid,ql,qr,x);
        add(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    #undef ls
    #undef rs
}seg;

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    vector<edge> E;
    rep(i,1,n-1)
    {
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        E.pb(edge{u,v,w});
    }
    KruskalTree::build(n,E);
    HLD::init(n*2-1,n*2-1);
    using HLD::id;
    static int dfn[maxn+5];
    rep(i,1,n) dfn[i] = HLD::dfn[i];
    seg.build(1,1,n,dfn);
    while(q--)
    {
        int op; scanf("%d",&op);
        if(op==1 || op==2)
        {
            int l,r; scanf("%d%d",&l,&r);
            seg.add(1,1,n,l,r,2-op);
        }
        else
        {
            int v; scanf("%d",&v);
            int mx = seg.mx[1];
            int mn = seg.mn[1];
            chmax(mx,dfn[v]);
            chmin(mn,dfn[v]);
            if(mx==mn) puts("-1");
            else
            {
                int x = id[mn], y = id[mx];
                int z = HLD::lca(x,y);
                printf("%d\n",W[z]);
            }
        }
    }
    return 0;
}