#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=100010;
//const ll Mod=1000000007;
const ll Mod=998244353;

struct node
{
    int v,nxt;
}e[maxn<<1];
int head[maxn],tot=0;
inline void Add(int u,int v)
{
    e[tot].v=v;
    e[tot].nxt=head[u];
    head[u]=tot++;
}
int fa[maxn],dep[maxn],siz[maxn],hson[maxn],dfn[maxn],low[maxn],top[maxn],tim;

void dfs1(int u,int ff)
{
    fa[u]=ff;
    dep[u]=dep[ff]+1;
    siz[u]=1;
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==ff)
            continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[hson[u]])   //
            hson[u]=v;
    }
}

void dfs2(int u,int tp)
{
    top[u]=tp;
    dfn[u]=++tim;
    if(hson[u])
        dfs2(hson[u],tp);
    for(int i=head[u];i!=-1;i=e[i].nxt)
        if(e[i].v!=fa[u]&&e[i].v!=hson[u])
            dfs2(e[i].v,e[i].v);
    low[u]=tim;
}

int LCA(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]])
            v=fa[top[v]];
        else
            u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}

int p[maxn<<1],S[maxn];

bool cmp(int a,int b)
{
    return dfn[a]<dfn[b];
}

int f[maxn],g[maxn],n,q,k;
bool FL=0,vis[maxn];

void DP(int u)
{
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int v=e[i].v;DP(v);
        f[u]+=f[v];
        g[u]+=g[v];
    }
    if(vis[u])
    {
        f[u]+=g[u];
        g[u]=1;
    }
    else
    {
        f[u]+=(g[u]>1);
        g[u]=(g[u]==1);
    }
}

int Calc(int rt)
{
    DP(rt);
    for(int i=1;i<=k;++i)
        if(vis[p[i]]&&vis[fa[p[i]]])
            return -1;
    return f[rt];
}

int main()
{
    sync;
    cin>>n;
    int u,v;
    memset(head,-1,sizeof(head));
    tot=0;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        Add(u,v);
        Add(v,u);
    }
    dfs1(1,0);
    dfs2(1,1);
    memset(head,-1,sizeof(head));
    cin>>q;
    while(q--)
    {
        cin>>k;
        tot=0;
        for(int i=1;i<=k;++i)
        {
            cin>>p[i];
            vis[p[i]]=1;
        }
        sort(p+1,p+k+1,cmp);
        for(int i=k;i>1;--i)
            p[++k]=LCA(p[i],p[i-1]);
        sort(p+1,p+k+1,cmp);
        k=unique(p+1,p+k+1)-p-1;
        for(int i=1,tp=0;i<=k;++i)
        {
            while(tp&&low[S[tp]]<dfn[p[i]])
                tp--;
            Add(S[tp],p[i]);
            S[++tp]=p[i];
        }
        cout<<Calc(p[1])<<endl;
        for(int i=1;i<=k;++i)
        {
            head[p[i]]=-1;
            vis[p[i]]=0;
            f[p[i]]=g[p[i]]=0;
        }
    }
    return 0;
}