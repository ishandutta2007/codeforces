#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
int dist(pair<int, int> &x, pair<int, int> &y) {
  return abs(x.f - y.f) + abs(x.s - y.s);
}
int main() {
  int r, n; cin >> r >> n;
  vector<pair<int,pair<int,int>>> in(n);
  for(auto &a : in) cin>> a.f >> a.s.f >> a.s.s;
  vector<int> dp(n+1, -1000000000);
  vector<int> mx(n+1, -1000000000);
  pair<int, int> z = {1, 1};
  dp[0] = 0;
  mx[0] = 0;
  int ans = 0;
  for(int i=1;i<=n;i++) {
    for(int j=i-1;j>=i-2*r;j--) {
      if(j >= 1) {
        if(dist(in[i-1].s, in[j-1].s) <= in[i-1].f - in[j-1].f) {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
      else if(j == 0) {
        if(dist(in[i-1].s, z) <= in[i-1].f) {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
    }
    if(i-2*r-1 >= 0) {
      dp[i] = max(dp[i], 1 + mx[i-2*r-1]);
    }
    ans = max(ans, dp[i]);
    mx[i] = max(mx[i-1], dp[i]);
  }
  cout << ans << "\n";
}