#include <bits/stdc++.h>
using namespace std;

struct union_find {

  vector<int> par;
  vector<int> size, maxi;

  union_find(int n) {
    par.resize(n);
    maxi.resize(n);
    size.assign(n, 1);
    iota(par.begin(), par.end(), 0);
  }

  int find(int u) {
    if (par[u] != u) {
      par[u] = find(par[u]);
    }
    return par[u];
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;

    if (size[u] > size[v]) {
      swap(u, v);
    }
    par[u] = v;
    size[v] += size[u];
    maxi[v] = max(maxi[v], maxi[u]);
    return true;
  }

};

const int N = 1000000;

int maxi_row[N], maxi_col[N], ans[N];
vector<int> row[N], col[N];
array<int, 3> events[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a;
      cin >> a;
      events[i * m + j] = {a, i, j};
    }
  }
  sort(events, events + n * m);

  union_find dsu(n * m);
  for (int i = 0, j = 0; i < n * m; i = j) {
    vector<int> marked_row, marked_col;
    for ( ; j < n * m && events[j][0] == events[i][0]; ++j) {
      auto [a, r, c] = events[j];
      dsu.maxi[j] = max(maxi_row[r], maxi_col[c]) + 1;
      marked_row.push_back(r);
      marked_col.push_back(c);
      row[r].push_back(j);
      col[c].push_back(j);
    }

    for (auto r : marked_row) {
      for (auto k : row[r]) {
        dsu.unite(row[r][0], k);
      }
      row[r].clear();
    }

    for (auto c : marked_col) {
      for (auto k : col[c]) {
        dsu.unite(col[c][0], k);
      }
      col[c].clear();
    }

    for (int k = i; k < j; ++k) {
      auto [a, r, c] = events[k];
      int maxi = dsu.maxi[dsu.find(k)];
      maxi_row[r] = max(maxi_row[r], maxi);
      maxi_col[c] = max(maxi_col[c], maxi);
      ans[r * m + c] = maxi;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i * m + j] << " ";
    }
    cout << "\n";
  }
}