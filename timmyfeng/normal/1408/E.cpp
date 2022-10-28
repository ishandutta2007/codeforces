#include <bits/stdc++.h>
using namespace std;

struct union_find {

  vector<int> par;
  vector<int> sz;

  union_find(int n) {
    par.resize(n);
    sz.assign(n, 1);
    iota(par.begin(), par.end(), 0);
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

};

const int N = 200'000;

array<int, 3> edges[N];
int a[N];
int b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> m >> n;

  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  int count_e = 0;
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int c;
      cin >> c;
      ans += a[i] + b[--c];
      edges[count_e++] = {a[i] + b[c], c, n + i};
    }
  }

  sort(edges, edges + count_e);
  union_find dsu(n + m);

  for (int i = count_e - 1; i >= 0; --i) {
    auto [w, u, v] = edges[i];
    if (dsu.unite(u, v)) {
      ans -= w;
    }
  }

  cout << ans << "\n";
}