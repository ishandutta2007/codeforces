#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

array<int, 3> edges[N];
int special[N];

struct union_find {

  vector<int> par;
  vector<int> sz;

  union_find(int n) {
    par.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i) {
      sz[i] = (special[i] > -1);
    }
    iota(par.begin(), par.end(), 0);
  }

  int find(int u) {
    if (par[u] != u) {
      par[u] = find(par[u]);
    }
    return par[u];
  }

  int unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return sz[u];

    if (sz[u] > sz[v]) {
      swap(u, v);
    }
    par[u] = v;
    sz[v] += sz[u];
    return sz[v];
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;

  fill(special, special + n, -1);
  for (int i = 0; i < t; ++i) {
    int x;
    cin >> x;
    special[x - 1] = i;
  }

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {w, u - 1, v - 1};
  }
  sort(edges, edges + m);

  int ans = 0;
  union_find dsu(n);
  for (int i = 0; i < m; ++i) {
    auto [w, u, v] = edges[i];
    if (dsu.unite(u, v) == t) {
      ans = w;
      break;
    }
  }


  for (int i = 0; i < t; ++i) {
    cout << ans << " ";
  }
  cout << "\n";
}