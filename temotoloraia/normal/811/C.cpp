#include <iostream>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e8,N=5005;
const ll INF=1e15;
int n,a[N],dp[N],x,y;
int b[N],c[N],d[N];
int main(){
   cin>>n;
   for (int i=1;i<=n;i++){
      cin>>a[i];
      if (b[a[i]]==0)b[a[i]]=i;
      c[a[i]]=i;
   }
   for (int i=1;i<=n;i++){
      dp[i]=dp[i-1];
      x=0;
      y=i;
      for (int j=0;j<=5000;j++)d[j]=0;
      for (int j=i-1;j>=0;j--){
         if (d[a[j+1]]==0 && c[a[j+1]]!=j+1)break;
         if (d[a[j+1]]==0)x=(x^a[j+1]);
         d[a[j+1]]=1;
         y=min(y,b[a[j+1]]);
         if (j<b[a[i]] && j+1<=y)
         dp[i]=max(dp[i],dp[j]+x);
      }
   }
   //for (int i=1;i<=n;i++)
   cout<<dp[n]<<endl;
   return 0;
}