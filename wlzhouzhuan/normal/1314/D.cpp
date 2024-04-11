#include<bits/stdc++.h>
using namespace std;
const int N=85;
int a[N][N],n,k;
int dp[11][N],col[N],ans=1e9;
int main(){
  srand(time(NULL));
  scanf("%d%d",&n,&k);
  for(register int i=1;i<=n;i++){
    for(register int j=1;j<=n;j++){
      scanf("%d",&a[i][j]);
    }
  }
  int beg=clock();
  while(1.0*(clock()-beg)/CLOCKS_PER_SEC<=1.14){
    for(register int j=0;j<=k;j++)
      for(register int i=1;i<=n;i++)
        dp[j][i]=1e9;
    for(register int i=1;i<=n;i++)col[i]=rand()&1;
    dp[0][1]=0;
    for(register int j=1;j<=k;j++){
      for(register int u=1;u<=n;u++){
        for(register int v=1;v<=n;v++){
          if(col[u]^col[v])dp[j][u]=min(dp[j][u],dp[j-1][v]+a[v][u]);
        }
      }
    }
    ans=min(ans,dp[k][1]);
  }
  printf("%d\n",ans);
  return 0;
}