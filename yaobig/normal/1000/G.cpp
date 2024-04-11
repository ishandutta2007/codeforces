#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int val[maxn+5];
vector<pii> e[maxn+5];

int anc[20][maxn+5];
ll upsum[20][maxn+5],upw[maxn+5];
ll dp1[maxn+5],dp2[maxn+5];
int dep[maxn+5];

void dfs1(int now,int fa)
{
    dep[now]=dep[fa]+1;
    dp1[now]=val[now];
    anc[0][now]=fa;
    for(auto [v,w]: e[now]) if(v!=fa)
    {
        dfs1(v,now);
        upw[v]=w;
        if(dp1[v]-2ll*w>0) dp1[now]+=dp1[v]-2ll*w;
    }
}
void dfs2(int now,int fa,ll x)
{
    dp2[now]=x;
    x+=dp1[now];
    for(auto [v,w]: e[now]) if(v!=fa)
    {
        ll z=dp1[v]-2ll*w; if(z<0) z=0;
        ll y=x-z-2ll*w; if(y<0) y=0;
        dfs2(v,now,y);
    }
}

ll cal(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    ll ans=0;
    int h=dep[x]-dep[y];
    rep(i,0,18) if(h&(1<<i))
    {
        ans+=upsum[i][x];
        x=anc[i][x];
    }
    if(x==y) return ans+dp1[x]+dp2[x];
    per(i,0,18) if(anc[i][x]!=anc[i][y])
    {
        ans+=upsum[i][x]+upsum[i][y];
        x=anc[i][x]; y=anc[i][y];
    }
    ans+=upsum[0][x]+upsum[0][y];
    x=anc[0][x];
    return ans+dp1[x]+dp2[x];
}

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&val[i]);
    rep(i,1,n-1)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        e[x].pb({y,w});
        e[y].pb({x,w});
    }
    dfs1(1,0);
    dfs2(1,0,0);
    rep(i,1,n) upsum[0][i]=dp1[i]-upw[i]-(dp1[i]-2*upw[i]>0?dp1[i]-2*upw[i]:0);
    rep(j,1,18) rep(i,1,n) 
    {
        anc[j][i]=anc[j-1][anc[j-1][i]];
        upsum[j][i]=upsum[j-1][i]+upsum[j-1][anc[j-1][i]];
    }
    while(q--)
    {
        int x,y; scanf("%d%d",&x,&y);
        printf("%lld\n",cal(x,y));
    }
    return 0;
}