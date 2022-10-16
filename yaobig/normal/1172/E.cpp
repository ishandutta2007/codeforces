#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 400000
#define mod 1000000007
#define inf 0x3f3f3f3f
#define ls(x) son[x][0]
#define rs(x) son[x][1]
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct LCT
{
    int fa[maxn+5],son[maxn+5][2],sz[maxn+5],vsz[maxn+5];
    ll sz2[maxn+5],vsz2[maxn+5];
    bool rev[maxn+5];
    int q[maxn+5],top;
    void out(int n)
    {
        rep(i,1,n) printf("%d: fa %d, ls %d, rs %d, rev %d\n",i,fa[i],ls(i),rs(i),rev[i]);
    }
    void init(int n)
    {
        sz[0]=vsz[0]=0;
        sz2[0]=vsz2[0]=0;
		rep(i,1,n) rev[i]=0;
        rep(i,1,n) sz[i]=1;
        rep(i,1,n) vsz[i]=0;
        rep(i,1,n) sz2[i]=0;
        rep(i,1,n) vsz2[i]=0;
        rep(i,1,n) fa[i]=son[i][0]=son[i][1]=0;
    }
    bool isrt(int x)
    {
        return ls(fa[x])!=x && rs(fa[x])!=x;
    }
    void pushup(int x)
    {
        sz[x]=sz[ls(x)]+sz[rs(x)]+1+vsz[x];
        sz2[x]=1ll*sz[ls(x)]*sz[ls(x)]+1ll*sz[rs(x)]*sz[rs(x)]+vsz2[x];
    }
    void pushdown(int x)
    {
        if(!rev[x]) return;
        rev[x]=0;
        rev[ls(x)]^=1;
        rev[rs(x)]^=1;
        swap(ls(x),rs(x));
    }
    void rot(int x)
    {
        int y=fa[x],z=fa[y];
        int l=rs(y)==x,r=l^1;
        if(!isrt(y)) son[z][rs(z)==y]=x;
        fa[son[x][r]]=y;
        fa[y]=x;fa[x]=z;
        son[y][l]=son[x][r];son[x][r]=y;
        pushup(y);
    }
    void splay(int x)
    {
        q[++top]=x;
        for(int i=x;!isrt(i);i=fa[i]) q[++top]=fa[i];
        while(top) pushdown(q[top--]);
        while(!isrt(x))
        {
            int y=fa[x],z=fa[y];
            if(!isrt(y))
            {
                if(ls(y)==x ^ ls(z)==y) rot(x);
                else rot(y);
            }
            rot(x);
        }
        pushup(x);
    }
    void access(int x)
    {
        for(int l=0;x;l=x,x=fa[x])
        {
            splay(x);
            vsz[x]+=sz[rs(x)]-sz[l];
            vsz2[x]+=1ll*sz[rs(x)]*sz[rs(x)]-1ll*sz[l]*sz[l];
            rs(x)=l;pushup(x);
        }
    }
    void reroot(int x)
    {
        access(x);splay(x);rev[x]^=1;
    }
    int findrt(int x)
    {
        access(x);
        splay(x);
        while(pushdown(x),ls(x)) x=ls(x);
        return x;
    }
    void link(int x,int y)
    {
        reroot(x);fa[x]=y;
        int t=findrt(y);
        reroot(y);vsz[y]+=sz[x];vsz2[y]+=1ll*sz[x]*sz[x];
        pushup(y);
        reroot(t);
    }
    int cut(int x,int y)
    {
        reroot(x);access(y);splay(y);
        int l=ls(y);
        ls(y)=fa[l]=0;
        pushup(y);
        while(pushdown(l),rs(l)) l=rs(l);
        return l;
    }
}lct;

struct node
{
    int t,u,op;
    node(){}
    node(int a,int b,int c):t(a),u(b),op(c){}
};

vi e[maxn+5];
vector<node> q[maxn+5];
ll ans[maxn+5];
int c[maxn+5],fa[maxn+5];
void dfs(int now,int f)
{
    fa[now]=f;
    for(auto v: e[now]) if(v!=f) dfs(v,now);
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&c[i]);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    rep(i,1,n) q[c[i]].pb(node(0,i,0));
    rep(i,1,m)
    {
        int u,x; scanf("%d%d",&u,&x);
        q[c[u]].pb(node(i,u,1));
        q[c[u]=x].pb(node(i,u,0));
    }
    rep(i,1,n) q[c[i]].pb(node(m+1,i,1));
    dfs(1,n+1);
    lct.init(n+1);
    rep(i,1,n) lct.link(i,fa[i]);
    rep(cl,1,n)
    {
        for(auto it: q[cl])
        {
            int t=it.t,u=it.u,rt=lct.findrt(fa[u]);
            //printf("-- %d, %d: %d, %d\n",cl,t,u,rt);
            if(it.op)
            {
                lct.reroot(u);
                lct.reroot(rt);
                ans[t]+=lct.sz2[u]+lct.sz2[rt];
                //printf("+ %I64d %I64d\n",lct.sz2[u],lct.sz2[rt]);
                lct.link(u,fa[u]);
                lct.reroot(rt);
                ans[t]-=lct.sz2[rt];
                //printf("- %I64d\n",lct.sz2[rt]);
                //printf("?? %d %d: %I64d\n",t,u,ans[t]);
            }
            else
            {
                lct.reroot(rt);
                ans[t]+=lct.sz2[rt];
                //printf("+ %I64d\n",lct.sz2[rt]);
                lct.cut(u,fa[u]);
                lct.reroot(u);
                lct.reroot(rt);
                ans[t]-=lct.sz2[u]+lct.sz2[rt];
                //printf("- %I64d %I64d\n",lct.sz2[u],lct.sz2[rt]);
                //printf("!! %d %d: %I64d\n",t,u,ans[t]);
            }
        }
    }
    rep(i,1,m) ans[i]+=ans[i-1];
    rep(i,0,m) printf("%I64d\n",ans[i]);
    return 0;
}