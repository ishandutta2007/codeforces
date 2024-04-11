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
const int MOD=1e9+7,N=105;
const ll INF=1e11;
int n,k,d,dp[N];
int solve (int a, int b)
{
   for (int i=1;i<=a;i++)dp[i]=0;
   dp[0]=1;
   for (int i=1;i<=a;i++)
   for (int j=i-1;j>=0 && j>=i-b;j--)
   dp[i]=(dp[i]+dp[j])%MOD;
   return dp[a];
}
int main()
{
   cin>>n>>k>>d;
   cout<<(solve(n,k)-solve(n,d-1)+MOD)%MOD<<endl;
   return 0;
}