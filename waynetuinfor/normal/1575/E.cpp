#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<vector<pair<int, int>>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    u--;
    v--;
    g[u].emplace_back(v, t);
    g[v].emplace_back(u, t);
  }

  vector<int> sz(N), mx(N);
  vector<bool> vis(N);
  vector<int> nds;

  auto DfsSz = [&](auto dfs, int x) -> void {
    vis[x] = true;
    sz[x] = 1;
    mx[x] = 0;
    nds.push_back(x);
    for (auto [u, t] : g[x]) {
      if (!vis[u]) {
        dfs(dfs, u);
        sz[x] += sz[u];
        mx[x] = max(mx[x], sz[u]);
      }
    }
  };

  constexpr int kP = 1'000'000'000 + 7;
  vector<vector<vector<pair<int, int>>>> vec(N, vector<vector<pair<int, int>>>(2));

  auto DfsPath = [&](auto dfs, int x, int f, int c, int fc, int y, int s = 0) -> void {
    vis[x] = true;
    (s += A[x]) %= kP;
    if (y > K) return;
    vec[f][fc].emplace_back(y, s);
    for (auto [u, t] : g[x]) {
      if (!vis[u]) {
        dfs(dfs, u, f, t, fc, y + (c != t), s);
      }
    }
  };

  int ans = 0;

  vector<vector<pair<int, int>>> fw(2, vector<pair<int, int>>(N + 1));

  auto Update = [&](int x, int p, int c, int v) {
    for (int i = p + 1; i <= N; i += i & -i) {
      fw[x][i].first += c;
      (fw[x][i].second += v) %= kP;
    }
  };

  auto Query = [&](int x, int p) {
    pair<int, int64_t> res{};
    for (int i = p + 1; i > 0; i -= i & -i) {
      res.first += fw[x][i].first;
      (res.second += fw[x][i].second) %= kP;
    }
    return res;
  };

  auto Dfs = [&](auto dfs, int x) -> void {
    nds.clear();
    DfsSz(DfsSz, x);
    int cent = -1;
    int M = nds.size();
    for (int u : nds) {
      if (max(mx[u], M - sz[u]) * 2 <= M) {
        cent = u;
      }
      vis[u] = false;
    }
    assert(cent != -1);
    vis[cent] = true;
    for (auto [u, t] : g[cent]) {
      if (!vis[u]) {
        DfsPath(DfsPath, u, u, t, t, 0);
      }
    }
    for (int u : nds) {
      vis[u] = false;
    }
    vis[cent] = true;
    (ans += A[cent]) %= kP;
    for (auto [u, t] : g[cent]) {
      for (int i = 0; i < 2; ++i) {
        for (auto [p, s] : vec[u][i]) {
          assert(p <= K);
          for (int j = 0; j < 2; ++j) {
            auto r = Query(j, K - p - (i != j));
            ans += (r.second + 1LL * (s + A[cent]) * r.first) % kP;
            ans %= kP;
          }
          ans = (0LL + ans + s + A[cent]) % kP;
        }
      }
      for (int i = 0; i < 2; ++i) {
        for (auto [p, s] : vec[u][i]) {
          Update(i, p, 1, s);
        }
      }
    }
    for (auto [u, t] : g[cent]) {
      for (int i = 0; i < 2; ++i) {
        for (auto [p, s] : vec[u][i]) {
          Update(i, p, -1, kP - s);
        }
        vec[u][i].clear();
      }
    }
    for (auto [u, t] : g[cent]) {
      if (!vis[u]) {
        dfs(dfs, u);
      }
    }
  };

  Dfs(Dfs, 0);
  cout << ans << "\n";
  return 0;
}