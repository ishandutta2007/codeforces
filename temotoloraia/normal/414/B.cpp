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
const int MOD=1e9+7,N=2005;
const ll INF=1e11;
int n, k, p;
ll dp[N][N], ans;
int main()
{
   cin>>n>>k;
   for (int i=1;i<=n;i++)dp[i][1]=1;
   for (int i=1;i<=n;i++)
   for (int j=2;j<=k;j++){
   for (int l=1;l*l<i;l++)
   if (i%l==0)
   dp[i][j]=(dp[i][j]+dp[l][j-1]+dp[i/l][j-1])%MOD;
   p=sqrt(i);
   if (i==p*p)dp[i][j]=(dp[i][j]+dp[p][j-1])%MOD;
   }
   for (int i=1;i<=n;i++)ans=(ans+dp[i][k])%MOD;
   cout<<ans<<endl;
   return 0;
}