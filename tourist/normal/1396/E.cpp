/**
 *    author:  tourist
 *    created: 30.08.2020 18:54:03       
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
      if (id == pe[v]) {
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
  vector<vector<int>> pr;

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

  inline int go_up(int x, int up) {
    assert(!pr.empty());
    up = min(up, (1 << h) - 1);
    for (int j = h - 1; j >= 0; j--) {
      if (up & (1 << j)) {
        x = pr[x][j];
        if (x == -1) {
          break;
        }
      }
    }
    return x;
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

class segtree {
 public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    int sum = 0;
    bool flip = false;

    void apply(int l, int r) {
      sum = (r - l + 1) - sum;
      flip = !flip;
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.sum = a.sum + b.sum;
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    // push from x into (x + 1) and z
    if (tree[x].flip) {
      tree[x + 1].apply(l, y);
      tree[z].apply(y + 1, r);
      tree[x].flip = false;
    }
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  hld_forest<int> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g.add(x, y);
  }
  g.dfs(0);
  int root = 0;
  while (true) {
    int new_root = -1;
    for (int eid : g.g[root]) {
      auto& e = g.edges[eid];
      int to = e.from ^ e.to ^ root;
      if (to == g.pv[root]) {
        continue;
      }
      if (2 * g.sz[to] >= n) {
        new_root = to;
        break;
      }
    }
    if (new_root == -1) {
      break;
    }
    root = new_root;
  }
  g.build_hld(root);
  long long L = 0;
  long long R = 0;
  for (int i = 0; i < n; i++) {
    if (i != root) {
      R += g.sz[i];
      L += g.sz[i] % 2;
    }
  }
  debug(k, L, R);
  if (k < L || k > R || k % 2 != L % 2) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  vector<int> rt(n);
  for (int v : g.order) {
    rt[v] = v;
    if (v != root && g.pv[v] != root) {
      rt[v] = rt[g.pv[v]];
    }
  }
  vector<vector<int>> sets(n);
  for (int i = 0; i < n; i++) {
    sets[rt[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    assert(2 * (int) sets[i].size() <= n);
  }
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    sort(sets[i].begin(), sets[i].end(), [&](int u, int v) {
      return g.depth[u] < g.depth[v];
    });
    if (!sets[i].empty()) {
      s.emplace((int) sets[i].size(), i == root ? -1 : i);
    }
  }
  segtree st(n);
  for (int i = 1; i < n; i++) {
    if (g.sz[g.order[i]] % 2 == 0) {
      st.modify(i, i);
    }
  }
  vector<pair<int, int>> ret;
  long long diff = k - L;
  vector<bool> used(n, false);
  while (!s.empty() && diff > 0) {
    auto it1 = prev(s.end());
    assert(it1 != s.begin());
    auto it2 = prev(it1);
    int i1 = it1->second;
    int i2 = it2->second;
    if (i1 == -1) {
      i1 = root;
    }
    if (i2 == -1) {
      i2 = root;
    }
    int v1 = sets[i1].back();
    int v2 = sets[i2].back();
    s.erase(s.find(make_pair((int) sets[i1].size(), i1 == root ? -1 : i1)));
    s.erase(s.find(make_pair((int) sets[i2].size(), i2 == root ? -1 : i2)));
    sets[i1].pop_back();
    sets[i2].pop_back();
    if (!sets[i1].empty()) {
      s.emplace((int) sets[i1].size(), i1 == root ? -1 : i1);
    }
    if (!sets[i2].empty()) {
      s.emplace((int) sets[i2].size(), i2 == root ? -1 : i2);
    }
    long long change = 0;
    g.apply_on_path(v1, v2, false, [&](int from, int to, bool) {
      change += st.get(from, to).sum;
    });
    while (!g.anc(v2, v1) && 2 * change > diff) {
      change -= st.get(g.pos[v2], g.pos[v2]).sum;
      v2 = g.pv[v2];
    }
    while (!g.anc(v1, v2) && 2 * change > diff) {
      change -= st.get(g.pos[v1], g.pos[v1]).sum;
      v1 = g.pv[v1];
    }
    diff -= 2 * change;
    if (used[v1] || used[v2]) {
      assert(diff == 0);
      int lca = g.lca(v1, v2);
      vector<int> path1;
      vector<int> path2;
      while (v1 != lca) {
        path1.push_back(v1);
        v1 = g.pv[v1];
      }
      while (v2 != lca) {
        path2.push_back(v2);
        v2 = g.pv[v2];
      }
      vector<int> path;
      for (int x : path1) {
        path.push_back(x);
      }
      path.push_back(lca);
      for (int x : vector<int>(path2.rbegin(), path2.rend())) {
        path.push_back(x);
      }
      debug(path);
      int p1 = 0;
      int p2 = (int) path.size() - 1;
      while (p1 < p2 && used[path[p1]]) {
        ++p1;
      }
      while (p1 < p2 && used[path[p2]]) {
        --p2;
      }
      for (int ver : path) if (!used[ver]) debug(ver);
      assert(p1 < p2);
      v1 = path[p1];
      v2 = path[p2];
    }
    ret.emplace_back(v1, v2);
    used[v1] = true;
    used[v2] = true;
    g.apply_on_path(v1, v2, false, [&](int from, int to, bool) {
      st.modify(from, to);
    });
  }
  vector<int> any(n, -1);
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      any[i] = i;
    }
  }
  for (int it = n - 1; it >= 1; it--) {
    int v = g.order[it];
    if (any[v] != -1) {
      int u = g.pv[v];
      if (any[u] != -1) {
        ret.emplace_back(any[v], any[u]);
        any[u] = -1;
      } else {
        any[u] = any[v];
      }
    }
  }
  assert((int) ret.size() == n / 2);
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  for (auto& p : ret) {
    assert(0 <= p.first && p.first < n && 0 <= p.second && p.second < n);
    assert(!used[p.first]);
    used[p.first] = true;
    assert(!used[p.second]);
    used[p.second] = true;
  }
  long long total = 0;
  for (auto& p : ret) {
    int u = p.first;
    int v = p.second;
    int z = g.lca(u, v);
    total += g.depth[u] + g.depth[v] - 2 * g.depth[z];
  }
  assert(total == k);
  for (auto& p : ret) {
    cout << p.first + 1 << " " << p.second + 1 << '\n';
  }
  return 0;
}