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
const int N=505;
ll n, m, b, M;
ll dp[N][N],d[N][N]; // n b
ll a[N];
ll ans;
int main(){
   cin>>n>>m>>b>>M;
   for (int i=1;i<=n;i++)cin>>a[i];
   for (int i=0;i<=n;i++)dp[i][0]=1;
   for (int i=1;i<=m;i++){
      for (int j=1;j<=n;j++)
         for (int k=0;k<=b;k++)
            d[j][k]=0;
      for (int j=1;j<=n;j++)
         for (int k=0;k<=b;k++){
            if (k<a[j])d[j][k]=d[j-1][k];
            else d[j][k]=(d[j-1][k]+dp[j][k-a[j]])%M;
         }
      for (int j=1;j<=n;j++)
         for (int k=0;k<=b;k++)
            dp[j][k]=d[j][k];
   }
   for (int j=0;j<=b;j++)
      ans=(ans+dp[n][j])%M;
   cout<<ans<<endl;
   return 0;
}