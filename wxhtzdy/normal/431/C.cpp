#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;
long long dp[105][105];
int main() {
  int n,k,d;
  scanf("%i%i%i",&n,&k,&d);
  dp[0][0]=1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=min(d-1,i);j++)
      dp[i][0]+=dp[i-j][0]%md;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=min(d-1,i);j++) dp[i][1]+=dp[i-j][1]%md;
    for(int j=d;j<=min(i,k);j++) dp[i][1]+=(dp[i-j][0]%md+dp[i-j][1]%md)%md;
  }
  printf("%i",dp[n][1]%md);
}