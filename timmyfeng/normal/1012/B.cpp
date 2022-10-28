#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 1;

struct disjoint_set_union {

  int par[N];
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
    return true;
  }

} dsu;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  dsu.init(n + m + 1);
  int ans = n + m - 1;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    ans -= dsu.unite(x, y + n);
  }

  cout << ans << "\n";
}