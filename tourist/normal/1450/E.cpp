/**
 *    author:  tourist
 *    created: 06.12.2020 18:18:04       
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m), z(m);
  dsu d(2 * n);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i] >> z[i];
    --x[i]; --y[i];
    d.unite(x[i], y[i] + n);
    d.unite(x[i] + n, y[i]);
  }
  for (int i = 0; i < n; i++) {
    if (d.get(i) == d.get(i + n)) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    if (z[i] == 0) {
      g[x[i]].emplace_back(y[i], 1);
      g[y[i]].emplace_back(x[i], 1);
    } else {
      g[x[i]].emplace_back(y[i], 1);
      g[y[i]].emplace_back(x[i], -1);
    }
  }
  int mx = -1;
  vector<int> best;
  for (int start = 0; start < n; start++) {
    const int inf = (int) 1e9;
    vector<int> d(n, inf);
    d[start] = 0;
    int last = -1;
    for (int iter = 0; iter <= n; iter++) {
      for (int i = 0; i < n; i++) {
        for (auto& e : g[i]) {
          int to = e.first;
          if (d[i] + e.second < d[to]) {
            d[to] = d[i] + e.second;
            last = iter;
          }
        }
      }
    }
    if (last == n) {
      continue;
    }
    if (*min_element(d.begin(), d.end()) < 0) {
      continue;
    }
    int u = *max_element(d.begin(), d.end());
    if (u > mx) {
      mx = u;
      best = d;
    }
  }
  if (mx < 0) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  cout << mx << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << best[i];
  }
  cout << '\n';
  return 0;
}