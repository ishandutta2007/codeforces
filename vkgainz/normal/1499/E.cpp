#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 1e5 + 5;
ll dp[1001][1001][2];
ll dpx[1001], dpy[1001];
ll mod = 998244353;
int main() {
  string x, y; cin >> x >> y;
  int n = x.length(), m = y.length();
  for(int i=1;i<=n;i++) {
    dpx[i] = 1;
    if(i > 1 && x[i-1] != x[i-2]) dpx[i] += dpx[i-1];
  }
  for(int i=1;i<=m;i++) {
    dpy[i] = 1;
    if(i > 1 && y[i-1] != y[i-2]) dpy[i] += dpy[i-1];
  }
  //account for overcount
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      //dp[i][j][0]
      //stop at i
      if(x[i-1] != y[j-1])
        dp[i][j][0] += dpy[j];
      //don't stop
      if(i > 1) {
        if(x[i-1] != x[i-2])
          dp[i][j][0] += dp[i-1][j][0];
      }
      if(x[i-1] != y[j-1])
        dp[i][j][0] += dp[i-1][j][1];
      //dp[i][j][1]
      //stop at j
      if(x[i-1] != y[j-1])
        dp[i][j][1] += dpx[i];
      //don't stop
      if(j > 1) {
        if(y[j-1] != y[j-2])
          dp[i][j][1] += dp[i][j-1][1];
      }
      if(x[i-1] != y[j-1])
        dp[i][j][1] += dp[i][j-1][0];
      dp[i][j][0] %= mod, dp[i][j][1] %= mod;
    }
  }
  ll ans = 0LL;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      ans += dp[i][j][0] + dp[i][j][1];
      ans %= mod;
    }
  }
  if(ans < 0) ans += mod;
  cout << ans << "\n";
}