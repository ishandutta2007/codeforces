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
const int maxn=100005;
//const ll Mod=1000000007;
const ll Mod=998244353;

vector<int>g[maxn];
int tag[maxn];
int vis[maxn],dis[maxn];
int n;
int L[maxn],R[maxn];

void dfs(int u)
{
    if(u==n)
        return;
    for(int v:g[u])
    {
        if(vis[v]==0)
        {
            vis[v]=1;
            dfs(v);
        }
        if(tag[v])
            tag[u]=1;
    }
}

struct node
{
    int u,v,w;
}e[maxn];

int main()
{
    sync;
    int m;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        L[i]=u;
        R[i]=v;
    }
    tag[n]=1;
    dfs(1);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        if(tag[L[i]]&&tag[R[i]])
        {
            e[++cnt].u=L[i];
            e[cnt].v=R[i];
            e[cnt].w=2;
            e[++cnt].u=R[i];
            e[cnt].v=L[i];
            e[cnt].w=-1;
        }
    }
    memset(dis,inf,sizeof(dis));
    dis[1]=0;
    int w,j;
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=cnt;j++)
        {
            u=e[j].u;v=e[j].v;w=e[j].w;
            dis[v]=min(dis[v],dis[u]+w);
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        if(dis[e[i].u]+e[i].w<dis[e[i].v])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=m;i++)
    {
        if(tag[L[i]]&&tag[R[i]])
        {
            cout<<dis[R[i]]-dis[L[i]]<<endl;
        }
        else
            cout<<1<<endl;
    }
    
    return 0;
}