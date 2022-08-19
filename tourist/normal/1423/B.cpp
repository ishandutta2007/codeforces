/**
 *    author:  tourist
 *    created: 05.10.2020 16:08:00       
**/
#include <bits/stdc++.h>

using namespace std;

class matching {
 public:
  vector<vector<int>> g;
  vector<int> pa;
  vector<int> pb;
  vector<int> was;
  int n, m;
  int res;
  int iter;

  matching(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = vector<int>(n, -1);
    pb = vector<int>(m, -1);
    was = vector<int>(n, 0);
    g.resize(n);
    res = 0;
    iter = 0;
  }

  void add(int from, int to) {
    assert(0 <= from && from < n && 0 <= to && to < m);
    g[from].push_back(to);
  }

  bool dfs(int v) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != iter && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }

  int solve() {
    while (true) {
      iter++;
      int add = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1 && dfs(i)) {
          add++;
        }
      }
      if (add == 0) {
        break;
      }
      res += add;
    }
    return res;
  }

  int run_one(int v) {
    if (pa[v] != -1) {
      return 0;
    }
    iter++;
    return (int) dfs(v);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  vector<int> c(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i]; --b[i];
  }
  vector<int> order(m);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return c[i] < c[j];
  });
  int low = n, high = m + 1;
  while (low < high) {
    int mid = (low + high) >> 1;
    matching mat(n, n);
    for (int i = 0; i < m; i++) {
      if (c[i] <= c[order[mid - 1]]) {
        mat.add(a[i], b[i]);
      }
    }
    if (mat.solve() == n) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << (low <= m ? c[order[low - 1]] : -1) << '\n';
  return 0;
}