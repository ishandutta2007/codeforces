#include <bits/stdc++.h>
using namespace std;

const int MOD = (119 << 23) + 1;
const int N = 3e5 + 1;

vector<int> adj[N];
int dp[N][3];
int pre[3];

int add(int a, int b) {
  return (a += b) < MOD ? a : a - MOD;
}

int mul(int a, int b) {
  return 1LL * a * b % MOD;
}

int mod_inv(int a) {
  int b = MOD - 2;
  int res = 1;
  while (b) {
    if (b % 2 > 0) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

// dp[0]: edge (u, p) is absent
// dp[1]: edge (u, p) is present and u is part of matching
// dp[2]: edge (u, p) is present and u is not part of matching

void dfs(int u, int p) {
  dp[u][0] = 1;
  dp[u][2] = 1;
  for (int c : adj[u]) {
    if (c != p) {
      dfs(c, u);
      dp[u][0] = mul(dp[u][0], dp[c][0]);
      dp[u][2] = mul(dp[u][2], add(dp[c][0], dp[c][1]));
    }
  }
  for (int c : adj[u]) {
    if (c != p) {
      int cnt = mul(dp[c][2], mul(dp[u][2], mod_inv(add(dp[c][0], dp[c][1]))));
      dp[u][1] = add(dp[u][1], cnt);
    }
  }
  dp[u][0] = add(dp[u][0], dp[u][1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);
  cout << dp[1][0] << "\n";
}