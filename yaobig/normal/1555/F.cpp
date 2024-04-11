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
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 500000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

template<class T> struct BIT
{
    int n;
    T a[maxn+5];
    void init(int _n)
    {
        n=_n;
        rep(i,1,n) a[i]=0;
    }
    void add(int i,T x) {for(;i<=n;i+=i&-i) a[i]+=x;}
    T ask(int i)
    {
        T ans=0;
        for(;i;i-=i&-i) ans+=a[i];
        return ans;
    }
    void add(int l,int r,T x) {add(l,x); add(r+1,-x);}
    T ask(int l,int r) {return ask(r)-ask(l-1);}
};
BIT<int> bit;

int ps[maxn+5],dfn,tin[maxn+5],tout[maxn+5];

const int LG=20;
int dep[maxn+5],anc[maxn+5][LG];
vector<pii> e[maxn+5];

void dfs(int now,int fa)
{
    tin[now]=++dfn;
    dep[now]=dep[fa]+1; anc[now][0]=fa; rep(i,1,LG-1) anc[now][i]=anc[anc[now][i-1]][i-1];
    for(auto [v,w]: e[now]) if(v!=fa) 
    {
        ps[v] = ps[now] ^ w;
        dfs(v,now);
    }
    tout[now]=dfn;
}
int swim(int x,int h)
{
    rep(i,0,LG-1) if(h>>i&1) x=anc[x][i];
    return x;
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    x=swim(x,dep[x]-dep[y]);
    if(x==y) return x;
    per(i,0,LG-1) if(anc[x][i]!=anc[y][i]) x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

struct Union_Set
{
    array<int,maxn+5> fa,sz;
    void init(int n) 
    {
        rep(i,1,n) fa[i]=i,sz[i]=1;
    }
    int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
	bool check(int x,int y) {return getfa(x)==getfa(y);}
    void merge(int x,int y)
    {
        int fx=getfa(x),fy=getfa(y);
        if(sz[fx]<sz[fy]) swap(fx,fy);
        fa[fy]=fx;
        sz[fx]+=sz[fy];
    }
}us;

struct node {int u,v,w;};
node q[maxn+5];
int ans[maxn+5];

int main()
{
    int n,Q; scanf("%d%d",&n,&Q);
    us.init(n);
    rep(i,1,Q)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        q[i] = node{x,y,w};
        if(us.check(x,y)==0) 
        {
            us.merge(x,y);
            e[x].pb({y,w});
            e[y].pb({x,w});
            ans[i]=1;
        }
    }
    rep(i,1,n) if(dep[i]==0) dfs(i,0);
    bit.init(n);
    rep(qid,1,Q) if(ans[qid] == 0)
    {
        auto [u,v,w] = q[qid];
        if(ps[u]^ps[v]^w)
        {
            int l = lca(u,v);
            if(bit.ask(tin[u])+bit.ask(tin[v])-bit.ask(tin[l])*2==0)
            {
                ans[qid] = 1;
                auto chg = [&](int x) {
                    while(x!=l) bit.add(tin[x],tout[x],1), x=anc[x][0];
                };
                chg(u);
                chg(v);
            }
        }
    }
    rep(qid,1,Q) puts(ans[qid]?"YES":"NO");
    return 0;
}