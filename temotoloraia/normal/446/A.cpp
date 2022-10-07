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
const int MOD=1e9+7,N=100005;
const ll INF=1e11;
int n, a[N], ind[N], ans, p;
int main()
{
   cin>>n;
   for (int i=1;i<=n;i++)cin>>a[i];
   for (int i=1;i<=n;i++){
      if (i<=ind[i-1]){
         ind[i]=ind[i-1];
         continue;
      }
      ind[i]=i;
      while (a[ind[i]+1]>a[ind[i]])ind[i]++;
   }
   for (int i=1;i<=n;i++){
      if (i==2)p=1;
      ans=max(ind[i]-i+1+p,ans);
      if (ind[i]+1<=n)ans=max(ans,ind[i]-i+2);
      if (a[ind[i]+2]>a[ind[i]]+1)
      ans=max(ind[ind[i]+2]-i+1,ans);
      if (ind[i]==i)continue;
      ind[i]--;
      if (a[ind[i]+2]>a[ind[i]]+1)
      ans=max(ind[ind[i]+2]-i+1,ans);
      ind[i]++;
   }
   cout<<ans<<endl;
   return 0;
}