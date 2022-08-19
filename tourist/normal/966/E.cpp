/**
 *    author:  tourist
 *    created: 29.04.2018 16:44:37       
**/
#undef _GLIBCXX_DEBUG

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
class hld_forest : public lca_forest<T> {
  public:
  using lca_forest<T>::edges;
  using lca_forest<T>::g;
  using lca_forest<T>::n;
  using lca_forest<T>::ignore;
  using lca_forest<T>::pv;
  using lca_forest<T>::sz;
  using lca_forest<T>::pos;
  using lca_forest<T>::order;
  using lca_forest<T>::depth;
  using lca_forest<T>::dfs;
  using lca_forest<T>::dfs_all;
  using lca_forest<T>::lca;
  using lca_forest<T>::build_lca;

  vector<int> head;
  vector<int> visited;

  hld_forest(int _n) : lca_forest<T>(_n) {
    visited.resize(n);
  }

  void build_hld(const vector<int> &vs) {
    for (int tries = 0; tries < 2; tries++) {
      if (vs.empty()) {
        dfs_all();
      } else {
        order.clear();
        for (int v : vs) {
//          assert(depth[v] == -1);
          dfs(v, false);
        }
        assert((int) order.size() == n);
      }
      if (tries == 1) {
        break;
      }
      for (int i = 0; i < n; i++) {
        if (g[i].empty()) {
          continue;
        }
        int best = -1, bid = 0;
        for (int j = 0; j < (int) g[i].size(); j++) {
          int id = g[i][j];
          if (ignore != nullptr && ignore(id)) {
            continue;
          }
          int v = edges[id].from ^ edges[id].to ^ i;
          if (pv[v] != i) {
            continue;
          }
          if (sz[v] > best) {
            best = sz[v];
            bid = j;
          }
        }
        swap(g[i][0], g[i][bid]);
      }
    }
    build_lca();
    head.resize(n);
    for (int i = 0; i < n; i++) {
      head[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
      int x = order[i];
      int y = order[i + 1];
      if (pv[y] == x) {
        head[y] = head[x];
      }
    }
  }

  void build_hld(int v) {
    build_hld(vector<int>(1, v));
  }

  void build_hld_all() {
    build_hld(vector<int>());
  }

  bool apply_on_path(int x, int y, bool with_lca, function<void(int,int,bool)> f) {
    // f(x, y, up): up -- whether this part of the path goes up
    assert(!head.empty());
    int z = lca(x, y);
    if (z == -1) {
      return false;
    }
    {
      int v = x;
      while (v != z) {
        if (depth[head[v]] <= depth[z]) {
          f(pos[z] + 1, pos[v], true);
          break;
        }
        f(pos[head[v]], pos[v], true);
        v = pv[head[v]];
      }
    }
    if (with_lca) {
      f(pos[z], pos[z], false);
    }
    {
      int v = y;
      int cnt_visited = 0;
      while (v != z) {
        if (depth[head[v]] <= depth[z]) {
          f(pos[z] + 1, pos[v], false);
          break;
        }
        visited[cnt_visited++] = v;
        v = pv[head[v]];
      }
      for (int at = cnt_visited - 1; at >= 0; at--) {
        v = visited[at];
        f(pos[head[v]], pos[v], false);
      }
    }
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  hld_forest<int> g(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    g.add(p, i);
  }
  g.build_hld(0);
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    int foo;
    cin >> foo;
    t[g.pos[i]] = foo;
  }
  vector<int> otp(n, 0);
  const int BLOCK = max(1, (int) sqrt(n) / 3);
  int cnt = (n - 1) / BLOCK + 1;
  vector<int> bid(n);
  for (int i = 0; i < n; i++) {
    bid[i] = i / BLOCK;
  }
  vector< vector< pair<int,int> > > sorted(cnt);
  vector<int> add_to(cnt, 0);
  auto pull = [&](int id) {
    sorted[id].clear();
    for (int i = id * BLOCK; i < min(n, (id + 1) * BLOCK); i++) {
      sorted[id].emplace_back(t[i], i);
    }
    sort(sorted[id].begin(), sorted[id].end());
  };
  auto push = [&](int id) {
    for (int i = id * BLOCK; i < min(n, (id + 1) * BLOCK); i++) {
      t[i] += add_to[id];
    }
    add_to[id] = 0;
  };
  auto modify = [&](int from, int to, int value) {
    from = max(from, 0);
    to = min(to, n - 1);
    if (from > to) {
      return;
    }
    int id_from = bid[from];
    int id_to = bid[to];
    push(id_from);
    if (id_to != id_from) {
      push(id_to);
    }
    int init_from = from, init_to = to;
    while (from <= to && bid[from] == id_from) {
      t[from] += value;
      from++;
    }
    while (from <= to && bid[to] == id_to) {
      t[to] += value;   
      to--;
    }
    for (int id = id_from + 1; id <= id_to - 1; id++) {
      add_to[id] += value;
    }
    for (int rot = 0; rot < 2; rot++) {
      int id = (rot == 0 ? id_from : id_to);
      if (id_from == id_to && rot == 1) {
        break;
      }
      vector< pair<int,int> > sorted1, sorted2;
      for (auto &p : sorted[id]) {
        if (p.second >= init_from && p.second <= init_to) {
          sorted1.emplace_back(t[p.second], p.second);
        } else {
          sorted2.emplace_back(t[p.second], p.second);
        }
      }
      sorted[id].clear();
      merge(sorted1.begin(), sorted1.end(), sorted2.begin(), sorted2.end(), back_inserter(sorted[id]));
    }
  };
  for (int i = 0; i < cnt; i++) {
    pull(i);
  }
  const int inf = (int) 1e9;
  for (int qid = 0; qid < m; qid++) {
    int who;
    cin >> who;
    int delta = (who > 0 ? -1 : 1);
    who = abs(who) - 1;
    modify(g.pos[who], g.pos[who], otp[g.pos[who]] == 0 ? inf : -inf);
    otp[g.pos[who]] ^= 1;
    auto stupid = [&](int from, int to, bool) {
      if (from > to) {
        swap(from, to);
      }
      modify(from, to, delta);
    };
    g.apply_on_path(0, who, true, stupid);
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
      ans += (int) (lower_bound(sorted[i].begin(), sorted[i].end(), make_pair(-add_to[i], -1)) - sorted[i].begin());
    }
    if (qid > 0) {
      cout << ' ';
    }
    cout << ans;
  }
  cout << '\n';
  cerr << "time = " << clock() << " ms" << '\n';
  return 0;
}