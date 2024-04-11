/**
 *  author: milos
 *  created: 05.01.2021 06:06:03
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
vector<int> find_topsort(const digraph<T> &g) {
  vector<int> deg(g.n, 0);
  for (int id = 0; id < (int) g.edges.size(); id++) {
    deg[g.edges[id].to]++;
  }
  vector<int> x;
  for (int i = 0; i < g.n; i++) {
    if (deg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) x.size(); ptr++) {
    int i = x[ptr];
    for (int id : g.g[i]) {
      auto &e = g.edges[id];
      int to = e.to;
      if (--deg[to] == 0) {
        x.push_back(to);
      }
    }
  }
  if ((int) x.size() != g.n) {
    return vector<int>();
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m), z(m);
    digraph<int> g(n);
    for (int i = 0; i < m; i++) {
      cin >> x[i] >> y[i] >> z[i];
      --y[i], --z[i];
      if (x[i] == 1) {
        g.add(y[i], z[i]);  
      }
    }
    auto p = find_topsort(g);
    if (p.empty()) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      vector<int> pos(n);
      for (int i = 0; i < n; i++) {
        pos[p[i]] = i;
      }
      for (int i = 0; i < m; i++) {
        if (x[i] == 0 && pos[y[i]] > pos[z[i]]) {
          swap(y[i], z[i]);
        }
        cout << y[i] + 1 << " " << z[i] + 1 << '\n';
      }
    }
  }
  return 0;
}