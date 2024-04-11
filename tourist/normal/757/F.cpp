/**
 *    author:  tourist
 *    created: 07.09.2017 15:04:54       
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

  virtual void unset_ignore_edge_rule() {
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

  digraph<T> reverse() {
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
vector <T> dijkstra(const graph<T> &g, int start) {
  assert(0 <= start && start < g.n);
  vector<T> dist(g.n, numeric_limits<T>::max());
  priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > s;
  dist[start] = 0;
  s.emplace(dist[start], start);
  while (!s.empty()) {
    T expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (dist[i] != expected) {
      continue;
    }
    for (int id : g.g[i]) {
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ i;
      if (dist[i] + e.cost < dist[to]) {
        dist[to] = dist[i] + e.cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist;
  // returns numeric_limits<T>::max() if there's no path
}

template <typename T>
vector<int> dominators(digraph<T> &g, int root) {
  int n = g.n;
  vector<int> pos(n, -1);
  vector<int> order;
  vector<int> parent(n, -1);
  function<void(int)> dfs = [&](int v) {
    pos[v] = (int) order.size();
    order.push_back(v);
    for (int id : g.g[v]) {
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
      auto &e = g.edges[id];
      int u = e.to;
      if (pos[u] == -1) {
        parent[u] = v;
        dfs(u);
      }
    }
  };
  dfs(root);
  vector<int> p(n), best(n);
  iota(p.begin(), p.end(), 0);
  iota(best.begin(), best.end(), 0);
  vector<int> sdom = pos;
  function<int(int)> find_best = [&](int x) {
    if (p[x] != x) {
      int u = find_best(p[x]);
      if (sdom[u] < sdom[best[x]]) {
        best[x] = u;
      }
      p[x] = p[p[x]];
    }
    if (sdom[best[p[x]]] < sdom[best[x]]) {
      best[x] = best[p[x]];
    }
    return best[x];
  };
  digraph<int> g_rev = g.reverse();
  vector<int> idom(n, -1);
  vector<int> link(n, 0);
  vector< vector<int> > bucket(n);
  for (int it = (int) order.size() - 1; it >= 0; it--) {
    int w = order[it];
    for (int id : g_rev.g[w]) {
      if (g_rev.ignore != nullptr && g_rev.ignore(id)) {
        continue;
      }
      auto &e = g_rev.edges[id];
      int u = e.to;
      sdom[w] = min(sdom[w], sdom[find_best(u)]);
    }
    idom[w] = order[sdom[w]];
    for (int u : bucket[w]) {
      link[u] = find_best(u);
    }
    for (int id : g.g[w]) {
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
      auto &e = g.edges[id];
      int u = e.to;
      if (parent[u] == w) {
        p[u] = w;
      }
    }
    bucket[order[sdom[w]]].push_back(w);
  }
  for (int it = 1; it < (int) order.size(); it++) {
    int w = order[it];
    idom[w] = idom[link[w]];
  }
  return idom;
  // idom[i] -- immediate dominator for vertex i
}

template <typename T>
vector<int> find_topsort(const digraph<T> &g) {
  vector<int> deg(g.n, 0);
  for (int id = 0; id < (int) g.edges.size(); id++) {
    if (g.ignore != nullptr && g.ignore(id)) {
      continue;
    }
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
      if (g.ignore != nullptr && g.ignore(id)) {
        continue;
      }
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
  int n, m, st;
  scanf("%d %d %d", &n, &m, &st);
  st--;
  undigraph<long long> gd(n);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    x--; y--;
    gd.add(x, y, z);
  }
  vector<long long> d = dijkstra(gd, st);
  digraph<int> g(n);
  const long long inf = numeric_limits<long long>::max();
  for (int i = 0; i < n; i++) {
    for (int id : gd.g[i]) {
      auto &e = gd.edges[id];
      int to = i ^ e.from ^ e.to;
      if (d[to] != inf && d[i] != inf && d[i] + e.cost == d[to]) {
        g.add(i, to);
      }
    }
  }
  vector<int> dom = dominators(g, st);
  vector<int> order = find_topsort(g);
  vector<int> who(n), dcnt(n);
  for (int i : order) {
    if (i == st || dom[i] == -1) {
      continue;
    }
    if (dom[i] == st) {
      who[i] = i;
    } else {
      who[i] = who[dom[i]];
    }
    dcnt[who[i]]++;
  }
  int mx = 0;
  for (int x : dcnt) {
    mx = max(mx, x);
  }
  printf("%d\n", mx);
  return 0;
}