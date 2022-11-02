#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define ri int
#define ll long long
#define pii pair<int,int>
const ll mod=1e9+7;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
const int MAXN=1e3+7;
int dp[2][MAXN][2][2],fac[MAXN],C[MAXN][MAXN],n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(ri i=0,j;i<=n;++i) for(C[i][0]=1,j=1;j<=i;++j) C[i][j]=add(C[i-1][j-1],C[i-1][j]);
    fac[0]=1;for(ri i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
    dp[0][0][1][0]=1;
    int o=0;
    for(ri i=1;i<=n;++i){
        memset(dp[o^1],0,sizeof(dp[o^1]));
        for(ri j=0;j<=i-1;++j){
            for(ri p=0;p<=1;++p) for(ri q=0;q<=1;++q) if(dp[o][j][p][q]){
                //
                dp[o^1][j][q][0]=add(dp[o^1][j][q][0],dp[o][j][p][q]);
                //
                if(!p) dp[o^1][j+1][q][0]=add(dp[o^1][j+1][q][0],dp[o][j][p][q]);
                if(i!=n) dp[o^1][j+1][q][1]=add(dp[o^1][j+1][q][1],dp[o][j][p][q]);
            }
        }
        o^=1;
    }
    int ans=0;
    for(ri i=m;i<=n;++i){
        int res=0;
        for(ri p=0;p<=1;++p) for(ri q=0;q<=1;++q) res=add(res,dp[o][i][p][q]);
        res=1ll*res*fac[n-i]%mod;
        // printf("[%d %d]\n",i,res);
        if(i-m&1) ans=dec(ans,1ll*C[i][m]*res%mod);
        else    ans=add(ans,1ll*C[i][m]*res%mod);
    }
    printf("%d\n",ans);
}