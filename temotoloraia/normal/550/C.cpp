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
string s;
int n,a[105];
int dp[105][1005];
int main()
{
   cin>>s;
   n=s.size();
   for (int i=1;i<=n;i++)a[i]=s[i-1]-'0';
   for (int i=1;i<=n;i++){
      dp[i][a[i]]=1;
      for (int j=0;j<100;j++)
      if (dp[i-1][j])
      dp[i][j*10+a[i]]=1;
      for (int j=0;j<1000;j++)
      if (dp[i-1][j])
      dp[i][j]=1;
   }
   for (int i=0;i<1000;i+=8)
   if (dp[n][i]){
      cout<<"YES"<<endl;
      cout<<i<<endl;
      return 0;
   }
   cout<<"NO"<<endl;
   return 0;
}