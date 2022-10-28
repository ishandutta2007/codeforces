#include <bits/stdc++.h>
using namespace std;

const int N = 5e4;
const int K = 10;

priority_queue<array<int, 2>> pq[K];

struct union_find {

  int par[N];
  int mx[N][K];
  int mn[N][K];
  int sz[N];

  void init(int n) {
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);
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
    if (u == v)
      return false;

    if (sz[u] > sz[v]) {
      swap(u, v);
    }
    par[u] = v;
    sz[v] += sz[u];

    for (int i = 0; i < K; ++i) {
      mn[v][i] = min(mn[v][i], mn[u][i]);
      mx[v][i] = max(mx[v][i], mx[u][i]);
    }
    return true;
  }

} dsu;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  dsu.init(n);

  int root = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> dsu.mx[i][j];
      dsu.mn[i][j] = dsu.mx[i][j];
    }

    for (int j = 0; j < k; ++j) {
      pq[j].push({dsu.mx[i][j], i});
    }

    if (dsu.mx[i][0] >= dsu.mx[root][0]) {
      root = i;
    }

    bool delta = true;
    while (delta) {
      delta = false;
      for (int j = 0; j < k; ++j) {
        while (!pq[j].empty() && pq[j].top()[0] >= dsu.mn[root][j]) {
          auto [x, u] = pq[j].top();
          pq[j].pop();
          if (u == root || dsu.par[u] != u) {
            continue;
          }
          delta |= dsu.unite(root, u);
          root = dsu.find(root);
        }
        pq[j].push({dsu.mx[root][j], root});
      }
    }

    cout << dsu.sz[root] << "\n";
  }
}