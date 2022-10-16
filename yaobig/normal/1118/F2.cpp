#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi clr[maxn+5],e[maxn+5];
int dep[maxn+5],anc[20][maxn+5];

void getdep(int now,int fa)
{
    anc[0][now]=fa;
    dep[now]=dep[fa]+1;
    for(auto v: e[now]) if(v!=fa) getdep(v,now);
}

int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    int h=dep[x]-dep[y];
    rep(i,0,18) if(h&(1<<i)) x=anc[i][x];
    if(x==y) return x;
    per(i,0,18) if(anc[i][x]!=anc[i][y]) x=anc[i][x],y=anc[i][y];
    return anc[0][x];
}
int cnt[maxn+5],mark[maxn+5],dp[maxn+5][2];

void dfs(int now,int fa)
{
    dp[now][0]=1;
    for(auto v: e[now]) if(v!=fa)
    {
        dfs(v,now);
        cnt[now]+=cnt[v];
        vi tmp(2,0);
        tmp[0]=1ll*dp[now][0]*(dp[v][0]+dp[v][1])%mod;
        tmp[1]=(1ll*dp[now][0]*dp[v][1]+1ll*dp[now][1]*(dp[v][0]+dp[v][1]))%mod;
        dp[now][0]=tmp[0]; dp[now][1]=tmp[1];
    }
    if(mark[now]) {dp[now][1]=dp[now][0]; dp[now][0]=0;}
    if(cnt[now]) dp[now][1]=0;
}

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n) 
    {
        int x; scanf("%d",&x); if(x) clr[x].pb(i);
    }
    rep(i,2,n)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    getdep(1,0);
    rep(i,1,18) rep(now,1,n) anc[i][now]=anc[i-1][anc[i-1][now]];
    rep(c,1,k) 
    {
        assert(clr[c].size());
        int L=clr[c][0];
        for(auto now: clr[c]) L=lca(L,now);
        for(auto now: clr[c]) cnt[now]++,cnt[L]--;
        if(mark[L]) return puts("0"),0;
        mark[L]=1;
    }
    dfs(1,0);
    printf("%d\n",dp[1][1]);
    return 0;
}