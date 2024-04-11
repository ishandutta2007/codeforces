/**
 *    author:  tourist
 *    created: 19.05.2022 19:34:51       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

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
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    if (2 * t[i] + 1 > m) {
      cout << -1 << '\n';
      return 0;
    }
  }
  sort(t.begin(), t.end());
  int ptr = n;
  while (ptr > 0 && 3 * t[ptr - 1] > m) {
    ptr -= 1;
  }
  matching mat(n - ptr, ptr);
  for (int i = 0; i < ptr; i++) {
    for (int j = ptr; j < n; j++) {
      if (t[j] % t[i] == 0 && 2 * t[j] + t[i] <= m) {
        mat.add(j - ptr, i);
      }
    }
  }
  if (mat.solve() < n - ptr) {
    cout << -1 << '\n';
    return 0;
  }
  vector<pair<int, int>> res;
  for (int j = ptr; j < n; j++) {
    int i = mat.pa[j - ptr];
    res.emplace_back(2 * t[j] + t[i], t[j] + t[i]);
  }
  for (int i = 0; i < ptr; i++) {
    if (mat.pb[i] == -1) {
      res.emplace_back(3 * t[i], 2 * t[i]);
    }
  }
  cout << res.size() << '\n';
  for (auto& p : res) {
    cout << p.first << " " << p.second << '\n';
  }
  return 0;
}