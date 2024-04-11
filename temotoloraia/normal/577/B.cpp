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
const int N=3005;
int n,m,dp[N];
vector<int>v;
int main(){
   cin>>n>>m;
   if (n>=m){
      cout<<"YES"<<endl;
      return 0;
   }
   for (int i=1;i<=n;i++){
      int x;
      cin>>x;
      v.clear();
      for (int j=0;j<m;j++)
      if (dp[j])v.pb(j);
      for (int j=0;j<v.size();j++)
      dp[(v[j]+x)%m]=1;
      dp[x%m]=1;
      if (dp[0]){
         cout<<"YES"<<endl;
         return 0;
      }
   }
   cout<<"NO"<<endl;
   return 0;
}