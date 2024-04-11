#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define MOD 1e9+7
#define N 100005
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
int n,m,a[105],b[105],ind[105],ans;
int main()
{
   cin>>n;
   for (int i=1;i<=n;i++){cin>>a[i];ind[a[i]]++;}
   cin>>m;
   for (int i=1;i<=m;i++)cin>>b[i];
   sort(b+1,b+m+1);
   for (int i=1;i<=m;i++){
      if (ind[b[i]-1]){
         ind[b[i]-1]--;
         ans++;
         continue;
      }
      if (ind[b[i]]){
         ind[b[i]]--;
         ans++;
         continue;
      }
      if (ind[b[i]+1]){
         ind[b[i]+1]--;
         ans++;
      }
   }
   cout<<ans<<endl;
   return 0;
}