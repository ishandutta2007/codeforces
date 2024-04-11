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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef double db;

ll ans;
int dp[maxn+5][20],n;
vi e[maxn+5];

inline void upd(int &x,int y) {if(x<y) x=y;}

int dfs(int now,int fa)
{
    int mxdep=0;
    for(auto v: e[now]) if(v!=fa) upd(mxdep,dfs(v,now));
    mxdep++; ans+=mxdep;
    dp[now][1]=n;
    rep(m,2,19)
    {
        vi tmp;
        for(auto v: e[now]) if(v!=fa) tmp.pb(dp[v][m-1]);
        sort(tmp.begin(),tmp.end(),greater<int>());
        int t=1;
        while(t<=(int)tmp.size() && tmp[t-1]>=t) t++;
        dp[now][m]=t-1;
        upd(dp[now][m],1);
    } 
    return mxdep;
}
void dfs2(int now,int fa)
{
    for(auto v: e[now]) if(v!=fa) 
    {
        dfs2(v,now); 
        rep(m,1,19) upd(dp[now][m],dp[v][m]);
    }
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0);
    dfs2(1,0);
    rep(now,1,n) rep(m,1,18) ans+=1ll*m*(dp[now][m]-dp[now][m+1]);
    printf("%lld\n",ans);
    return 0;
}