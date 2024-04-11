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
//const ll Mod=1000000007;
//const ll Mod=998244353;

int n,m;
vector<pii>g[maxn];
vector<int>h[maxn];
struct node
{
    int u,v;
}e[maxn];
int vis[maxn],dep[maxn],vise[maxn];
int low[maxn];
int cut[maxn];

void dfs(int u,int fa)
{
    vis[u]=1;
    dep[u]=dep[fa]+1;
    int v,id;
    for(auto f:g[u])
    {
        v=f.first;
        id=f.second;
        if(v==fa)
            continue;
        if(vis[v]==0)
        {
            dfs(v,u);
            vise[id]=1;
            h[u].push_back(v);
            h[v].push_back(u);
        }
        else if(dep[u]>dep[v])
        {
            low[u]=min(low[u],dep[v]);
        }
    }
}

void dfs2(int u,int fa)
{
    for(int v:h[u])
    {
        if(v==fa)
            continue;
        dfs2(v,u);
        low[u]=min(low[v],low[u]);
    }
    if(fa!=0&&low[u]>=dep[u])
        cut[u]=1;
}

int main()
{
    sync;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(mkp(v,i));
        g[v].push_back(mkp(u,i));
        e[i].u=u;
        e[i].v=v;
    }
    for(int i=1;i<=n;i++)
    {
        low[i]=n;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,0);
            dfs2(i,0);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(cut[i])
        {
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        u=e[i].u;
        v=e[i].v;
        if(dep[u]>dep[v])
            swap(u,v);
        if(vise[i]==0)
            swap(u,v);
        cout<<u<<' '<<v<<endl;
    }
    
    
    return 0;
}