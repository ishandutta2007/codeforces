#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int dp[N][N][N],a[N],n,sum[N],sm[N][N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(dp,-63,sizeof dp);
    dp[1][1][0]=dp[1][1][1]=a[1],dp[1][2][1]=a[2];
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int o=1;o<=n;o++){
            for(int j=0;j<=i;j++){
                if(i>1){
                    if(j)dp[i][o][j]=max(dp[i][o][j],dp[i-1][o][j-1]+a[o]);
                    if(i<=o&&j-(o-i)>=0){
                        dp[i][o][j]=max(dp[i][o][j],sm[i-1][o-1][j-(o-i)]+a[o]);
                    }
                }
                ans=max(ans,dp[i][o][j]);
                sm[i][o][j]=max(sm[i][o-1][j],dp[i][o][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)ans=max(ans,sm[n][n][i]);
    printf("%d",ans);
    return 0;
}