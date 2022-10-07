#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define MOD 1e9+7
#define N 500005
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
int n,a[N];
ll a1,a2,a3;
ll sum,ss,ans;
int main()
{
   cin>>n;
   for (int i=1;i<=n;i++){
      cin>>a[i];
      ss+=a[i];
   }
   if (ss%3){cout<<0<<endl;return 0;}
   if (ss==0){
      for (int i=1;i<=n;i++){
         sum+=a[i];
         if (sum==0)ans++;
      }
      cout<<(ans-1)*(ans-2)/2<<endl;
      return 0;
   }
   for (int i=1;i<=n;i++){
      sum+=a[i];
      if (sum==ss/3){a1++;continue;}
      if (sum==2*ss/3){a2+=a1;continue;}
      if (sum==ss){a3+=a2;continue;}
   }
   cout<<a2<<endl;
   return 0;
}