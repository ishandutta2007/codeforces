/**
 *    author:  tourist
 *    created: 21.12.2019 14:34:39       
**/
#undef _GLIBCXX_DEBUG

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
  // c[i] <= c[j] for every edge i -> j
}

const int N = 2010;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int backup = -1;
  {
    digraph<int> g(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == '1') {
          g.add(i, j);
        }
      }
    }
    int cnt = -1;
    vector<int> foo = find_scc(g, cnt);
    if (cnt == 1) {
      cout << "0 1" << '\n';
      return 0;
    }
    if (cnt == 2) {
      vector<int> cc(2, 0);
      for (int x : foo) {
        ++cc[x];
      }
      if (min(cc[0], cc[1]) == 1) {
        backup = 0;
      } else {
        backup = 2 * cc[0] * cc[1];
      }
    }
  }
  vector<bitset<N>> g(n);
  vector<bitset<N>> g_rev(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '1') {
        g[i].set(j);
        g_rev[j].set(i);
      }
    }
  }
  int ans = 0;
  for (int v = 0; v < n; v++) {
    for (int i = 0; i < n; i++) {
      if (i != v) {
        g[i].flip(v);
        g[v].flip(i);
        g_rev[i].flip(v);
        g_rev[v].flip(i);
      }
    }
    vector<int> order;
    bitset<N> alive;
    for (int i = 0; i < n; i++) {
      alive.set(i);
    }
    function<void(int)> Dfs1 = [&](int v) {
      alive.reset(v);
      while (true) {
        auto who = alive & g[v];
        int i = who._Find_first();
        if (0 <= i && i < n) {
          Dfs1(i);
        } else {
          break;
        }
      }
      order.push_back(v);
    };
    for (int i = 0; i < n; i++) {
      if (alive[i] == 1) {
        Dfs1(i);
      }
    }
    for (int i = 0; i < n; i++) {
      alive.set(i);
    }
    function<void(int)> Dfs2 = [&](int v) {
      alive.reset(v);
      while (true) {
        auto who = alive & g_rev[v];
        int i = who._Find_first();
        if (0 <= i && i < n) {
          Dfs2(i);
        } else {
          break;
        }
      }
    };
    Dfs2(order.back());
    if (alive.count() == 0) {
      ++ans;
    }
    for (int i = 0; i < n; i++) {
      if (i != v) {
        g[i].flip(v);
        g[v].flip(i);
        g_rev[i].flip(v);
        g_rev[v].flip(i);
      }
    }
  }
  if (ans > 0) {
    cout << "1 " << ans << '\n';
  } else {
    assert(backup != -1);
    if (backup == 0) {
      cout << -1 << '\n';
    } else {
      cout << "2 " << backup << '\n';
    }
  }
  return 0;
}