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
ll n,m,k;
ll c[105];
ll P[105][105];
ll dp[105][105][105]; // n m
int main(){
   cin>>n>>m>>k;
   for (ll i=1;i<=n;i++)cin>>c[i];
   for (ll i=1;i<=n;i++)
   for (ll j=1;j<=m;j++)
   cin>>P[i][j];
   for (ll i=0;i<=n;i++)
   for (ll j=0;j<=k;j++)
   for (ll l=0;l<=m;l++)
   dp[i][j][l]=-1;
   dp[0][0][0]=0;
   for (ll i=1;i<=n;i++){
      for (ll l=1;l<=m;l++)
         if (c[i]==0 || c[i]==l)
            for (ll j=0;j<=k;j++)
               for (ll p=0;p<=m;p++){
                  if (dp[i-1][j][p]==-1)continue;
                  ll x=j;
                  if (p!=l)x++;
                  ll y=dp[i-1][j][p];
                  if (c[i]==0)y+=P[i][l];
                  if (dp[i][x][l]==-1 || dp[i][x][l]>y)dp[i][x][l]=y;
               }
   }
   ll ans=-1;
   for (ll i=1;i<=m;i++)
   if (dp[n][k][i]!=-1)
   if (ans==-1 || ans>dp[n][k][i])
   ans=dp[n][k][i];
   cout<<ans<<endl;
   return 0;
}