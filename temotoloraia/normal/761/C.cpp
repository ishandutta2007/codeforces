#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define F(x,y)   (MIN(x-1,y-x+1))
using namespace std;
const int N=55;
int n,m;
char ch;
int a[N][N];
int dp[10],d[10];
int main(){
   cin>>n>>m;
   for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++){
      cin>>ch;
      if ('a'<=ch && ch<='z')a[i][j]=1;
      else if ('0'<=ch && ch<='9')a[i][j]=2;
      else a[i][j]=4;
   }
   for (int j=1;j<8;j++)
   dp[j]=-1;
   dp[0]=0;
   for (int i=1;i<=n;i++){
      for (int j=1;j<8;j++)d[j]=-1;
      for (int j=1;j<=m;j++)
      for (int k=0;k<8;k++)
      if (dp[k]!=-1)
      if (d[(k|a[i][j])]==-1 || d[(k|a[i][j])]>dp[k]+F(j,m))
      d[(k|a[i][j])]=dp[k]+F(j,m);
      for (int j=1;j<8;j++)
      if (d[j]!=-1)
      if (dp[j]==-1 || dp[j]>d[j])
      dp[j]=d[j];
   }
   cout<<dp[7]<<endl;
   return 0;
}