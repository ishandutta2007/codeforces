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
const int MOD=1e9+7,N=105,M=1105;
const ll INF=1e11;
int v1,v2;
int t,d;
int dp[N][M];
int ans;
int main()
{
   cin>>v1>>v2>>t>>d;
   dp[1][v1]=v1;
   for (int i=2;i<t;i++)
   for (int j=1;j<=M;j++)
   for (int l=max(1,j-d);l<=min(M,j+d);l++)
   if (dp[i-1][l])
   dp[i][j]=max(dp[i][j],dp[i-1][l]+j);
   for (int i=max(1,v2-d);i<=min(M,v2+d);i++)
   ans=max(ans,dp[t-1][i]);
   cout<<ans+v2<<endl;
   return 0;
}