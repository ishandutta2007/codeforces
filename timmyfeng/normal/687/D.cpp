#include <bits/stdc++.h>
using namespace std;

struct union_find {

  vector<int> par, size, w;

  union_find(int n) {
    par.resize(n);
    w.assign(n, 0);
    size.assign(n, 1);
    iota(par.begin(), par.end(), 0);
  }

  pair<int, int> find(int u) {
    if (par[u] != u) {
      int color;
      tie(par[u], color) = find(par[u]);
      w[u] ^= color;
    }
    return {par[u], w[u]};
  }

  bool unite(int u, int v) {
    int cu, cv;
    tie(u, cu) = find(u);
    tie(v, cv) = find(v);
    if (u == v)
      return cu != cv;

    if (size[u] > size[v]) {
      swap(cu, cv);
      swap(u, v);
    }
    par[u] = v;
    w[u] = cu ^ cv ^ 1;
    size[v] += size[u];
    return true;
  }

};

const int M = 500000;

int u[M], v[M], w[M], indices[M];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i], --v[i];
  }

  iota(indices, indices + m, 0);
  sort(indices, indices + m, [&](int a, int b) {
    return w[a] > w[b];
  });

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;

    int ans = -1;
    union_find dsu(n);
    for (int j = 0; j < m; ++j) {
      int i = indices[j];
      if (l <= i && i <= r) {
        if (!dsu.unite(u[i], v[i])) {
          ans = w[i];
          break;
        }
      }
    }

    cout << ans << "\n";
  }
}