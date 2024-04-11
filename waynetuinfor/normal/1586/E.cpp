#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> g(N);
  vector<int> uf(N);
  iota(uf.begin(), uf.end(), 0);

  function<int(int)> Find = [&](int x) {
    if (x == uf[x]) return x;
    return uf[x] = Find(uf[x]);
  };

  auto Merge = [&](int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return false;
    uf[x] = y;
    return true;
  };

  for (int i = 0; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (Merge(x, y)) {
      g[x].emplace_back(y, i);
      g[y].emplace_back(x, i);
    }
  }

  vector<int> fa(N), fe(N), dep(N);

  auto Dfs = [&](auto dfs, int x, int p = -1, int f = -1) -> void {
    fa[x] = p;
    fe[x] = f;
    for (auto [u, e] : g[x]) {
      if (u == p) continue;
      dep[u] = dep[x] + 1;
      dfs(dfs, u, x, e);
    }
  };

  int Q;
  cin >> Q;

  vector<int> tag(M);
  vector<vector<int>> res(Q);

  for (int i = 0; i < Q; ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    Dfs(Dfs, x);
    while (y != x) {
      tag[fe[y]] ^= 1;
      res[i].push_back(y);
      y = fa[y];
    }
    res[i].push_back(x);
    reverse(res[i].begin(), res[i].end());
  }
  if (*max_element(tag.begin(), tag.end()) == 0) {
    cout << "YES\n";
    for (int i = 0; i < Q; ++i) {
      cout << res[i].size() << "\n";
      for (int u : res[i]) cout << u + 1 << " ";
      cout << "\n";
    }
  } else {
    cout << "NO\n";

    vector<int> dp(N);

    auto DfsDp = [&](auto dfs, int x, int p = -1, int f = -1) -> void {
      int s = 0;
      int t = 0;
      for (auto [u, e] : g[x]) {
        if (u == p) continue;
        dfs(dfs, u, x, e);
        s += dp[u];
        if (tag[e] == 1) {
          t++;
        }
      }
      s -= t / 2;
      t %= 2;
      if (f != -1 && tag[f] == 1) {
        t++;
        s++;
      }
      if (t == 2) s--;
      dp[x] = s;
    };

    DfsDp(DfsDp, 0);
    cout << dp[0] << "\n";
  }
}