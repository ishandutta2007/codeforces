/**
 *    author:  tourist
 *    created: 13.06.2021 18:58:29       
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  vector<int> a(w);
  for (int i = 0; i < w; i++) {
    cin >> a[i];
  }
  vector<vector<int>> id(h, vector<int>(w, -1));
  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        id[i][j] = cnt++;
      }
    }
  }
  vector<vector<int>> down(h, vector<int>(w, -1));
  for (int j = 0; j < w; j++) {
    for (int i = h - 1; i >= 0; i--) {
      if (id[i][j] != -1) {
        down[i][j] = id[i][j];
      } else {
        down[i][j] = (i == h - 1 ? -1 : down[i + 1][j]);
      }
    }
  }
  digraph<int> g(cnt);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (id[i][j] != -1) {
        if (i > 0 && id[i - 1][j] != -1) {
          g.add(id[i][j], id[i - 1][j]);
        }
        if (i < h - 1 && down[i + 1][j] != -1) {
          g.add(id[i][j], down[i + 1][j]);
        }
        if (j > 0 && down[i][j - 1] != -1) {
          g.add(id[i][j], down[i][j - 1]);
        }
        if (j < w - 1 && down[i][j + 1] != -1) {
          g.add(id[i][j], down[i][j + 1]);
        }
      }
    }
  }
  int cc = 0;
  auto comp = find_scc(g, cc);
  vector<vector<int>> g2(cc);
  for (auto& e : g.edges) {
    int x = comp[e.from];
    int y = comp[e.to];
    if (x != y) {
      g2[x].push_back(y);
    }
  }
  const int inf = (int) 1e9;
  vector<int> mn(cc, inf);
  vector<int> mx(cc, -inf);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int v = id[i][j];
      if (v != -1) {
        mn[comp[v]] = min(mn[comp[v]], j);
        mx[comp[v]] = max(mx[comp[v]], j);
      }
    }
  }    
  for (int i = 0; i < cc; i++) {
    for (int j : g2[i]) {
      mn[j] = min(mn[j], mn[i]);
      mx[j] = max(mx[j], mx[i]);
    }
  }
  vector<pair<int, int>> segs;
  for (int j = 0; j < w; j++) {
    if (a[j] == 0) {
      continue;
    }
    int aux = 0;
    for (int i = h - 1; i >= 0; i--) {
      int v = id[i][j];
      if (v != -1) {
        ++aux;
        if (aux == a[j]) {
          int L = mn[comp[v]];
          int R = mx[comp[v]];
          debug(L, R);
          segs.emplace_back(R, L);
          break;
        }
      }
    }
  }
  sort(segs.begin(), segs.end());
  int ans = 0;
  int last = -1;
  for (auto& p : segs) {
    if (p.second > last) {
      ++ans;
      last = p.first;
    }
  }
  cout << ans << '\n';
  return 0;
}