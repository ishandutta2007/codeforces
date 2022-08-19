/**
 *    author:  tourist
 *    created: 21.12.2019 15:33:45       
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
vector<vector<int>> find_cycles(const graph<T> &g, int bound_cnt = 1 << 30, int bound_size = 1 << 30) {
  vector<int> was(g.n, -1);
  vector<int> st;
  vector<vector<int>> cycles;
  int total_size = 0;
  function<void(int, int)> dfs = [&](int v, int pe) {
    if ((int) cycles.size() >= bound_cnt || total_size >= bound_size) {
      return;
    }
    was[v] = (int) st.size();
    for (int id : g.g[v]) {
      if (id == pe) {
        continue;
      }
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ v;
      if (was[to] >= 0) {
        vector<int> cycle(1, id);
        for (int j = was[to]; j < (int) st.size(); j++) {
          cycle.push_back(st[j]);
        }
        cycles.push_back(cycle);
        total_size += (int) cycle.size();
        if ((int) cycles.size() >= bound_cnt || total_size >= bound_size) {
          return;
        }
        continue;
      }
      if (was[to] == -1) {
        st.push_back(id);
        dfs(to, id);
        st.pop_back();
      }
    }
    was[v] = -2;
  };
  for (int i = 0; i < g.n; i++) {
    if (was[i] == -1) {
      dfs(i, -1);
    }
  }
  return cycles;
  // cycles are given by edge ids, all cycles are simple
  // breaks after getting bound_cnt cycles or total_size >= bound_size
  // digraph: finds at least one cycle in every connected component (if not broken)
  // undigraph: finds cycle basis
}

template <typename T>
vector<int> edges_to_vertices(const graph<T> &g, const vector<int> &edge_cycle) {
  int sz = (int) edge_cycle.size();
  vector<int> vertex_cycle;
  if (sz <= 2) {
    vertex_cycle.push_back(g.edges[edge_cycle[0]].from);
    if (sz == 2) {
      vertex_cycle.push_back(g.edges[edge_cycle[0]].to);
    }
  } else {
    for (int i = 0; i < sz; i++) {
      int j = (i + 1) % sz;
      auto &e = g.edges[edge_cycle[i]];
      auto &other = g.edges[edge_cycle[j]];
      if (other.from == e.from || other.to == e.from) {
        vertex_cycle.push_back(e.to);
      } else {
        vertex_cycle.push_back(e.from);
      }
    }
  }
  return vertex_cycle;
  // only for simple cycles!
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  undigraph<int> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g.add(x, y);
  }
  vector<vector<int>> cycles = find_cycles(g);
  vector<vector<int>> events(m);
  for (auto& cycle : cycles) {
    int sz = (int) cycle.size();
    int pos = (int) (min_element(cycle.begin(), cycle.end()) - cycle.begin());
    rotate(cycle.begin(), cycle.begin() + pos, cycle.end());
    pos = (int) (max_element(cycle.begin(), cycle.end()) - cycle.begin());
    bool ok = true;
    for (int i = 0; i < pos - 1; i++) {
      if (cycle[i] > cycle[i + 1]) {
        ok = false;
        break;
      }
    }
    for (int i = pos; i < sz - 1; i++) {
      if (cycle[i] < cycle[i + 1]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      events[cycle[pos]].push_back(cycle[0]);
    }
  }
  vector<int> sub(m, 0);
  vector<int> ans(n, 1);
  for (int i = m - 1; i >= 0; i--) {
    auto& e = g.edges[i];
    int x = e.from;
    int y = e.to;
    int cur = ans[x] + ans[y] - sub[i];
    ans[x] = ans[y] = cur;
    for (int j : events[i]) {
      sub[j] += cur;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i] - 1;
  }
  cout << '\n';
  return 0;
}