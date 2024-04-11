#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e8,N=50005;
const ll INF=1e17;
int m,n;
int a[N][6],dp[N][6];
int main(){
   cin>>m>>n;
   for (int i=1;i<=m;i++)
   for (int j=1;j<=n;j++)
   cin>>a[i][j];
   for (int i=1;i<=m;i++)
   for (int j=1;j<=n;j++)
   dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
   for (int i=1;i<=m;i++)cout<<dp[i][n]<<" ";
   return 0;
}