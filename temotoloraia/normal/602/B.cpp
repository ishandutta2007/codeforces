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
int n,a[N],b[N],ind=1,ans,x;
int main()
{
   cin>>n;
   for (int i=1;i<=n;i++)cin>>a[i];
   b[a[1]]=1;
   for (int i=2;i<=n;i++){
      b[a[i]]++;
      if (b[a[i]]>1){
         ans=max(i-ind+1,ans);
         continue;
      }
      if (b[a[i]-1])x=a[i]-2;
      else x=a[i]+2;
      while (b[x]){
         b[a[ind]]--;
         ind++;
      }
      ans=max(i-ind+1,ans);
   }
   cout<<ans<<endl;
   return 0;
}