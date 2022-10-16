#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll dp[50+5][50+5][maxn+5];
ll ans[maxn+5];
ll inv[10000+5];
int like[maxn+5],w[maxn+5];

int main()
{
    inv[1]=1;
    rep(i,2,10000) inv[i]=inv[mod%i]*(mod-mod/i)%mod;

    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&like[i]);
    rep(i,1,n) scanf("%d",&w[i]);
    int W=0,L=0;
    rep(i,1,n) if(like[i]==0) W+=w[i]; else L+=w[i];

    rep(id,1,n)
    {
        memset(dp,0,sizeof dp);
        dp[0][0][w[id]]=1;
        if(like[id]==0)
        {
            rep(i,0,m-1) rep(j,0,i) rep(k,0,w[id])
            {
                if(W+L+i-j*2<=0) continue;
                ll base=dp[i][j][k];
                //if(j>W) assert(base==0);
                dp[i+1][j][k]=(dp[i+1][j][k]+base*(L+i-j)%mod*inv[W+L+i-j*2])%mod;
                if(W-j>0)
                {
                    if(k>W-j) assert(base==0);
                    dp[i+1][j+1][k]=(dp[i+1][j+1][k]+base*(W-j-k)%mod*inv[W+L+i-j*2])%mod;
                    dp[i+1][j+1][k-1]=(dp[i+1][j+1][k-1]+base*(k)%mod*inv[W+L+i-j*2])%mod;
                }
            }
        }
        else
        {
            rep(i,0,m-1) rep(j,0,i) rep(k,w[id],w[id]+i)
            {
                if(W+L+i-j*2<=0) continue;
                ll base=dp[i][j][k];
                //if(j>W) assert(base==0);

                if(W-j>0)
                {
                    dp[i+1][j+1][k]=(dp[i+1][j+1][k]+base*(W-j)%mod*inv[W+L+i-j*2])%mod;
                }
                dp[i+1][j][k]=(dp[i+1][j][k]+base*(L+i-j-k)%mod*inv[W+L+i-j*2])%mod;
                dp[i+1][j][k+1]=(dp[i+1][j][k+1]+base*(k)%mod*inv[W+L+i-j*2])%mod;
            }
        }
        ll S=0;
        rep(j,0,m) rep(k,0,w[id]+m) S=(S+dp[m][j][k])%mod;
        rep(j,0,m) rep(k,0,w[id]+m) ans[id]=(ans[id]+dp[m][j][k]*k)%mod;
        //assert(S==1);
        printf("%I64d\n",ans[id]);
    }
    return 0;
}