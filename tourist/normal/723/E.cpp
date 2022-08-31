/**
 *    author:  tourist
 *    created: 11.11.2017 22:33:47       
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
class undigraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
vector<int> find_eulerian_path(const graph<T> &g, int &root) {
  // in_deg and out_deg are fake for undigraph!
  vector<int> in_deg(g.n, 0);
  vector<int> out_deg(g.n, 0);
  int cnt_edges = 0;
  for (int id = 0; id < (int) g.edges.size(); id++) {
    if (g.ignore != nullptr && g.ignore(id)) {
      continue;
    }
    cnt_edges++;
    auto &e = g.edges[id];
    out_deg[e.from]++;
    in_deg[e.to]++;
  }
  root = -1;
  int odd = 0;
  for (int i = 0; i < g.n; i++) {
    if ((in_deg[i] + out_deg[i]) % 2 == 1) {
      odd++;
      if (root == -1 || out_deg[i] - in_deg[i] > out_deg[root] - in_deg[root]) {
        root = i;
      }
    }
  }
  if (odd > 2) {  
    root = -1;
    return vector<int>();
  }
  if (root == -1) {
    root = 0;
    while (root < g.n && in_deg[root] + out_deg[root] == 0) {
      root++;
    }
    if (root == g.n) {
      // an empty path
      root = 0;
      return vector<int>();
    }
  }
  vector<bool> used(g.edges.size(), false);
  vector<int> ptr(g.n, 0);
  vector<int> balance(g.n, 0);
  vector<int> res(cnt_edges);
  int stack_ptr = 0;
  int write_ptr = cnt_edges;
  int v = root;
  while (true) {
    bool found = false;
    while (ptr[v] < (int) g.g[v].size()) {
      int id = g.g[v][ptr[v]++];
      if (used[id] || (g.ignore != nullptr && g.ignore(id))) {
        continue;
      }
      used[id] = true;
      res[stack_ptr++] = id;
      auto &e = g.edges[id];
      balance[v]++;
      v ^= e.from ^ e.to;
      balance[v]--;
      found = true;
      break;
    }
    if (!found) {
      if (stack_ptr == 0) {
        break;
      }
      int id = res[--stack_ptr];
      res[--write_ptr] = id;
      auto &e = g.edges[id];
      v ^= e.from ^ e.to;
    }
  }
  int disbalance = 0;
  for (int i = 0; i < g.n; i++) {
    disbalance += abs(balance[i]);
  }
  if (write_ptr != 0 || disbalance > 2) {
    root = -1;
    return vector<int>();
  }
  return res;
  // root == -1 if there is no path
  // (or res.empty(), but this is also true when there are no edges)
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d %d", &n, &m);
    undigraph<int> g(n + 1);
    vector<int> deg(n, 0);
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      x--; y--;
      g.add(x, y);
      deg[x]++;
      deg[y]++;
    }
    int v = -1;
    int bad = 0;
    for (int i = 0; i < n; i++) {
      if (deg[i] % 2 == 1) {
        bad++;
        if (v == -1) {
          v = i;
        } else {
          g.add(v, i);
          v = -1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      g.add(n, i);
      g.add(n, i);
    }
    int root;
    vector<int> res = find_eulerian_path(g, root);
    assert(!res.empty());
    printf("%d\n", n - bad);
    v = root;
    for (int id : res) {
      auto &e = g.edges[id];
      int new_v = v ^ e.from ^ e.to;
      if (id < m) {
        printf("%d %d\n", v + 1, new_v + 1);
      }
      v = new_v;
    }
  }
  return 0;
}