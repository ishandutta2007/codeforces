#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int N = 5e5 + 10;
vector<pair<int, int>> g[N];
int dp[N][2], k;

void dfs(int v, int p = 0) {
  vector<pair<int, int>> arr;
  dp[v][0] = dp[v][1] = 0;
  for (auto u : g[v]) {
    if (u.F != p) {
      dfs(u.F, v);
      dp[v][0] += dp[u.F][1];
      arr.pb({-dp[u.F][1] + dp[u.F][0] + u.S, u.F});
    }
  }
  if (SZ(arr) < k) {
    dp[v][0] = 0;
    for (auto u : g[v]) {
      if (u.F != p) dp[v][0] += max(dp[u.F][0] + u.S, dp[u.F][1]);
    }
    dp[v][1] = dp[v][0];
  }
  else {
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < k - 1; i++) {
      if (arr[i].F > 0) {
        dp[v][0] += arr[i].F;
      }
    }
    dp[v][1] = dp[v][0];
    dp[v][1] += max(0ll, arr[k - 1].F);
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      g[i] = {};
    }
    for (int i = 1; i < n; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      g[u].pb({v, c});
      g[v].pb({u, c});
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
  }    
}