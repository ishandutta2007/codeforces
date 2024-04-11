/**
 *    author:  tourist
 *    created: 31.08.2017 20:36:40       
**/
#include <bits/stdc++.h>

using namespace std;

template <class T> class flow_graph {
  public:
  static const T eps = (T) 1e-9;

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

  void clear() {
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
      ans += dfs(st, -1);
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

const int inf = (int) 1e9;

const int N = 1234567;

int from[N], to[N], flag[N];

int main() {
  int n, m, st, fin;
  scanf("%d %d %d %d", &n, &m, &st, &fin);
  st--; fin--;
  flow_graph <int> g(n, st, fin);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", from + i, to + i, flag + i);
    from[i]--; to[i]--;
    if (flag[i] == 1) {
      g.add(from[i], to[i], 1, inf);
    } else {
      g.add(from[i], to[i], inf, 0);
    }
  }
  cout << g.max_flow() << endl;
  vector <bool> cut = g.min_cut();
  flow_graph <int> g2(n + 2, n, n + 1);
  for (int i = 0; i < m; i++) {
    if (!flag[i]) {
      continue;
    }
    g2.add(n, to[i], 1, 0);
    g2.add(from[i], n + 1, 1, 0);
    g2.add(from[i], to[i], inf - 2, 0);
  }
  g2.add(fin, st, inf, 0);
  g2.max_flow();
  map < pair <int, int>, int > mp;
  for (int i = 0; i < n; i++) {
    for (auto &e : g2.g[i]) {
      if (i != fin && e.to != st && e.f > 0) {
        mp[make_pair(i, e.to)] += e.f;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (!flag[i]) {
      printf("%d %d\n", 0, 1);
      continue;
    }
    int f = 1 + mp[make_pair(from[i], to[i])];
    int c = (cut[from[i]] == cut[to[i]] ? inf : f);
    printf("%d %d\n", f, c);
  }
  return 0;
}