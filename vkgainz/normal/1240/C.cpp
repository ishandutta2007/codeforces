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
vector<vector<pair<int, int>>> adj;
vector<pair<ll, ll>> dp;
int k;
void dfs(int curr, int par) {
  vector<ll> in;
  ll sum = 0LL;
  for(auto next : adj[curr]) {
    if(next.f == par) continue;
    dfs(next.f, curr);
    sum += dp[next.f].f;
    in.push_back({dp[next.f].s+next.s - dp[next.f].f});
  }
  sort(in.begin(), in.end(), greater<ll>());
  dp[curr] = {sum, sum};
  //to calculate first, take <= k of second and rest first
  for(int i=0;i<min(k, (int)in.size());i++) {
    dp[curr].f += max(in[i], 0LL);
  }
  for(int i=0;i<min(k-1, (int)in.size());i++) {
    dp[curr].s += max(in[i], 0LL);
  }
  //otherwise take <= k-1
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q; cin >> q;
  while(q--) {
    int n; cin >> n >> k;
    adj.clear();
    adj.resize(n);
    dp.clear();
    dp.resize(n);
    for(int i=0;i<n;i++) dp[i] = {0LL, 0LL};
    for(int i=0;i<n-1;i++) {
      int u, v, w; cin >> u >> v >> w;
      --u, --v;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    dfs(0, -1);
    cout << dp[0].f << "\n";
  }
}