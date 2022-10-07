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
const int MOD=1e9+7,N=1005;
const ll INF=1e11;
int k, c[N], dp[N];
ll sum;
ll power(ll a, ll b)
{
   ll x=1,y=a,ans=1;
   while (x<=b){
      if (x&b)ans=ans*y%MOD;
      x*=2;
      y=y*y%MOD;
   }
   return ans;
}
ll fact (ll a)
{
   ll ans=1;
   for (int i=2;i<=a;i++)ans=ans*i%MOD;
   return ans;
}
ll C (ll n, ll m)
{
   ll ans=fact(n),nn=fact(n-m),mm=fact(m);
   ans=ans*power(nn*mm%MOD,MOD-2)%MOD;
   return ans;
}
int main()
{
   cin>>k;
   for (int i=1;i<=k;i++)cin>>c[i];
   dp[1]=1;
   sum=c[1];
   for (int i=2;i<=k;i++){
      dp[i]=dp[i-1]*C(sum+c[i]-1,sum)%MOD;
      sum+=c[i];
   }
   cout<<dp[k]<<endl;
   return 0;
}