#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
const int N = 39;
int lim[N];
ll n,dp[N][N][2];



int main(){
    scanf("%lld",&n);
    int len=-1;memset(dp,0,sizeof(dp));
    while(n){lim[++len]=n&1;n>>=1;}
    dp[len+1][0][1]=1;
    for(int i=len;i>=0;i--){
        for(int j=0;j<=len+1;j++){
            (dp[i][j+1][0]+=dp[i+1][j][0])%=mod;
            (dp[i][j][0]+=(1ll<<j)*dp[i+1][j][0]%mod)%=mod;
            if(lim[i]){
                if(j) (dp[i][j][0]+=(1ll<<(j-1))*dp[i+1][j][1]%mod)%=mod;
                else (dp[i][j][0]+=dp[i+1][j][1])%=mod;
            }
            //dp[i+1][j][1]
            if(lim[i]){
                if(j) (dp[i][j][1]+=(1ll<<(j-1))*dp[i+1][j][1]%mod)%=mod;
                (dp[i][j+1][1]+=dp[i+1][j][1])%=mod;
            }
            else{
                if(j) (dp[i][j][1]+=(1ll<<(j-1))*dp[i+1][j][1]%mod)%=mod;
            }
        }
    }
    ll sum=0;
    for(int j=0;j<=len+1;j++) (sum+=(dp[0][j][0]+dp[0][j][1])%mod)%=mod;
    printf("%lld\n",sum);
    return 0;
}