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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=205;
//const ll Mod=1000000007;
const ll Mod=998244353;


int st[maxn],ed[maxn],dis[maxn][maxn],num[maxn],dp[maxn],pd[maxn];
int b[maxn][maxn];
int vis[maxn];
int T=0;
int n,m;

int dfs(int u,int k)
{
    if(vis[u]==T)
        return pd[u];
    int tmp=-1;
    vis[u]=T;
    for(int v=1;v<=n;v++)
    {
        if(dis[u][v]==1&&dis[u][ed[k]]==dis[v][ed[k]]+1)
        {
            tmp=max(tmp,dfs(v,k));
        }
    }
    if(tmp==-1)
        tmp=inf;
    if(tmp>dp[u])
        tmp=dp[u];
    return pd[u]=tmp;
}

int main()
{
    sync;
    cin>>n>>m>>st[0]>>ed[0];
    memset(dis,inf,sizeof(dis));
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        dis[u][v]=1;
    }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    
    int i,j;
    for(int k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int q;
    cin>>q;
    for(i=1;i<=q;i++)
    {
        mm(num);
        cin>>st[i]>>ed[i];
        if(dis[st[i]][ed[i]]==inf)
            continue;
        for(j=1;j<=n;j++)
        {
            if(dis[st[i]][j]+dis[j][ed[i]]==dis[st[i]][ed[i]])
            {
                num[dis[st[i]][j]]++;
            }
        }
        for(j=1;j<=n;j++)
        {
            if(dis[st[i]][j]+dis[j][ed[i]]==dis[st[i]][ed[i]])
            {
                if(num[dis[st[i]][j]]==1)
                    b[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=pd[i]=inf;
    }
    dp[ed[0]]=0;
    int fl=1;
    int res=0;
    while(fl)
    {
        fl=0;
        for(i=1;i<=q;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(b[i][j])
                {
                    T++;
                    res=dfs(j,i)+1;
                    if(res<dp[j])
                    {
                        fl=1;
                        dp[j]=res;
                    }
                }
            }
        }
    }
    if(dp[st[0]]==inf)
        dp[st[0]]=-1;
    cout<<dp[st[0]]<<endl;
    return 0;
}