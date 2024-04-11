#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 3e6+5;
vector<array<ll, 2>> dp;
vector<array<int, 2>> pt;
vector<vector<int>> adj;
void dfs(int curr, int par) {
  for(int next : adj[curr]) {
    if(next == par) continue;
    dfs(next, curr);
    dp[curr][0] += max(abs(pt[curr][0] - pt[next][0]) + dp[next][0], abs(pt[curr][0] - pt[next][1]) + dp[next][1]);
    dp[curr][1] += max(abs(pt[curr][1] - pt[next][1]) + dp[next][1], abs(pt[curr][1] - pt[next][0]) + dp[next][0]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    dp.clear();
    dp.resize(n);
    pt.clear(), pt.resize(n);
    adj.clear(), adj.resize(n);
    for(int i = 0; i < n; i++)
      dp[i] = {0LL, 0LL};
    for(int i = 0; i < n; i++) {
      cin >> pt[i][0] >> pt[i][1];
    }
    for(int i = 0; i < n - 1; i++) {
      int u, v; cin >> u >> v;
      --u, --v;
      adj[u].push_back(v), adj[v].push_back(u);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << "\n";
  }
}