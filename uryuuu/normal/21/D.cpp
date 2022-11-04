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
typedef pair<int,ll> pil;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1000005;
const ll Mod=1000000007;
//const ll Mod=998244353;


ll d[maxn],dis[20][20],dp[maxn];

int main()
{
    sync;
    int n,m,j,u,v,i;
    ll w;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            dis[i][j]=inf;
        }
    }
    int ans=0;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        u--;
        v--;
        dis[u][v]=dis[v][u]=min(dis[u][v],w);
        d[u]++;
        d[v]++;
        ans+=w;
    }
    for(int k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(d[i]&&dis[0][i]==inf)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    ll up=(1<<n)-1;
    for(int i=0;i<=up;i++)
        dp[i]=inf;
    dp[0]=0;
    for(int k=0;k<=up;k++)
    {
        for(i=0;i<n;i++)
        {
            if(d[i]%2&&(k&(1<<i)))
                break;
        }
        if(i==n)
            dp[k]=0;
        for(i=0;i<n;i++)
        {
            if(d[i]%2&&(k&(1<<i))==0)
                for(j=i+1;j<n;j++)
                {
                    if(d[j]%2&&(k&(1<<j))==0&&dis[i][j]<inf)
                        dp[k|(1<<i)|(1<<j)]=min(dp[k|(1<<i)|(1<<j)],dp[k]+dis[i][j]);
                        
                }
        }
    }
    if(dp[up]<inf)
        cout<<ans+dp[up]<<endl;
    else
        cout<<-1<<endl;
    return 0;
}