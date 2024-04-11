#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  constexpr int kMod = 998244353;
  vector<vector<int>> dp(n, vector<int>(5));
  // dp[x][0]: x not in induced graph
  // dp[x][1]: x in induced graph but not chosen
  // dp[x][2]: x in induced graph and chosen
  // dp[x][3]

  auto Dfs = [&](auto self, int x, int p) -> void {
    vector<int> edp(2), fdp(2);
    edp[0] = 1;
    fdp[0] = 1;
    dp[x][0] = 1;
    dp[x][3] = 1;
    for (int u : g[x]) {
      if (u == p) continue;
      self(self, u, x);
      vector<int> ext(2), fxt(2);
      // cut the edge
      dp[x][0] = 1LL * dp[x][0] * (0LL + dp[u][1] + dp[u][2] + dp[u][3]) % kMod;
      dp[x][3] = 1LL * dp[x][3] * (0LL + dp[u][1] + dp[u][2] + dp[u][3]) % kMod;
      {
        for (int i = 0; i < 2; ++i) {
          int a = (0LL + dp[u][1] + dp[u][2] + dp[u][3]) % kMod;
          ext[i] += 1LL * edp[i] * a % kMod;
          ext[i] >= kMod ? ext[i] -= kMod : 0;
          fxt[i] += 1LL * fdp[i] * a % kMod;
          fxt[i] >= kMod ? fxt[i] -= kMod : 0;
        }
      }
      // keep the edge
      {
        for (int i = 0; i < 2; ++i) {
          int a = (0LL + 2 * dp[u][0] + dp[u][1] + dp[u][2]) % kMod;
          ext[1] += 1LL * edp[i] * a % kMod;
          ext[1] >= kMod ? ext[1] -= kMod : 0;
        }
        for (int i = 0; i < 2; ++i) {
          int a = (0LL + dp[u][0] + dp[u][1]) % kMod;
          fxt[1] += 1LL * fdp[i] * a % kMod;
          fxt[1] >= kMod ? fxt[1] -= kMod : 0;
        }
      }
      edp = ext;
      fdp = fxt;
    }
    dp[x][1] = edp[1];
    dp[x][2] = fdp[1];
    // cerr << "dp[" << x << "][0] = " << dp[x][0] << endl;
    // cerr << "dp[" << x << "][1] = " << dp[x][1] << endl;
    // cerr << "dp[" << x << "][2] = " << dp[x][2] << endl;
    // cerr << "dp[" << x << "][3] = " << dp[x][3] << endl;
  };

  Dfs(Dfs, 0, -1);
  cout << (0LL + dp[0][1] + dp[0][2] + dp[0][3] + kMod - 1) % kMod << "\n";
  return 0;
}