#include <bits/stdc++.h>
using namespace std;
const int N=150;
const int md=1e8;
int dp[N][N][2];
int main(){
    int n1,n2,k1,k2;scanf("%i%i%i%i",&n1,&n2,&k1,&k2);
    dp[0][0][0]=dp[0][0][1]=1;
    for(int i=0;i<=n1;i++)for(int j=0;j<=n2;j++){
        if(i==0&&j==0)continue;
        for(int k=1;k<=k1;k++)if(i>=k)dp[i][j][0]+=dp[i-k][j][1];
        for(int k=1;k<=k2;k++)if(j>=k)dp[i][j][1]+=dp[i][j-k][0];
        dp[i][j][0]%=md;
        dp[i][j][1]%=md;
    }
    printf("%i",(dp[n1][n2][0]+dp[n1][n2][1])%md);
    return 0;
}