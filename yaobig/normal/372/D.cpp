#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];

struct Segtree
{
    #define ls i*2
    #define rs i*2+1
    array<int,maxn*4+5> a,lz;
    void push(int i,int l,int r,int x)
    {
        lz[i]+=x;
        a[i]=lz[i]?r-l+1:l==r?0:a[ls]+a[rs];
    }
    void pu(int i,int l,int r) {a[i]=lz[i]?r-l+1:a[ls]+a[rs];}
    void build(int i,int l,int r)
    {
        lz[i]=0;
        if(l==r) a[i]=0;
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i,l,r);
        }
    }
    void add(int i,int l,int r,int ql,int qr,int x)
    {
        if(ql<=l && r<=qr)
        {
            push(i,l,r,x);
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        add(ls,l,mid,ql,qr,x);
        add(rs,mid+1,r,ql,qr,x);
        pu(i,l,r);
    }
    int ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return a[i];
        if(qr<l || r<ql) return 0;
        int mid=(l+r)>>1;
        return ask(ls,l,mid,ql,qr)+ask(rs,mid+1,r,ql,qr);
    }
    #undef ls
    #undef rs
}seg;

struct HLD
{
	array<int,maxn+5> fa,sz,heavy,id,dep,top;
    int n,cnt;
    
    void dfs(int now)
    {
        sz[now]=1;
        heavy[now]=-1;
        int mx=0;
        for(auto v: e[now]) if(dep[v]==0) 
        {
            dep[v]=dep[now]+1;
            fa[v]=now;
            dfs(v);
            sz[now]+=sz[v];
            if(chmax(mx,sz[v])) heavy[now]=v;
        }
    }
    void getid(int now,int sp)
    {
        top[now]=sp;
        id[now]=++cnt;
        if(heavy[now]==-1) return;
        getid(heavy[now],sp);
        for(auto v: e[now]) 
        {
            if(v==heavy[now] || v==fa[now]) continue;
            getid(v,v);
        }
        return;
    }
    void init(int _n)
    {
		n=_n;
        rep(i,1,n) dep[i]=0;
        dep[1]=1; cnt=0;
        dfs(1);
        getid(1,1);
		seg.build(1,1,n);
    }
    void add(int u,int x)
    {
        int f=top[u];
        while(f!=1)
        {
            seg.add(1,1,n,id[f],id[u],x);
            u=fa[f]; f=top[u];
        }
        if(u==1) return;
        seg.add(1,1,n,id[heavy[1]],id[u],x);
        return;
    }
}hld;

int dep[maxn+5];

struct Euler_order
{
    #define LG 18
    array<int,maxn+5> in;
    array<int,maxn*2+5> a,lg;
    int tot;
    pii st[LG][maxn*2+5];
    void dfs(int now,int fa)
    {
        dep[now]=dep[fa]+1;
        a[++tot]=now; in[now]=tot; 
        for(auto v: e[now]) if(v!=fa) {dfs(v,now); a[++tot]=now;}
    }
    void init(int n)
    {
        int N=n*2-1;
        rep(i,2,N) lg[i]=lg[i>>1]+1;
        tot=0;
        dfs(1,0);
        rep(i,1,N) st[0][i]={in[a[i]],a[i]};
        rep(i,1,lg[N]) rep(j,1,N-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
    int lca(int u,int v) // ask the lca of vertices u and v. 
    {
        int l=in[u],r=in[v];
        if(l>r) swap(l,r);
        int k=lg[r-l+1];
        return min(st[k][l],st[k][r-(1<<k)+1]).SE;
    }
    #undef LG
}eu;

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    int L=1;
    hld.init(n);
    eu.init(n);
    set<pii> S;
    int ans=0;
    rep(R,1,n)
    {
        S.insert({eu.in[R],R});
        hld.add(R,1);
        while(L<=R)
        {
            int u=S.begin()->SE,v=S.rbegin()->SE;
            int lca=eu.lca(u,v);
            int sz=seg.a[1]-(dep[lca]-1)+1;
            if(sz<=k) break;
            S.erase({eu.in[L],L});
            hld.add(L,-1);
            L++;
        }
        chmax(ans,R-L+1);
    }
    printf("%d\n",ans);
    return 0;
}