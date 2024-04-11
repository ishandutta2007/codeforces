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
const int MOD=1e9+7,N=5005;
const ll INF=1e11;
int n, m, k, a[N];
ll dp[N][N], sum[N];
int main()
{
   cin>>n>>m>>k;
   for (int i=1;i<=n;i++){
      cin>>a[i];
      sum[i]=sum[i-1]+a[i];
   }
   for (int j=1;j<=k;j++)
   for (int i=j*m;i<=n;i++)
      dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]+sum[i]-sum[i-m]);
   cout<<dp[n][k]<<endl;
   return 0;
}