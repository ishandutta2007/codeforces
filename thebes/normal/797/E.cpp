#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+4, MS = 316;
int N, S, Q, arr[MN], i, j, p, k, cnt, dp[MN][MS];

int main(){
  for(scanf("%d",&N),i=1;i<=N;i++)
    scanf("%d",&arr[i]);
  S = sqrt(N+0.0);
  for(i=N;i>=1;i--){
    for(j=1;j<=S;j++){
      if(i+j+arr[i]>N) dp[i][j]=1;
      else dp[i][j]=dp[i+j+arr[i]][j]+1;
    }
  }
  for(scanf("%d",&Q);Q;Q--){
    scanf("%d%d",&p,&k);
    if(k<=S) printf("%d\n",dp[p][k]);
    else{
      for(cnt=0;p<=N;cnt++)
        p += arr[p]+k;
      printf("%d\n",cnt);
    }
  }
  return 0;
}