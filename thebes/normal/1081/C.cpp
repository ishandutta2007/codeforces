#include <bits/stdc++.h>
using namespace std;

const int MN=2002, mod=998244353;
int dp[2][MN], n, m, k, i, j;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    dp[1][0]=m;
    for(i=2;i<=n;i++){
        for(int j=0;j<MN;j++)
            dp[i%2][j]=dp[(i+1)%2][j];
        for(int j=1;j<=k;j++)
            dp[i%2][j]=(dp[i%2][j]+1LL*(m-1)*dp[(i+1)%2][j-1])%mod;
    }
    printf("%d\n",dp[n%2][k]);
    return 0;
}