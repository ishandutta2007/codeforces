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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res%Mod;
}

struct node
{
    int from,to,nxt,cut;
}e[maxn<<1];
int head[maxn],tot=0;
int dfn[maxn],low[maxn];
int dcc[maxn],siz[maxn];
int cnt=0;
vector<int>g[maxn];

inline void add(int u,int v)
{
    e[tot].cut=0;
    e[tot].from=u;
    e[tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot++;
}

void dfs(int u,int eid)
{
    low[u]=dfn[u]=++tot;
    int v;
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        v=e[i].to;
        if(dfn[v]==0)
        {
            dfs(v,i);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v])
            {
                e[i].cut=e[i^1].cut=1;
            }
        }
        else
        {
            if(i!=(eid^1))
                low[u]=min(low[u],dfn[v]);
        }
    }
}

void dfs1(int u,int id)
{
    dcc[u]=id;
    siz[id]++;
    int v;
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        v=e[i].to;
        if(dcc[v]||e[i].cut)
            continue;
        dfs1(v,id);
    }
}


int len[maxn];

int ma,root;
int d[maxn],anc[maxn][20];
inline void dfs2(int u,int dep,int fa)
{
    len[u]=len[fa];
    if(siz[u]>1)
        len[u]++;
    d[u]=dep;
    anc[u][0]=fa;
    ma=max(ma,dep);
    for(int i=0;i<g[u].size();i++)
        if(g[u][i]!= fa)
            dfs2(g[u][i],dep+1,u);
}
inline int log2(int x)
{
    int k=0;
    while(x>1)
    {
        x>>=1;
        k++;
    }
    return k;
}
inline void init()
{
    ma=0;
    dfs2(root, 0, 0);
    int s = log2(ma);
    for (int j = 1;j<= s;j++)
        for(int i = 1;i<=cnt;i++)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
// xyLCA
inline int lca(int x,int y)
{
    if(d[x]<d[y])
        swap(x, y);
    int s = log2(d[x] - d[y]);
    while(d[x]>d[y])
    {
        if(d[x]-(1<<s)>=d[y])
            x=anc[x][s];
        s--;
    }
    s=log2(d[x]);
    while(s>-1)
    {
        if (anc[x][s]!=anc[y][s])
        {
            x=anc[x][s];
            y=anc[y][s];
        }
        s--;
    }
    return x==y?x:anc[x][0];
}

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=n;i++)
        head[i]=-1;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0)
            dfs(i,0);
    }
    for(int i=1;i<=n;i++)
    {
        if(dcc[i]==0)
            dfs1(i,++cnt);
    }
    
    for(u=1;u<=n;u++)
    {
        for(int j=head[u];j!=-1;j=e[j].nxt)
        {
            v=e[j].to;
            if(dcc[u]!=dcc[v])
            {
                g[dcc[u]].push_back(dcc[v]);
            }
        }
    }
    root=1;
    init();
    int q;
    cin>>q;
    int Lca;
    for(int i=1;i<=q;i++)
    {
        cin>>u>>v;
        u=dcc[u];
        v=dcc[v];
        Lca=lca(u,v);
        cout<<ksm(2ll,len[u]+len[v]-len[Lca]*2+(siz[Lca]>1))<<endl;
    }
    return 0;
}