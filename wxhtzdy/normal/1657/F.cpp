/**
 *    author:  wxhtzdy
 *    created: 15.06.2022 16:12:34
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  vector<edge> edges;
  vector< vector<int> > g;
  int n;
  function<bool(int)> ignore;
  graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }
  virtual int add(int from, int to, T cost) = 0;
  virtual void set_ignore_edge_rule(const function<bool(int)> &f) {
    ignore = f;
  }
  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class digraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  using graph<T>::ignore;
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
    if (ignore != nullptr) {
      rev.set_ignore_edge_rule([&](int id) {
        return ignore(id);
      });
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
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
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
      if (g_rev.ignore != nullptr && g_rev.ignore(id)) {
        continue;
      }
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
  // c[i] <= c[j] for every edge i -> j
}

class twosat {
  public:
  digraph<int> g;
  int n;
  twosat(int _n) : g(digraph<int>(2 * _n)), n(_n) {
  }
  inline void add(int x, int value_x) {
    // (v[x] == value_x)
    assert(0 <= x && x < n);
    assert(0 <= value_x && value_x <= 1);
    g.add(2 * x + (value_x ^ 1), 2 * x + value_x);
  }
  
  inline void add(int x, int value_x, int y, int value_y) {
    // (v[x] == value_x || v[y] == value_y)
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
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  const int L = 20;
  vector<int> dep(n);    
  vector<vector<int>> pr(n, vector<int>(L));
  function<void(int, int)> Dfs = [&](int v, int p) {
    pr[v][0] = p;
    dep[v] = dep[p] + 1;
    for (int u : g[v]) {
      if (u != p) {
        Dfs(u, v);
      }
    }
  };
  Dfs(0, 0);
  for (int j = 1; j < L; j++) {
    for (int i = 0; i < n; i++) {
      pr[i][j] = pr[pr[i][j - 1]][j - 1];
    }
  }                         
  auto Lca = [&](int u, int v) {
    if (dep[u] > dep[v]) {
      swap(u, v);
    }
    for (int i = L - 1; i >= 0; i--) {
      if ((dep[v] - dep[u]) >> i & 1) {
        v = pr[v][i];
      }
    }
    for (int i = L - 1; i >= 0; i--) {
      if (pr[u][i] != pr[v][i]) {
        u = pr[u][i];
        v = pr[v][i];
      }
    }
    return (u == v ? v : pr[v][0]);
  };
  vector<int> x(q);
  vector<int> y(q);
  vector<string> s(q);
  for (int i = 0; i < q; i++) {
    cin >> x[i] >> y[i] >> s[i];
    --x[i]; --y[i];
  }            
  vector<char> a(n, 'a');
  vector<char> b(n, 'a');
  vector<int> vis(n);
  twosat ts(n + q);
  for (int i = 0; i < q; i++) {
    int l = Lca(x[i], y[i]);
    vector<int> path;
    {
      int j = x[i];
      while (j != l) {
        path.push_back(j);
        j = pr[j][0];
      }
      path.push_back(l);
    }  
    {
      int j = y[i];
      vector<int> tmp;
      while (j != l) {
        tmp.push_back(j);
        j = pr[j][0];
      }
      reverse(tmp.begin(), tmp.end());
      for (int p : tmp) {
        path.push_back(p);
      }
    }
    assert(s[i].size() == path.size());
    int m = (int) s[i].size();
    for (int j = 0; j < m; j++) {
      int t = path[j];
      if (!vis[t]) {
        a[t] = s[i][j];
        b[t] = s[i][m - j - 1];  
        vis[t] = 1;
      }
      if (a[t] != s[i][j]) {
        ts.add(t, 1, n + i, 1);
      }
      if (b[t] != s[i][j]) {
        ts.add(t, 0, n + i, 1); 
      }
      if (a[t] != s[i][m - j - 1]) {
        ts.add(t, 1, n + i, 0);
      }
      if (b[t] != s[i][m - j - 1]) {
        ts.add(t, 0, n + i, 0); 
      }
    }
  }
  auto res = ts.solve();
  if (res.empty()) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    cout << (res[i] == 0 ? a[i] : b[i]);
  }
  return 0;
}