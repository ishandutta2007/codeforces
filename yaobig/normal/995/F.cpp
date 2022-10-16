#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 3000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
 
int dp[maxn+5][maxn+5],C[maxn+5][maxn+5],inv[maxn+5];
vi e[maxn+5];
int n,D; 
void add(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

void dfs(int now,int fa)
{
    rep(i,1,n) dp[now][i]=1;
    for(auto v: e[now]) if(v!=fa)
    {
        dfs(v,now);
        rep(i,1,n) dp[now][i]=1ll*dp[now][i]*dp[v][i]%mod;
    }
    rep(i,1,n) add(dp[now][i],dp[now][i-1]);
}

int main()
{
    rep(i,0,maxn) C[i][0]=1;
    rep(i,1,maxn) rep(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    inv[1]=1;
    rep(i,2,maxn) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;

    scanf("%d%d",&n,&D);
    rep(i,2,n)
    {
        int x; scanf("%d",&x);
        e[x].pb(i);
    }
    dfs(1,0);
    rep(i,1,n) rep(j,1,i-1) add(dp[1][i],mod-1ll*dp[1][j]*C[i][j]%mod);
    //rep(now,1,n) rep(i,1,n) printf("? %d %d: %d\n",now,i,dp[now][i]);
    int ans=0,coef=1;
    rep(i,1,n) 
    {
        coef=1ll*coef*(D-i+1)%mod*inv[i]%mod;
        add(ans,1ll*coef*dp[1][i]%mod);
    }
    printf("%d\n",ans);
    return 0;
}