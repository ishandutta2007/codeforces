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
const int maxn=50005;
//const ll Mod=1000000007;
//const ll Mod=998244353;


int vis[maxn],c[maxn];
int cnt=0;
int num[maxn],dis[maxn];
int len[30][30],dp[1<<22];
queue<int>q;
int n,m,k;

void spfa(int st)
{
    memset(dis,inf,sizeof(dis));
    dis[c[st]]=0;
    q.push(c[st]);
    int u,v;
    while(q.size())
    {
        u=q.front();
        q.pop();
        for(int i=1;i<=k;i++)
        {
            if(u+num[i]<=n+1&&dis[u+num[i]]>dis[u]+1)
            {
                dis[u+num[i]]=dis[u]+1;
                q.push(u+num[i]);
            }
            if(u-num[i]>0&&dis[u-num[i]]>dis[u]+1)
            {
                dis[u-num[i]]=dis[u]+1;
                q.push(u-num[i]);
            }
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        len[st][i]=dis[c[i]];
    }
}

int main()
{
    sync;
    cin>>n>>m>>k;
    int x;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        vis[x]=1;
    }
    cnt=0;
    for(int i=1;i<=n+1;i++)
    {
        if(vis[i]^vis[i-1])
            c[++cnt]=i;
    }
    if(cnt==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=k;i++)
        cin>>num[i];
    for(int i=1;i<=cnt;i++)
    {
        spfa(i);
    }

    memset(dp,inf,sizeof(dp));
    dp[0]=0;
    int u,j;
    for(int i=0;i<(1<<cnt);i++)
    {
        u=0;
        while((i>>u)&1ll)
            u++;
        for(j=u+1;j<cnt;j++)
        {
            if(((1<<j)&i)==0)
            {
                dp[i|(1<<u)|(1<<j)]=min(dp[i|(1<<u)|(1<<j)],dp[i]+len[u+1][j+1]);
            }
        }
    }
  
    if(dp[(1<<cnt)-1]==inf)
        cout<<-1<<endl;
    else
        cout<<dp[(1<<cnt)-1]<<endl;
    
    return 0;
}