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
const int MOD=1e8,N=150005;
const ll INF=1e17;
int n,k;
string ans[N],s;
int main(){
   cin>>n>>k;
   for (int i=1;i<=n;i++)
      ans[i]="A";
   for (int i=1;i<=n;i++)
   if (i<=26){
      ans[i]+=('a'+i-1);
   }
   else {
      ans[i]+="a";
      ans[i]+=('a'+(i-26)-1);
   }
   for (int i=1;i<=n-k+1;i++){
      cin>>s;
      if (s=="NO")
      ans[i+k-1]=ans[i];
   }
   for (int i=1;i<=n;i++)
   cout<<ans[i]<<" ";
   return 0;
}