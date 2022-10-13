#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5+ 5;
vi dp(1001);
vb vis(1001);
vvi adj(1001);
void dfs(int curr) {
  vis[curr] = true;
  for(int next : adj[curr]) {
    if(!vis[next]) dfs(next);
    dp[curr] = max(dp[curr], dp[next] + 1);
  }
}
int main() {
  int n, k; cin >> n >> k;
  vvi in(k);
  vi f(n+1, 10000), l(n+1);
  vvi num(n+1, vi(n+1));
  for(int i=0;i<k;i++) {
    in[i].resize(n);
    for(int j=0;j<n;j++) {
      cin >> in[i][j];
      f[in[i][j]] = min(f[in[i][j]], j+1);
      l[in[i][j]] = max(l[in[i][j]], j+1);
    }
    for(int j=0;j<n;j++) {
      for(int r=j+1;r<n;r++) {
        ++num[in[i][j]][in[i][r]];
      }
    }
  }
  vi degree(n+1);
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      if(num[i][j] == k) {
        adj[i].pb(j), ++degree[j];
      }
    }
  }
  int ans = 0;
  for(int i=1;i<=n;i++) {
    if(degree[i]) continue;
    dfs(i);
    ans = max(ans, dp[i]);
  }
  cout << ans+1;
}