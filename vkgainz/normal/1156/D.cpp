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
const int MX = 2e5 + 5;
vector<pair<int, int>> adj[MX];
int dp[MX][2]; //have not passed through a 1-edge, or have passed through a 1-edge
int dpOut[MX][2];
void dfs(int curr, int par) {
  for(auto next : adj[curr]) {
    if(next.f == par) continue;
    dfs(next.f, curr);
    if(next.s == 0) {
      dp[curr][0] += dp[next.f][0];
    }
    else {
      dp[curr][1] += dp[next.f][1];
      dp[curr][0] += dp[next.f][1];
    }
  }
  ++dp[curr][0], ++dp[curr][1];
}
void dfs2(int curr, int par, int v) {
  ++dpOut[curr][0], ++dpOut[curr][1];
  if(v == 0 && par!=-1) {
    dpOut[curr][0] += dpOut[par][0];
    dpOut[curr][0] += dp[par][0] - dp[curr][0];
    --dpOut[curr][0];
  }
  else if(par!=-1) {
    dpOut[curr][1] += dpOut[par][1];
    dpOut[curr][1] += dp[par][1] - dp[curr][1];
    dpOut[curr][0] += dpOut[par][1];
    dpOut[curr][0] += dp[par][1] - dp[curr][1];
    --dpOut[curr][0], --dpOut[curr][1];
  }
  for(auto next : adj[curr]) {
    if(next.f == par) continue;
    dfs2(next.f, curr, next.s);
  }
}
int main() {
  int n; cin >> n;
  for(int i=0;i<n-1;i++) {
    int x, y; cin >> x >> y;
    int c; cin >> c;
    --x, --y;
    adj[x].push_back({y, c});
    adj[y].push_back({x, c});
  }
  dfs(0, -1);
  dfs2(0, -1, -1);
  ll ans = 0LL;
  for(int i=0;i<n;i++) {
    ans+=dp[i][0]+dpOut[i][0];
    ans-=2;
  }
  cout << ans << "\n";
}