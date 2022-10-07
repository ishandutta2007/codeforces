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
const int MOD=1e9+7,N=5000005;
const ll INF=1e11;
int t,a,b;
int prime[N],dp[N];
ll sum[N];
int main(){
   for (int i=2;i*i<=N;i++)
   if (prime[i]==0)
   for (int j=i*i;j<=N;j+=i)
   prime[j]=i;
   for (int i=2;i<=N;i++){
      if (prime[i]==0)dp[i]=1;
      else dp[i]=dp[i/prime[i]]+1;
      sum[i]=sum[i-1]+dp[i];
   }
   cin>>t;
   while (t--){
      scanf("%d%d",&a,&b);
      printf("%lld\n",sum[a]-sum[b]);
   }
   return 0;
}