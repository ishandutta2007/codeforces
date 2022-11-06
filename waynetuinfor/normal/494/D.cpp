#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  constexpr int kMod = 1'000'000'000 + 7;
  vector<int> dist(n);
  vector<vector<int>> dp(n, vector<int>(2));
  vector<vector<int>> up(n, vector<int>(2));
  vector<int> sz(n), dep(n);
  vector<vector<int>> fa(n);

  function<void(int, int)> Dfs = [&](int x, int p) {
    sz[x] = 1;
    fa[x].push_back(p);
    for (int i = 1; (1 << i) <= dep[x]; ++i) fa[x].push_back(fa[fa[x][i - 1]][i - 1]);
    for (auto e : g[x]) {
      int u = e.first, w = e.second;
      if (u == p) continue;
      dist[u] = (dist[x] + w) % kMod;
      dep[u] = dep[x] + 1;
      Dfs(u, x);
      sz[x] += sz[u];
      (dp[x][0] += (dp[u][0] + 1LL * w * sz[u]) % kMod) >= kMod ? dp[x][0] -= kMod : 0;
      (dp[x][1] += (dp[u][1] + 2LL * w * dp[u][0] + 1LL * w * w % kMod * sz[u]) % kMod) >= kMod ? dp[x][1] -= kMod : 0;
    }
  };

  function<void(int, int, int, int, vector<int>)> Dfs2 = 
      [&](int x, int p, int fsz, int fw, vector<int> fdp) {

    up[x][0] = dp[x][0];
    up[x][1] = dp[x][1];
    (up[x][0] += (fdp[0] + 1LL * fw * fsz) % kMod) >= kMod ? up[x][0] -= kMod : 0;
    (up[x][1] += (fdp[1] + 2LL * fw * fdp[0] + 1LL * fw * fw % kMod * fsz) % kMod) >= kMod ? up[x][1] -= kMod : 0;
    for (auto e : g[x]) {
      int u = e.first, w = e.second;
      if (u == p) continue;
      (up[x][0] += kMod - (dp[u][0] + 1LL * w * sz[u]) % kMod) >= kMod ? up[x][0] -= kMod : 0;
      (up[x][1] += kMod - (dp[u][1] + 2LL * w * dp[u][0] + 1LL * w * w % kMod * sz[u]) % kMod) >= kMod ? up[x][1] -= kMod : 0;
      Dfs2(u, x, n - sz[u], w, up[x]);
      (up[x][0] += (dp[u][0] + 1LL * w * sz[u]) % kMod) >= kMod ? up[x][0] -= kMod : 0;
      (up[x][1] += (dp[u][1] + 2LL * w * dp[u][0] + 1LL * w * w % kMod * sz[u]) % kMod) >= kMod ? up[x][1] -= kMod : 0;
    }
  };

  Dfs(0, -1);
  Dfs2(0, -1, 0, 0, {0, 0});

  auto Jump = [&](int u, int k) {
    for (int i = 0; i < fa[u].size(); ++i) {
      if (k >> i & 1) u = fa[u][i];
    }
    return u;
  };

  auto GetLCA = [&](int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    v = Jump(v, dep[v] - dep[u]);
    if (u == v) return u;
    for (int i = min(fa[u].size(), fa[v].size()) - 1; i >= 0; --i) {
      if (i < fa[u].size() && i < fa[v].size()) {
        if (fa[u][i] != fa[v][i]) {
          u = fa[u][i];
          v = fa[v][i];
        }
      }
    }
    return fa[u][0];
  };

  auto GetDist = [&](int u, int v) {
    int z = GetLCA(u, v);
    int res = (0LL + dist[u] + dist[v] + kMod - dist[z] + kMod - dist[z]) % kMod;
    return res;
  };

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    int d = GetDist(u, v);
    if (GetLCA(u, v) == v) {
      int f0 = (up[v][0] + kMod - dp[v][0]) % kMod;
      int f1 = (up[v][1] + kMod - dp[v][1]) % kMod;
      int res = (f1 + 2LL * d * f0 + 1LL * d * d % kMod * (n - sz[v])) % kMod;
      int oth = (up[u][1] + kMod - res) % kMod;
      cout << (oth + kMod - res) % kMod << "\n";
    } else {
      int res = (dp[v][1] + 2LL * d * dp[v][0] + 1LL * d * d % kMod * sz[v]) % kMod;
      int oth = (up[u][1] + kMod - res) % kMod;
      cout << (res + kMod - oth) % kMod << "\n";
    }
  }
  return 0;
}