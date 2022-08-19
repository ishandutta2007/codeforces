/**
 *    author:  tourist
 *    created: 12.06.2022 19:00:43       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };

  vector<edge> edges;
  vector<vector<int>> g;
  int n;

  graph(int _n) : n(_n) {
    g.resize(n);
  }

  virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class digraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  digraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  digraph<T> reverse() const {
    digraph<T> rev(n);
    for (auto &e : edges) {
      rev.add(e.to, e.from, e.cost);
    }
    return rev;
  }
};

template <typename T>
vector<int> find_scc(const digraph<T> &g, int &cnt) {
  digraph<T> g_rev = g.reverse();
  vector<int> order;
  vector<bool> was(g.n, false);
  function<void(int)> dfs1 = [&](int v) {
    was[v] = true;
    for (int id : g.g[v]) {
      auto &e = g.edges[id];
      int to = e.to;
      if (!was[to]) {
        dfs1(to);
      }
    }
    order.push_back(v);
  };
  for (int i = 0; i < g.n; i++) {
    if (!was[i]) {
      dfs1(i);
    }
  }
  vector<int> c(g.n, -1);
  function<void(int)> dfs2 = [&](int v) {
    for (int id : g_rev.g[v]) {
      auto &e = g_rev.edges[id];
      int to = e.to;
      if (c[to] == -1) {
        c[to] = c[v];
        dfs2(to);
      }
    }
  };
  cnt = 0;
  for (int id = g.n - 1; id >= 0; id--) {
    int i = order[id];
    if (c[i] != -1) {
      continue;
    }
    c[i] = cnt++;
    dfs2(i);
  }
  return c;
}

class twosat {
 public:
  digraph<int> g;
  int n;

  twosat(int _n) : g(digraph<int>(2 * _n)), n(_n) {
  }

  inline void add(int x, int value_x) {
    assert(0 <= x && x < n);
    assert(0 <= value_x && value_x <= 1);
    g.add(2 * x + (value_x ^ 1), 2 * x + value_x);
  }
  
  inline void add(int x, int value_x, int y, int value_y) {
    assert(0 <= x && x < n && 0 <= y && y < n);
    assert(0 <= value_x && value_x <= 1 && 0 <= value_y && value_y <= 1);
    g.add(2 * x + (value_x ^ 1), 2 * y + value_y);
    g.add(2 * y + (value_y ^ 1), 2 * x + value_x);
  }

  inline vector<int> solve() {
    int cnt;
    vector<int> c = find_scc(g, cnt);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      if (c[2 * i] == c[2 * i + 1]) {
        return vector<int>();
      }
      res[i] = (c[2 * i] < c[2 * i + 1]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    twosat ts(n * (k + 1));
    for (int i = 0; i < n; i++) {
      ts.add(i * (k + 1) + 0, 0);
      ts.add(i * (k + 1) + k, 1);
      for (int j = 0; j < k; j++) {
        ts.add(i * (k + 1) + j, 0, i * (k + 1) + (j + 1), 1);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = 1; j < k; j++) {
        ts.add(i * (k + 1) + j, 1, (i + 1) * (k + 1) + j, 0);
      }
    }
    while (m--) {
      int op;
      cin >> op;
      if (op == 1) {
        int i, x;
        cin >> i >> x;
        --i;
        ts.add(i * (k + 1) + x - 1, 1, i * (k + 1) + x, 0);
      }
      if (op == 2) {
        int i, j, x;
        cin >> i >> j >> x;
        --i; --j;
        for (int p = 0; p <= k; p++) {
          int q = x - 1 - p;
          if (q >= 0 && q <= k) {
            ts.add(i * (k + 1) + p, 1, j * (k + 1) + q, 1);
          }
        }
      }
      if (op == 3) {
        int i, j, x;
        cin >> i >> j >> x;
        --i; --j;
        for (int p = 0; p <= k; p++) {
          int q = x - 1 - p;
          if (q >= 0 && q <= k) {
            ts.add(i * (k + 1) + p, 0, j * (k + 1) + q, 0);
          }
        }
      }
    }
    auto res = ts.solve();
    if (res.empty()) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= k; j++) {
        if (res[i * (k + 1) + j]) {
          a[i] = j;
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}