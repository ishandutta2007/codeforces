/**
 *    author:  tourist
 *    created: 26.09.2017 21:41:25       
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

  vector <edge> edges;
  vector < vector <int> > g;
  int n;

  graph(int n) : n(n) {
    g.resize(n);
  }

  virtual void add(int from, int to, T cost) = 0;
};

template <typename T>
class undigraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int n) : graph<T>(n) {
  }

  void add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    g[from].push_back(edges.size());
    g[to].push_back(edges.size());
    edges.push_back({from, to, cost});
  }
};

class dsu {
  public:
  vector <int> p;
  int n;

  dsu(int n) : n(n) {
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

template <typename T>
vector< vector<int> > find_cycles(const graph<T> &g, int bound = 1 << 30) {
  vector<int> was(g.n, -1);
  vector<int> st;
  vector< vector<int> > cycles;
  function<void(int, int)> dfs = [&g, &was, &st, &cycles, &dfs, &bound](int v, int pe) {
    if ((int) cycles.size() >= bound) {
      return;
    }
    was[v] = st.size();
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
        if ((int) cycles.size() >= bound) {
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
  // returns at most bound cycles (given by edge ids)
  // digraph: finds at least one cycle in every connected component
  // undigraph: finds cycle basis
}

const int md = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
#if !defined(_WIN32) || defined(_WIN64)
  return (long long) a * b % md;
#endif
  unsigned long long x = (long long) a * b;
  unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
  asm(
    "divl %4; \n\t"
    : "=a" (d), "=d" (m)
    : "d" (xh), "a" (xl), "r" (md)
  );
  return m;
}

inline int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

int main() {
  int n;
  scanf("%d", &n);
  n *= 2;
  undigraph<int> g(n);
  dsu d(n);
  for (int i = 0; i < n / 2; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    g.add(x, y);
    d.unite(x, y);
  }
  vector<int> coeff(n, 0);
  for (int i = 0; i < n; i++) {
    coeff[d.get(i)]++;
  }
  vector< vector<int> > cycles = find_cycles(g);
  for (auto &cycle : cycles) {
    auto &e = g.edges[cycle[0]];
    coeff[d.get(e.from)] = min((int) cycle.size(), 2);
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (coeff[i] != 0) {
      ans = mul(ans, coeff[i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}