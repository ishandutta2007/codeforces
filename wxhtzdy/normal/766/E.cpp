#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> vis(n);
  vector<int> sz(n);
  function<void(int, int)> Dfs1 = [&](int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) {
      if (v == p || vis[v]) {
        continue;
      }
      Dfs1(v, u);
      sz[u] += sz[v];
    }
  };
  function<int(int, int, int)> Dfs2 = [&](int u, int p, int n) {
    for (int v : g[u]) {
      if (v == p || vis[v] || sz[v] * 2 < n) {
        continue;
      }
      return Dfs2(v, u, n);
    }
    return u;
  };
  vector<vector<int>> cnt(25, vector<int>(2));
  vector<int> vec;
  function<void(int, int, int)> Dfs3 = [&](int u, int p, int x) {
    x ^= a[u];
    vec.push_back(x);
    for (int v : g[u]) {
      if (v == p || vis[v]) {
        continue;
      }
      Dfs3(v, u, x);
    }
  };
  long long ans = 0;
  function<void(int)> Solve = [&](int u) {
    Dfs1(u, u);
    u = Dfs2(u, u, sz[u]);
    vis[u] = 1;
    ans += a[u];
    for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 2; j++) {
        cnt[i][j] = 0;
      }
      int bit = (a[u] >> i) & 1;
      cnt[i][bit] += 1;
    }
    for (int v : g[u]) {
      if (vis[v]) {
        continue;
      }
      vec.clear();
      Dfs3(v, u, 0);
      for (int i = 0; i < vec.size(); i++) {
        int x = vec[i];
        for (int j = 0; j < 25; j++) {
          int bit = (x >> j) & 1;
          ans += (long long) cnt[j][bit ^ 1] * (1LL << j);
        }
      }
      for (int i = 0; i < vec.size(); i++) {
        int x = vec[i] ^ a[u];
        for (int j = 0; j < 25; j++) {
          int bit = (x >> j) & 1;
          cnt[j][bit] += 1;
        }
      }
    }
    for (int v : g[u]) {
      if (!vis[v]) {
        Solve(v);
      }
    }
  };
  Solve(0);
  cout << ans << '\n';
  return 0;
}