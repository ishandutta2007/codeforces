/**
 *    author:  tourist
 *    created: 29.05.2018 19:57:11       
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int md = (int) 1e9 + 7;

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
  return (int) ((long long) a * b % md);
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

inline int power(int a, long long b) {
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

  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class forest : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  forest(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
class dfs_forest : public forest<T> {
  public:
  using forest<T>::edges;
  using forest<T>::g;
  using forest<T>::n;
  using forest<T>::ignore;

  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pos;
  vector<int> end;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<T> dist;

  dfs_forest(int _n) : forest<T>(_n) {
  }

  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pos = vector<int>(n, -1);
    end = vector<int>(n, -1);
    sz = vector<int>(n, 0);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n);
  }

  void clear() {
    pv.clear();
    pe.clear();
    order.clear();
    pos.clear();
    end.clear();
    sz.clear();
    root.clear();
    depth.clear();
    dist.clear();
  }

  private:
  void do_dfs(int v) {
    pos[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v] || (ignore != nullptr && ignore(id))) {
        continue;
      }
      auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
    }
    end[v] = (int) order.size() - 1;
  }

  void do_dfs_from(int v) {
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }

  public:
  void dfs(int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else {
      if (clear_order) {
        order.clear();
      }
    }
    do_dfs_from(v);
  }

  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
  }
};

template <typename T>
class lca_forest : public dfs_forest<T> {
  public:
  using dfs_forest<T>::edges;
  using dfs_forest<T>::g;
  using dfs_forest<T>::n;
  using dfs_forest<T>::pv;
  using dfs_forest<T>::pos;
  using dfs_forest<T>::end;
  using dfs_forest<T>::depth;

  int h;
  vector< vector<int> > pr;

  lca_forest(int _n) : dfs_forest<T>(_n) {
  }

  inline void build_lca() {
    assert(!pv.empty());
    int max_depth = 0;
    for (int i = 0; i < n; i++) {
      max_depth = max(max_depth, depth[i]);
    }
    h = 1;
    while ((1 << h) <= max_depth) {
      h++;
    }
    pr.resize(n);
    for (int i = 0; i < n; i++) {
      pr[i].resize(h);
      pr[i][0] = pv[i];
    }
    for (int j = 1; j < h; j++) {
      for (int i = 0; i < n; i++) {
        pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
      }
    }
  }

  inline bool anc(int x, int y) {
    return (pos[x] <= pos[y] && end[y] <= end[x]);
  }

  inline int lca(int x, int y) {
    // maybe optimize?
    // if depth[x] > depth[y], swap
    // then go from j = log(depth[x])?
    assert(!pr.empty());
    if (anc(x, y)) {
      return x;
    }
    if (anc(y, x)) {
      return y;
    }
    for (int j = h - 1; j >= 0; j--) {
      if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
        x = pr[x][j];
      }
    }
    return pr[x][0];
  }
};

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = (int) 1e7 + 10;
  vector<int> prime_div(MAX);
  for (int i = 0; i < MAX; i++) {
    prime_div[i] = i;
  }
  for (int i = 2; i * i < MAX; i++) {
    if (prime_div[i] == i) {
      for (int j = i * i; j < MAX; j += i) {
        if (prime_div[j] == j) {
          prime_div[j] = i;
        }
      }
    }
  }
  vector<int> pos(MAX);
  vector<int> primes;
  for (int i = 2; i < MAX; i++) {
    if (prime_div[i] == i) {
      pos[i] = (int) primes.size();
      primes.push_back(i);
    }
  }
  vector<vector<pair<int,int>>> at(primes.size());
  int n;
  cin >> n;
  lca_forest<int> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g.add(x, y);
  }
  g.dfs(0);
  g.build_lca();
  for (int i = 0; i < n; i++) {
    int foo;
    cin >> foo;
    while (foo > 1) {
      int d = prime_div[foo];
      int cc = 0;
      while (foo % d == 0) {
        foo /= d;
        cc++;
      }
      at[pos[d]].emplace_back(cc, i);
    }
  }
  int tt;
  cin >> tt;
  vector<int> u(tt), v(tt), lca(tt);
  vector<int> res(tt, 1);
  for (int i = 0; i < tt; i++) {
    int foo;
    cin >> u[i] >> v[i] >> foo;
    u[i]--; v[i]--;
    lca[i] = g.lca(u[i], v[i]);
    while (foo > 1) {
      int d = prime_div[foo];
      int cc = 0;
      while (foo % d == 0) {
        foo /= d;
        cc++;
      }
      for (int j = 1; j <= cc; j++) {
        at[pos[d]].emplace_back(j, ~i);
      }
    }
  }
  fenwick<int> fenw(n);
  for (int it = 0; it < (int) primes.size(); it++) {
    if (at[it].empty()) {
      continue;
    }
    sort(at[it].rbegin(), at[it].rend());
    for (auto &p : at[it]) {
      int id = p.second;
      if (id >= 0) {
        fenw.modify(g.pos[id], 1);
        fenw.modify(g.end[id] + 1, -1);
      } else {
        id = ~id;
        int cnt = fenw.get(g.pos[u[id]]) + fenw.get(g.pos[v[id]]) - fenw.get(g.pos[lca[id]]);
        if (lca[id] != 0) {
          cnt -= fenw.get(g.pos[g.pv[lca[id]]]);
        }
        res[id] = mul(res[id], power(primes[it], cnt));
      }
    }
    for (auto &p : at[it]) {
      int id = p.second;
      if (id >= 0) {
        fenw.modify(g.pos[id], -1);
        fenw.modify(g.end[id] + 1, +1);
      }
    }
  }
  for (int i = 0; i < tt; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}