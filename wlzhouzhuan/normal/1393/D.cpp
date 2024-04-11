#include<bits/stdc++.h>
using namespace std;

int read(){
  int x=0;
  char ch=getchar();
  while(!isdigit(ch))ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return x;
}

const int N=2005;

char a[N][N];
int dp[4][N][N];
int n,m;

int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    scanf("%s",a[i]+1);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i-1][j]==a[i][j]&&a[i][j]==a[i][j-1])
        dp[0][i][j]=min(dp[0][i-1][j],dp[0][i][j-1])+1;
      else
        dp[0][i][j]=1; 
    }
  }  
  for(int i=1;i<=n;i++){
    for(int j=m;j>=1;j--){
      if(a[i-1][j]==a[i][j]&&a[i][j]==a[i][j+1])
        dp[1][i][j]=min(dp[1][i-1][j],dp[1][i][j+1])+1;
      else
        dp[1][i][j]=1;
    }
  }
  for(int i=n;i>=1;i--){
    for(int j=1;j<=m;j++){
      if(a[i+1][j]==a[i][j]&&a[i][j]==a[i][j-1])
        dp[2][i][j]=min(dp[2][i+1][j],dp[2][i][j-1])+1;
      else
        dp[2][i][j]=1;
    }
  }
  for(int i=n;i>=1;i--){
    for(int j=m;j>=1;j--){
      if(a[i+1][j]==a[i][j]&&a[i][j]==a[i][j+1])
        dp[3][i][j]=min(dp[3][i+1][j],dp[3][i][j+1])+1;
      else
        dp[3][i][j]=1;
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      //printf("(%d,%d): %d %d %d %d\n",i,j,dp[0][i][j],dp[1][i][j],dp[2][i][j],dp[3][i][j]);
      ans+=min(min(dp[0][i][j],dp[1][i][j]),min(dp[2][i][j],dp[3][i][j]));
    }
  }
  printf("%d\n",ans);
  return 0;
}