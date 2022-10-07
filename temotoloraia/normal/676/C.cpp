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
int n,k,sa[N],sb[N],l=1,r,mid,ans;
string s;
int main()
{
   cin>>n>>k;
   cin>>s;
   for (int i=0;i<n;i++){
      sa[i+1]=sa[i];
      sb[i+1]=sb[i];
      if (s[i]=='a')sa[i+1]++;
      else sb[i+1]++;
   }
   r=n;
   while (l<=r){
      mid=(l+r)/2;
      for (int i=0;i<=n-mid;i++)
      if (sa[i+mid]-sa[i]<=k || sb[i+mid]-sb[i]<=k){
         l=mid+1;
         break;
      }
      if (l==mid+1)ans=mid;
      else r=mid-1;
   }
   cout<<ans<<endl;
   return 0;
}