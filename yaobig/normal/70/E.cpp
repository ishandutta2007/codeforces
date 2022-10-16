#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int dp[maxn+5][maxn+5],best[maxn+5];
int dis[maxn+5][maxn+5];
int w[maxn+5];

vi e[maxn+5];

void caldis(int now,int fa,int rt)
{
    for(auto v: e[now]) if(v!=fa)
    {
        dis[rt][v]=dis[rt][now]+1;
        caldis(v,now,rt);
    }
}

int n,k; 
void dfs(int now,int fa)
{
    for(auto v: e[now]) if(v!=fa) dfs(v,now);
    rep(i,1,n) dp[now][i]=w[dis[now][i]];
    for(auto v: e[now]) if(v!=fa)
    {
        rep(i,1,n) dp[now][i]+=min(dp[v][i],dp[v][best[v]]+k);
    }
    best[now]=1;
    rep(i,2,n) if(dp[now][i]<dp[now][best[now]]) best[now]=i;
}

int ans[maxn+5];
void solve(int now,int fa,int chosen)
{
    ans[now]=chosen;
    for(auto v: e[now]) if(v!=fa)
    {
        if(dp[v][chosen]<dp[v][best[v]]+k) solve(v,now,chosen);
        else solve(v,now,best[v]);
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    rep(i,1,n-1) scanf("%d",&w[i]);
    rep(i,1,n-1)
    {
        int u,v; scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    rep(i,1,n) caldis(i,0,i);
    dfs(1,0);
    printf("%d\n",dp[1][best[1]]+k);
    solve(1,0,best[1]);
    rep(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}