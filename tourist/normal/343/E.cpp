/**
 *    author:  tourist
 *    created: 09.10.2017 14:20:34       
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

  vector< vector<edge> > g;
  vector<int> ptr;
  int d[202];
  vector<int> q;
  int n;
  int st, fin;
  T flow;
   
  flow_graph(int n, int st, int fin) : n(n), st(st), fin(fin) {
    assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
    g.resize(n);
    ptr.resize(n);
    q.resize(n);
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
   
  void add(int from, int to, T forward_cap, T backward_cap) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int from_size = g[from].size();
    int to_size = g[to].size();
    g[from].push_back({to, forward_cap, 0, to_size});
    g[to].push_back({from, backward_cap, 0, from_size});
  }

  bool expath() {
    memset(d, -1, n * sizeof(int));
    q[0] = st;
    d[st] = 0;
    int beg = 0, end = 1;
    while (beg < end) {
      int i = q[beg];
      for (const edge &e : g[i]) {
        if (e.c - e.f > eps && d[e.to] == -1) {
          d[e.to] = d[i] + 1;
          if (e.to == fin) {
            return true;
          }
          q[end++] = e.to;
        }
      }
      beg++;
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

  vector<bool> min_cut() {
    max_flow();
    vector<bool> ret(n);
    for (int i = 0; i < n; i++) {
      ret[i] = (d[i] != -1);
    }
    return ret;
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  flow_graph<int> g(n, 0, 1);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    x--; y--;
    g.add(x, y, z, z);
  }
  vector< vector<int> > a(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      g.clear_flow();
      g.st = i;
      g.fin = j;
      a[i][j] = a[j][i] = g.max_flow();
    }
  }
  vector<bool> used(n, false);
  vector<int> ans(1, 0);
  used[ans[0]] = true;
  int sum = 0;
  for (int it = 0; it < n - 1; it++) {
    int best = -1, id = -1;
    for (int i = 0; i < n; i++) {
      if (!used[i] && a[ans.back()][i] > best) {
        best = a[ans.back()][i];
        id = i;
      }
    }
    used[id] = true;
    ans.push_back(id);
    sum += best;
  }
  printf("%d\n", sum);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", ans[i] + 1);
  }
  printf("\n");
  return 0;
}