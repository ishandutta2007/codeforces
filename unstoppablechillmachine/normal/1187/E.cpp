#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N= 2e5 + 10;
vector<int> g[N];
int dp[N], sz[N], up[N];

void dfs(int v, int p = 0) {
  sz[v] = 1;
  for (auto u : g[v]) {
    if (u != p) {
      dfs(u, v);
      dp[v] += dp[u];
      sz[v] += sz[u];
    }
  }
  dp[v] += sz[v];
}

int ans = 0, n;

void dfs2(int v, int p = 0) {
  if (v != 1) {
    up[v] = up[p] + dp[p] - sz[p] - dp[v] + n - sz[v];
  }
  ans = max(ans, dp[v] - sz[v] + n + up[v]);
  for (auto u : g[v]) {
    if (u != p) {
      dfs2(u, v);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }  
  dfs(1);
  dfs2(1);
  cout << ans << '\n';
}