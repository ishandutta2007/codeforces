/**
 *    author:  tourist
 *    created: 03.09.2017 13:43:08       
**/
#include <bits/stdc++.h>

using namespace std;

template <class T> class flow_graph {
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
  bool modified;
   
  flow_graph(int n, int st, int fin) : n (n), st (st), fin (fin) {
    modified = true;
    assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
    g.resize(n);
    ptr.resize(n);
    d.resize(n);
  }

  void clear_flow() {
    modified = true;
    for (int i = 0; i < n; i++) {
      for (edge &e : g[i]) {
        e.f = 0;
      }
    }
  }
   
  void add(int from, int to, T forward_cap, T backward_cap) {
    modified = true;
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
        if (e.c > e.f + eps && d[e.to] == -1) {
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
    T r = 0;
    int j = ptr[v];
    while (j > 0) {
      j--;
      edge &e = g[v][j];
      if (e.c > e.f + eps && d[e.to] == d[v] + 1) {
        T ww = e.c - e.f;
        if (v != st) {
          ww = min(ww, w - r);
        }
        T t = dfs(e.to, ww);
        if (t > 0) {
          e.f += t;
          g[e.to][e.rev].f -= t;
          r += t;
          if (v != st && r >= w - eps) {
            return r;
          }
        }
      }
      ptr[v]--;
    }
    return r;
  }

  T flow;

  T max_flow() {
    if (!modified) {
      return flow;
    }
    modified = false;
    T ans = 0;
    while (expath()) {
      for (int i = 0; i < n; i++) {
        ptr[i] = g[i].size();
      }
      T add = dfs(st, -1);
      if (add <= eps) {
        break;
      }
      ans += add;
    }
    return flow = ans;
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

const int N = 1234;

int city[N];
int g[N][N];

int main() {
  int v, e, n, k;
  scanf("%d %d %d %d", &v, &e, &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", city + i);
    city[i]--;
  }
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      g[i][j] = (i == j ? 0 : (int) 1e9);
    }
  }
  for (int i = 0; i < e; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    x--; y--;
    g[x][y] = min(g[x][y], z);
    g[y][x] = min(g[y][x], z);
  }
  for (int k = 0; k < v; k++) {
    for (int i = 0; i < v; i++) {
      for (int j = 0; j < v; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  const int inf = (int) 2e6;
  int low = 0, high = inf;
  while (low < high) {
    int mid = (low + high) >> 1;
    flow_graph <int> gr(n + v + 2, n + v, n + v + 1);
    for (int i = 0; i < n; i++) {
      gr.add(n + v, i, 1, 0);
    }
    for (int j = 0; j < v; j++) {
      gr.add(n + j, n + v + 1, 1, 0);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < v; j++) {
        if (g[city[i]][j] <= mid) {
          gr.add(i, n + j, 1, 0);
        }
      }
    }
    if (gr.max_flow() >= k) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  printf("%d\n", low == inf ? -1 : low);
  return 0;
}