#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define MOD 1e9+7
#define N 100005
#define INF 1e11
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
int n,a[105],dpc[105],dps[105],dpr[105];
int main()
{
   cin>>n;
   for (int i=1;i<=n;i++)cin>>a[i];
   for (int i=1;i<=n;i++){
      dpc[i]=i;
      dps[i]=i;
      dpr[i]=i;
   }
   for (int i=1;i<=n;i++){
      dpr[i]=min(min(dpr[i-1],dpc[i-1]),dps[i-1])+1;
      if (a[i]==0){
         continue;
      }
      if (a[i]==1){
         dpc[i]=min(dpr[i-1],dps[i-1]);
         continue;
      }
      if (a[i]==2){
         dps[i]=min(dpr[i-1],dpc[i-1]);
         continue;
      }
      if (a[i]==3){
         dpc[i]=min(dpr[i-1],dps[i-1]);
         dps[i]=min(dpr[i-1],dpc[i-1]);
         continue;
      }
   }
   cout<<min(min(dpr[n],dps[n]),dpc[n])<<endl;
   return 0;
}