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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
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
const int maxn=605;
//const ll Mod=1000000007;
const ll Mod=998244353;


int dis[maxn][maxn];
int mp[maxn][maxn];
int f[maxn][maxn];
int c[maxn][maxn];
int fl[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            dis[i][j]=1e9+5;
            c[i][j]=-1e9;
        }
        dis[i][i]=0;
    }
    int u,v,w;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        dis[u][v]=min(dis[u][v],w);
        dis[v][u]=dis[u][v];
        mp[u][v]=mp[v][u]=w;
    }
    
    for(int k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
  
    
    int q;
    cin>>q;
    while(q--)
    {
        cin>>u>>v>>w;
        if(dis[u][v]>w)
            continue;
        for(i=1;i<=n;i++)
        {
            c[u][i]=max(c[u][i],w-dis[v][i]);
            fl[u]=1;
        }
    }
    
    for(int k=1;k<=n;k++)
    {
        if(fl[k])
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(mp[i][j])
                    {
                        if(dis[k][i]+mp[i][j]<=c[k][j])
                            f[i][j]=f[j][i]=1;
                    }
                }
            }
        }
    }
    
    
    int ans=0;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(f[i][j])
                ans++;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}