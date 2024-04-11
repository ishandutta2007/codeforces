#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

struct union_find {

  int par[N];
  int cnt[N];
  int sz[N];

  void init(int n) {
    fill(sz, sz + n, 1);
    iota(par, par + n, 0);
  }

  int find(int u) {
    if (par[u] != u) {
      par[u] = find(par[u]);
    }
    return par[u];
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
      ++cnt[u];
      return false;
    }
    par[u] = v;
    sz[v] += sz[u];
    cnt[v] += cnt[u] + 1;
    return true;
  }

} dsu;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<array<int, 3>> edges;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, u - 1, v - 1});
  }
  sort(edges.rbegin(), edges.rend());

  int64_t ans = 0;
  dsu.init(n);
  for (auto [w, u, v] : edges) {
    if (dsu.cnt[dsu.find(u)] < dsu.sz[dsu.find(u)] || dsu.cnt[dsu.find(v)] < dsu.sz[dsu.find(v)]) {
      dsu.unite(u, v);
      ans += w;
    }
  }

  cout << ans << "\n";
}