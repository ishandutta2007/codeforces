#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 1e6+5;
vector<int> adj[MX];
int mn[MX], d[MX];
int dp[MX][2];
int n, k; 
void dfs(int curr, int par) {
  int mx = 0;
  bool leaf = true;
  for(int next : adj[curr]) if(next!=par) {
    d[next] = d[curr] + 1;
    dfs(next, curr);
    leaf = false;
    mn[curr] = min(mn[curr], mn[next]);
    if(mn[next] - k <= d[curr]) {
      dp[curr][0] += dp[next][0];
      mx = max(mx, dp[next][1] - dp[next][0]);
    }
    else {
      mx = max(mx, dp[next][1]);
    }
  }
  if(leaf) {
    mn[curr] = d[curr];
    dp[curr][0] = 1, dp[curr][1] = 1;
  }
  else {
    dp[curr][1] = dp[curr][0] + mx;
  }
}
int main() {
  cin >> n >> k;
  for(int i=0;i<n;i++)
    mn[i] = 1000000000;
  for(int i=0;i<n-1;i++) {
    int p; cin >> p;
    --p;
    adj[i+1].push_back(p);
    adj[p].push_back(i+1);
  }
  dfs(0, -1);
  cout << dp[0][1];
}