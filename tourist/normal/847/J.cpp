/**
 *    author:  tourist
 *    created: 18.09.2017 17:27:38       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class flow_graph {
  public:
  static constexpr T eps = (T) 1e-9;

  struct edge {
    int to;
    T c;
    T f;
    int rev;
  };

  vector < vector <edge> > g;
  vector <int> ptr;
  vector <int> d;
  int n;
  int st, fin;
  T flow;
   
  flow_graph(int n, int st, int fin) : n (n), st (st), fin (fin) {
    assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
    g.resize(n);
    ptr.resize(n);
    d.resize(n);
    flow = 0;
  }

  void clear_flow() {
    for (int i = 0; i < n; i++) {
      for (edge &e : g[i]) {
        e.f = 0;
      }
    }
    flow = 0;
  }
   
  void add(int from, int to, T forward_cap, T backward_cap = 0) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int from_size = g[from].size();
    int to_size = g[to].size();
    g[from].push_back({to, forward_cap, 0, to_size});
    g[to].push_back({from, backward_cap, 0, from_size});
  }
   
  bool expath() {
    queue <int> q({st});
    fill(d.begin(), d.end(), -1);
    d[st] = 0;
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      for (edge &e : g[i]) {
        if (e.c - e.f > eps && d[e.to] == -1) {
          d[e.to] = d[i] + 1;
          if (e.to == fin) {
            return true;
          }
          q.push(e.to);
        }
      }
    }
    return false;
  }
   
  T dfs(int v, T w) {
    if (v == fin) {
      return w;
    }
    int &j = ptr[v];
    while (j >= 0) {
      edge &e = g[v][j];
      if (e.c - e.f > eps && d[e.to] == d[v] + 1) {
        T t = dfs(e.to, min(e.c - e.f, w));
        if (t > eps) {
          e.f += t;
          g[e.to][e.rev].f -= t;
          return t;
        }
      }
      j--;
    }
    return 0;
  }

  T max_flow() {
    while (expath()) {
      for (int i = 0; i < n; i++) {
        ptr[i] = (int) g[i].size() - 1;
      }
      T big_add = 0;
      while (true) {
        T add = dfs(st, numeric_limits<T>::max());
        if (add <= eps) {
          break;
        }
        big_add += add;
      }
      if (big_add <= eps) {
        break;
      }
      flow += big_add;
    }
    return flow;
  }

  vector <bool> min_cut() {
    max_flow();
    vector <bool> ret(n);
    for (int i = 0; i < n; i++) {
      ret[i] = (d[i] != -1);
    }
    return ret;
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> x(m), y(m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x[i], &y[i]);
    x[i]--; y[i]--;
  }
  flow_graph<int> g(n + m + 2, 0, n + m + 1);
  for (int i = 0; i < n; i++) {
    g.add(0, i + 1, 0);
  }
  for (int i = 0; i < m; i++) {
    g.add(x[i] + 1, n + 1 + i, 1);
    g.add(y[i] + 1, n + 1 + i, 1);
  }
  for (int i = 0; i < m; i++) {
    g.add(n + 1 + i, n + 1 + m, 1);
  }
  int ans = 0;
  while (true) {
    int z = g.max_flow();
    if (z == m) {
      break;
    }
    for (auto &e : g.g[0]) {
      e.c++;
    }
    ans++;
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) {
    for (auto &e : g.g[i + 1]) {
      if (e.to >= n + 1 && e.f == 1) {
        printf("%d %d\n", i + 1, (x[e.to - n - 1] ^ y[e.to - n - 1] ^ i) + 1);
      }
    }
  }
  return 0;
}