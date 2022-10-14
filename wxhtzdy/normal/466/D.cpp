#include <bits/stdc++.h>
using namespace std;
const int N=2005;
const int mod=1000000007;
int n,h,a[N];
long long dp[N][N];
int main(){
    scanf("%i %i",&n,&h);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    dp[1][0]=((a[1]==h||a[1]+1==h)?1:0);
    dp[1][1]=((a[1]+1==h)?1:0);
    for(int i=2;i<=n;i++){
        for(int j=max(0,h-a[i]-2);a[i]+j<=h;j++){
            if(a[i]+j==h){
                dp[i][j]+=dp[i-1][j];
                if(j>0)dp[i][j]+=dp[i-1][j-1];
            }
            if(a[i]+j+1==h){
                dp[i][j]+=dp[i-1][j+1]*(j+1);
                dp[i][j]+=dp[i-1][j];
                dp[i][j]+=dp[i-1][j]*j;
            }
            dp[i][j]%=mod;
        }
    }
    printf("%lld",dp[n][0]);
    return 0;
}