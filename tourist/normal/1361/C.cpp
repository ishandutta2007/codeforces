/**
 *    author:  tourist
 *    created: 04.06.2020 17:49:08       
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
  vector<vector<int>> g;
  int n;

  graph(int _n) : n(_n) {
    g.resize(n);
  }

  virtual int add(int from, int to, T cost) = 0;
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
  vector<int> in_deg(g.n, 0);
  vector<int> out_deg(g.n, 0);
  int cnt_edges = 0;
  for (int id = 0; id < (int) g.edges.size(); id++) {
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
      if (used[id]) {
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
  // returns edge ids in the path (or the cycle if it exists)
  // root == -1 if there is no path
  // (or res.empty(), but this is also true when there are no edges)
}

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
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  for (int p = 20; p >= 0; p--) {
    int mask = (1 << p) - 1;
    dsu d(mask + 1);
    vector<int> deg(mask + 1);
    for (int i = 0; i < 2 * n; i += 2) {
      int x = a[i] & mask;
      int y = a[i + 1] & mask;
      d.unite(x, y);
      deg[x] += 1;
      deg[y] += 1;
    }
    bool ok = true;
    for (int i = 0; i <= mask; i++) {
      if (deg[i] & 1) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    int z = -1;
    for (int i = 0; i <= mask; i++) {
      if (deg[i] == 0) {
        continue;
      }
      int x = d.get(i);
      if (z == -1) {
        z = x;
      } else {
        if (z != x) {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      continue;
    }
    undigraph<int> g(mask + 1);
    for (int i = 0; i < 2 * n; i += 2) {
      int x = a[i] & mask;
      int y = a[i + 1] & mask;
      g.add(x, y);
    }
    int root = -1;
    auto path = find_eulerian_path(g, root);
    assert((int) path.size() == n);
    cout << p << '\n';
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      int j = path[i];
      int x = a[2 * j] & mask;
      int y = a[2 * j + 1] & mask;
      if (x == root) {
        cout << 2 * j + 1 << " " << 2 * j + 2;
        root = y;
      } else {
        assert(y == root);
        cout << 2 * j + 2 << " " << 2 * j + 1;
        root = x;
      }
    }
    cout << '\n';
    break;
  }
  return 0;
}