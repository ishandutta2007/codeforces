#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int mod;
ll inv[20];

void add(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

ll binom(int n,int m)
{
    ll res=1;
    rep(i,1,m) res=res*(n-i+1)%mod*inv[i]%mod;
    return res;
}

int dp[maxn+5][12][maxn+5],g[maxn+5][12];

int main()
{
    int n,d; scanf("%d%d%d",&n,&d,&mod);
    inv[1]=1;
    rep(i,2,15) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    if(n<=2) return puts("1"),0;

    dp[1][0][0]=1;
    rep(j,0,d) g[1][j]=1;
    rep(i,2,n) rep(j,1,d) 
    {
        rep(k,1,i-1) rep(j2,0,j)
        {
            if(j2*k>=i) break;
            add(dp[i][j][k],1ll*dp[i-j2*k][j-j2][min(k-1,i-j2*k-1)]*g[k][j2]%mod);
        }
        rep(j,0,d) g[i][j]=binom(dp[i][d-1][i-1]+j-1,j);
        //rep(k,1,i-1) printf("? %d %d %d: %d\n",i,j,k,dp[i][j][k]);
    }
    int ans=dp[n][d][n/2];
    if(n%2==0) ans=(ans+mod-binom(dp[n/2][d-1][n/2-1],2))%mod;
    printf("%d\n",ans);
    return 0;
}