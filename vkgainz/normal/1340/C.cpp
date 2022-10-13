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
const int MX = 2e5 + 5;
const int BLOCK_SZ = 300; 

int main() {
  int n, m; cin >> n >> m;
  vector<int> d(m);
  for(auto &a : d) cin >> a;
  sort(d.begin(), d.end());
  int g, r; cin >> g >> r;
  vector<vector<int>> dp(m); //number of cycles to get to vertex i and k mod g
  for(int i=0;i<m;i++)
    dp[i].assign(g, 1000000000);
  dp[0][0] = 0;
  deque<pair<int, int>> q;
  q.push_back({0, 0});
  while(!q.empty()) {
    auto curr = q.front();
    q.pop_front();
    if(curr.f > 0) {
      if(d[curr.f] - d[curr.f -1] + curr.s <= g) {
        int nxt = (d[curr.f] - d[curr.f-1] + curr.s)%g;
        if(nxt == 0 && dp[curr.f][curr.s] + 1 < dp[curr.f - 1][nxt]) {
          dp[curr.f - 1][nxt] = dp[curr.f][curr.s] + 1;
          q.push_back({curr.f -1, nxt});
        }
        else if(nxt != 0 && dp[curr.f][curr.s] < dp[curr.f - 1][nxt]) {
          dp[curr.f - 1][nxt] = dp[curr.f][curr.s];
          q.push_front({curr.f - 1, nxt});
        }
      }
    }
    if(curr.f < m - 1) {
      if(d[curr.f + 1] - d[curr.f] + curr.s <= g) {
        int nxt = (d[curr.f + 1] - d[curr.f] + curr.s)%g;
        if(nxt == 0 && dp[curr.f][curr.s] + 1 < dp[curr.f + 1][nxt]) {
          dp[curr.f + 1][nxt] = dp[curr.f][curr.s] + 1;
          q.push_back({curr.f + 1, nxt});
        }
        else if(nxt != 0 && dp[curr.f][curr.s] < dp[curr.f + 1][nxt]) {
          dp[curr.f + 1][nxt] = dp[curr.f][curr.s];
          q.push_front({curr.f + 1, nxt});
        }
      }
    }
  }
  ll ans = 1000000000;
  for(int i=0;i<g;i++) {
    if(i)
      ans = min(ans, dp[m-1][i]*1LL*(g+r) + i);
    else
      ans = min(ans, dp[m-1][0]*1LL*(g+r) - r);
  }
  if(ans == 1000000000)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}