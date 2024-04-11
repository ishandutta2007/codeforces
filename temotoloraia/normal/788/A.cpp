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
ll n,a[100005];
ll DP[100005],D[100005];
ll ans;
int main(){
   cin>>n;
   for (int i=1;i<=n;i++)
      cin>>a[i];
   a[n+1]=a[n];
   for (int i=n-1;i>=1;i--){
      DP[i]=-abs(a[i+1]-a[i+2])+abs(a[i]-a[i+1])+DP[i+2];
      DP[i]=max(DP[i],abs(a[i]-a[i+1]));
      if (DP[i]<0)DP[i]=0;
      ans=max(ans,DP[i]);
   }
   cout<<ans<<endl;
   return 0;
}