#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

#define MOD 998244353

typedef long long LL;

LL dp[2][2001][4];

int main(){
  int n,k;
  cin >> n >> k;
  for(int i=0;i<=2*n;i++){
    dp[0][i][0]=dp[0][i][1]=dp[0][i][2]=dp[0][i][3]=0;
  }
  dp[0][1][0]=dp[0][1][3]=dp[0][2][1]=dp[0][2][2]=1;
  for(int i=1;i<n;i++){
    dp[i%2][1][0]=(((dp[(i+1)%2][1][0]+dp[(i+1)%2][1][1])%MOD+dp[(i+1)%2][1][2])%MOD+dp[(i+1)%2][0][3])%MOD;
    dp[i%2][1][1]=dp[(i+1)%2][1][1];
    dp[i%2][1][2]=dp[(i+1)%2][1][2];
    dp[i%2][1][3]=(((dp[(i+1)%2][0][0]+dp[(i+1)%2][1][1])%MOD+dp[(i+1)%2][1][2])%MOD+dp[(i+1)%2][1][3])%MOD;
    for(int j=2;j<=2*n;j++){
      dp[i%2][j][0]=(((dp[(i+1)%2][j][0]+dp[(i+1)%2][j][1])%MOD+dp[(i+1)%2][j][2])%MOD+dp[(i+1)%2][j-1][3])%MOD;
      dp[i%2][j][1]=(((dp[(i+1)%2][j-1][0]+dp[(i+1)%2][j][1])%MOD+dp[(i+1)%2][j-2][2])%MOD+dp[(i+1)%2][j-1][3])%MOD;
      dp[i%2][j][2]=(((dp[(i+1)%2][j-1][0]+dp[(i+1)%2][j-2][1])%MOD+dp[(i+1)%2][j][2])%MOD+dp[(i+1)%2][j-1][3])%MOD;
      dp[i%2][j][3]=(((dp[(i+1)%2][j-1][0]+dp[(i+1)%2][j][1])%MOD+dp[(i+1)%2][j][2])%MOD+dp[(i+1)%2][j][3])%MOD;
    }
  }
  LL ans=(((dp[(n+1)%2][k][0]+dp[(n+1)%2][k][1])%MOD+dp[(n+1)%2][k][2])%MOD+dp[(n+1)%2][k][3])%MOD;
  cout << ans << endl;
  return 0;
}