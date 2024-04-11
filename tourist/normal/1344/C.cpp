/**
 *    author:  tourist
 *    created: 06.05.2020 17:52:38       
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
  int n, m;
  cin >> n >> m;
  digraph<int> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g.add(x, y);
  }
  vector<int> order = find_topsort(g);
  if (order.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  string res(n, 'A');
  vector<int> mn(n);
  iota(mn.begin(), mn.end(), 0);
  for (int i : order) {
    for (int eid : g.g[i]) {
      auto& e = g.edges[eid];
      int j = e.to;
      mn[j] = min(mn[j], mn[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (mn[i] < i) {
      res[i] = 'E';
    }
  }
  iota(mn.begin(), mn.end(), 0);
  for (int i : vector<int>(order.rbegin(), order.rend())) {
    for (int eid : g.g[i]) {
      auto& e = g.edges[eid];
      int j = e.to;
      mn[i] = min(mn[i], mn[j]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (mn[i] < i) {
      res[i] = 'E';
    }
  }
  int ans = 0;
  for (char c : res) {
    ans += (c == 'A');
  }
  cout << ans << '\n';
  cout << res << '\n';
  return 0;
}