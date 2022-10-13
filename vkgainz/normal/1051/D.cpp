#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5+5;
ll dp[1001][2001][4];
ll get(int i, int j, int k) {
  if(i<0 || j<0 || k<0)
    return 0LL;
  return dp[i][j][k];
}
int main() {
  int n,k; cin >> n >> k;
  for(int i=0;i<n;i++) {
    for(int j=0;j<=k;j++) {
      for(int bit=0;bit<4;bit++) {
        dp[i][j][bit] = 0;
      }
    }
  }
  dp[0][1][0] = 1,dp[0][1][3] = 1, dp[0][2][1] = 1, dp[0][2][2] = 1;
  ll mod = 998244353;
  for(int i=1;i<n;i++) {
    for(int j=0;j<=k;j++) {
      for(int bit=0;bit<4;bit++) {
        for(int lbit=0;lbit<4;lbit++) {
          if(bit==0 || bit==3) {
            if((bit^lbit)==3) dp[i][j][bit]+=get(i-1,j-1,lbit);
            else
              dp[i][j][bit]+=get(i-1,j,lbit);
          }
          else {
            if((bit^lbit)==3) dp[i][j][bit]+=get(i-1,j-2,lbit);
            else if((bit==lbit)) dp[i][j][bit]+=get(i-1,j,lbit);
            else
              dp[i][j][bit]+=get(i-1,j-1,lbit);
          }
        }
        dp[i][j][bit]%=mod;
      }
    }
  }
  ll ans = 0;
  for(int bit=0;bit<4;bit++)
    ans+=get(n-1, k, bit);
  ans%=mod;
  if(ans<0) ans+=mod;
  cout << ans << "\n";
}