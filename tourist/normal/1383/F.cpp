/**
 *    author:  tourist
 *    created: 24.07.2020 18:51:48       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
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

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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

template <typename T>
class flow_graph {
 public:
  static constexpr T eps = (T) 1e-9;

  struct edge {
    int from;
    int to;
    T c;
    T f;
  };

  vector<vector<int>> g;
  vector<edge> edges;
  int n;
  int st;
  int fin;
  T flow;

  flow_graph(int _n, int _st, int _fin) : n(_n), st(_st), fin(_fin) {
    assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
    g.resize(n);
    flow = 0;
  }

  void clear_flow() {
    for (const edge &e : edges) {
      e.f = 0;
    }
    flow = 0;
  }
   
  int add(int from, int to, T forward_cap, T backward_cap) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, forward_cap, 0});
    g[to].push_back(id + 1);
    edges.push_back({to, from, backward_cap, 0});
    return id;
  }
};

template <typename T>
class dinic {
 public:
  flow_graph<T> &g;

  vector<int> ptr;
  vector<int> d;
  vector<int> q;

  dinic(flow_graph<T> &_g) : g(_g) {
    ptr.resize(g.n);
    d.resize(g.n);
    q.resize(g.n);
  }

  bool expath() {
    fill(d.begin(), d.end(), -1);
    q[0] = g.fin;
    d[g.fin] = 0;
    int beg = 0, end = 1;
    while (beg < end) {
      int i = q[beg++];
      for (int id : g.g[i]) {
        const auto &e = g.edges[id];
        const auto &back = g.edges[id ^ 1];
        if (back.c - back.f > g.eps && d[e.to] == -1) {
          d[e.to] = d[i] + 1;
          if (e.to == g.st) {
            return true;
          }
          q[end++] = e.to;
        }
      }
    }
    return false;
  }
   
  T dfs(int v, T w) {
    if (v == g.fin) {
      return w;
    }
    int &j = ptr[v];
    while (j >= 0) {
      int id = g.g[v][j];
      const auto &e = g.edges[id];
      if (e.c - e.f > g.eps && d[e.to] == d[v] - 1) {
        T t = dfs(e.to, min(e.c - e.f, w));
        if (t > g.eps) {
          g.edges[id].f += t;
          g.edges[id ^ 1].f -= t;
          return t;
        }
      }
      j--;
    }
    return 0;
  }

  T max_flow() {
    while (expath()) {
      for (int i = 0; i < g.n; i++) {
        ptr[i] = (int) g.g[i].size() - 1;
      }
      T big_add = 0;
      while (true) {
        T add = dfs(g.st, numeric_limits<T>::max());
        if (add <= g.eps) {
          break;
        }
        big_add += add;
      }
      if (big_add <= g.eps) {
        break;
      }
      g.flow += big_add;
    }
    return g.flow;
  }

  vector<bool> min_cut() {
    max_flow();
    vector<bool> ret(g.n);
    for (int i = 0; i < g.n; i++) {
      ret[i] = (d[i] != -1);
    }
    return ret;
  }
};

const int MAXC = 25;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  flow_graph<int> g(n, 0, n - 1);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    g.add(x, y, z, 0);
  }
  dinic<int> d(g);
  vector<vector<int>> backup(1 << k, vector<int>(2 * m));
  vector<int> backup_flow(1 << k);
  vector<int> without(1 << k, 0);
  without.back() = d.max_flow();
  for (int i = 0; i < 2 * m; i++) {
    backup.back()[i] = g.edges[i].f;
  }
  backup_flow.back() = g.flow;
  for (int t = (1 << k) - 2; t >= 0; t--) {
//    debug(t);
    for (int id = 0; id < k; id++) {
      if (!(t & (1 << id))) {
//        debug(id);
        for (int i = 0; i < 2 * m; i++) {
          g.edges[i].f = backup[t | (1 << id)][i];
        }
        for (int i = 0; i < k; i++) {
          g.edges[2 * i].c = ((t & (1 << i)) ? 0 : MAXC);
        }
        g.flow = backup_flow[t | (1 << id)];
//        for (int i = 0; i < 2 * m; i++) debug(g.edges[i].from, g.edges[i].to, g.edges[i].c, g.edges[i].f);
        without[t] = d.max_flow();
//        debug(t, without[t]);
        for (int i = 0; i < 2 * m; i++) {
          backup[t][i] = g.edges[i].f;
        }
        backup_flow[t] = g.flow;
        break;
      }
    }
  }
//  debug(without);
  vector<int> cap(k);
  vector<int> sum(1 << k);
  while (q--) {
    for (int i = 0; i < k; i++) {
      cin >> cap[i];
    }
    sum[0] = 0;
    for (int t = 1; t < (1 << k); t++) {
      int bit = __builtin_ctz(t);
      sum[t] = sum[t ^ (1 << bit)] + cap[bit];
    }
    int ans = 787788789;
    for (int t = 0; t < (1 << k); t++) {
      ans = min(ans, sum[t] + without[t]);
    }
    cout << ans << '\n';
  }
  return 0;
}