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
int n,a[N],ind,ans;
int main()
{
   cin>>n;
   for (int i=1;i<=n;i++)cin>>a[i];
   for (int i=1;i<=n;i++){
      ind=i;
      while (a[ind+1]>a[ind])ind++;
      ans=max(ans,ind-i+1);
      i=ind;
   }
   cout<<ans<<endl;
   return 0;
}