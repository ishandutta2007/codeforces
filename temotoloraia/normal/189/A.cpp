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
const int MOD=1e9+7,N=1e5+5;
const ll INF=1e17;
int n,a,b,c,ans,k;
int main(){
   cin>>n>>a>>b>>c;
   for (int i=0;i*a<=n;i++)
   for (int j=0;j*b+i*a<=n;j++){
      k=n-i*a-j*b;
      if (k%c)continue;
      k/=c;
      ans=max(ans,i+j+k);
   }
   cout<<ans<<endl;
   return 0;
}