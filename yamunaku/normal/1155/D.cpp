#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  LL x;
  cin >> n >> x;
  vector<LL> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<vector<LL>> dp(n,vector<LL>(3,-LINF));
  dp[0][0]=max(a[0],0LL);
  dp[0][1]=max(x*a[0],dp[0][0]);
  dp[0][2]=max(a[0],dp[0][1]);
  LL ans=dp[0][2];
  for(int i=1;i<n;i++){
    dp[i][0]=max(dp[i-1][0]+a[i],max(a[i],0LL));
    dp[i][1]=max(dp[i-1][1]+x*a[i],max(dp[i-1][0]+x*a[i],dp[i][0]));
    dp[i][2]=max(dp[i-1][2]+a[i],max(dp[i-1][1]+a[i],dp[i][1]));
    ans=max(ans,dp[i][2]);
  }
  cout << ans << endl;
  return 0;
}