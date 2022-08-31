/**
 *    author:  tourist
 *    created: 24.12.2021 18:32:51       
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
class undigraph : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
vector<int> find_max_unweighted_matching(const undigraph<T>& g) {
  vector<int> mate(g.n, -1);
  vector<int> label(g.n);
  vector<int> parent(g.n);
  vector<int> orig(g.n);
  queue<int> q;
  vector<int> aux(g.n, -1);
  int aux_time = -1;
  auto lca = [&](int x, int y) {
    aux_time++;
    while (true) {
      if (x != -1) {
        if (aux[x] == aux_time) {
          return x;
        }
        aux[x] = aux_time;
        if (mate[x] == -1) {
          x = -1;
        } else {
          x = orig[parent[mate[x]]];
        }
      }
      swap(x, y);
    }
  };
  auto blossom = [&](int v, int w, int a) {
    while (orig[v] != a) {
      parent[v] = w;
      w = mate[v];
      if (label[w] == 1) {
        label[w] = 0;
        q.push(w);
      }
      orig[v] = orig[w] = a;
      v = parent[w];
    }
  };
  auto augment = [&](int v) {
    while (v != -1) {
      int pv = parent[v];
      int nv = mate[pv];
      mate[v] = pv;
      mate[pv] = v;
      v = nv;
    }
  };
  auto bfs = [&](int root) {
    fill(label.begin(), label.end(), -1);
    iota(orig.begin(), orig.end(), 0);
    while (!q.empty()) {
      q.pop();
    }
    q.push(root);
    label[root] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : g.g[v]) {
        auto &e = g.edges[id];
        int x = e.from ^ e.to ^ v;
        if (label[x] == -1) {
          label[x] = 1;
          parent[x] = v;
          if (mate[x] == -1) {
            augment(x);
            return true;
          }
          label[mate[x]] = 0;
          q.push(mate[x]);
          continue;
        }
        if (label[x] == 0 && orig[v] != orig[x]) {
          int a = lca(orig[v], orig[x]);
          blossom(x, v, a);
          blossom(v, x, a);
        }
      }
    }
    return false;
  };
  auto greedy = [&]() {
    vector<int> order(g.n);
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), mt19937(787788));
    for (int i : order) {
      if (mate[i] == -1) {
        for (int id : g.g[i]) {
          auto &e = g.edges[id];
          int to = e.from ^ e.to ^ i;
          if (mate[to] == -1) {
            mate[i] = to;
            mate[to] = i;
            break;
          }
        }
      }
    }
  };
  greedy();
  for (int i = 0; i < g.n; i++) {
    if (mate[i] == -1) {
      bfs(i);
    }
  }
  return mate;
}

class dsu {
 public:
  vector<int> p;
  int n;
  vector<int> info;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    info.assign(n, 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      info[y] += info[x];
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  vector<bool> done(n, false);
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != -1 && a[i] == a[i + 1]) {
      done[a[i]] = true;
    }
  }
  vector<array<int, 4>> e1;
  vector<array<int, 4>> e2;
  int beg = 0;
  while (beg < n) {
    if (a[beg] != -1) {
      ++beg;
      continue;
    }
    int end = beg;
    while (end + 1 < n && a[end + 1] == -1) {
      ++end;
    }
    int len = end - beg + 1;
    if (len % 2 == 1) {
      int x = ((beg == 0 || done[a[beg - 1]]) ? -1 : a[beg - 1]);
      int y = ((end == n - 1 || done[a[end + 1]]) ? -1 : a[end + 1]);
      if (x != -1 || y != -1) {
        array<int, 4> e = {x, y, beg, end};
        if (x == -1) {
          e[0] = y;
          e[2] = end;
        }
        if (y == -1) {
          e[1] = x;
          e[3] = beg;
        }
        e1.push_back(e);
      }
    } else {
      int x = ((beg == 0 || done[a[beg - 1]]) ? -1 : a[beg - 1]);
      int y = ((end == n - 1 || done[a[end + 1]]) ? -1 : a[end + 1]);
      if (x != -1 && y != -1 && x != y) {
        array<int, 4> e = {x, y, beg, end};
        e2.push_back(e);
      }
    }
    beg = end + 1;
  }
  dsu d(n);
  vector<array<int, 4>> take;
  vector<int> extra;
  for (auto& e : e1) {
    int x = d.get(e[0]);
    int y = d.get(e[1]);
    if (x == y) {
      if (d.info[x] == 0) {
        d.info[x] = 1;
        take.push_back(e);
        extra.push_back(1);
      }
    } else {
      if (d.info[x] + d.info[y] <= 1) {
        d.unite(x, y);
        take.push_back(e);
        extra.push_back(0);
      }
    }
  }
  vector<int> id(n, -1);
  vector<int> vers;
  auto GetId = [&](int x) {
    if (id[x] == -1) {
      id[x] = (int) vers.size();
      vers.push_back(x);
    }
    return id[x];
  };
  for (auto& e : e2) {
    int x = d.get(e[0]);
    int y = d.get(e[1]);
    if (x != y && d.info[x] == 0 && d.info[y] == 0) {
      x = GetId(x);
      y = GetId(y);
    }
  }
  int cnt = (int) vers.size();
  array<int, 4> init = {-1, -1, -1, -1};
  vector<vector<array<int, 4>>> who(cnt, vector<array<int, 4>>(cnt, init));
  for (auto& e : e2) {
    int x = d.get(e[0]);
    int y = d.get(e[1]);
    if (x != y && d.info[x] == 0 && d.info[y] == 0) {
      x = GetId(x);
      y = GetId(y);
      who[x][y] = e;
      who[y][x] = e;
    }
  }
  undigraph<int> g(cnt);
  for (int i = 0; i < cnt; i++) {
    for (int j = i + 1; j < cnt; j++) {
      if (who[i][j][0] != -1) {
        g.add(i, j);
      }
    }
  }
  auto mate = find_max_unweighted_matching(g);
  for (int i = 0; i < cnt; i++) {
    if (mate[i] > i) {
      auto& e = who[i][mate[i]];
      assert(a[e[2]] == -1 && a[e[3]] == -1);
      a[e[2]] = e[0];
      a[e[3]] = e[1];
      assert(!done[e[0]] && !done[e[1]]);
      done[e[0]] = true;
      done[e[1]] = true;
    }
  }
  int sz = (int) take.size();
  vector<vector<int>> gr(n);
  for (int i = 0; i < sz; i++) {
    if (!extra[i]) {
      auto& e = take[i];
      gr[e[0]].push_back(i);
      gr[e[1]].push_back(i);
    }
  }
  auto Bfs = [&](int start) {
    vector<int> que(1, start);
    for (int b = 0; b < (int) que.size(); b++) {
      for (int eid : gr[que[b]]) {
        if (!extra[eid]) {
          auto& e = take[eid];
          int to = e[0] ^ e[1] ^ que[b];
          if (!done[to]) {
            que.push_back(to);
            done[to] = true;
            int pos = (to == e[0] ? e[2] : e[3]);
            assert(a[pos] == -1);
            a[pos] = to;
          }
        }
      }
    }
  };
  for (int i = 0; i < cnt; i++) {
    if (mate[i] > i) {
      auto& e = who[i][mate[i]];
      Bfs(e[0]);
      Bfs(e[1]);
    }
  }
  for (int i = 0; i < sz; i++) {
    if (extra[i]) {
      auto& ee = take[i];
      assert(a[ee[2]] == -1);
      a[ee[2]] = ee[0];
      assert(!done[ee[0]]);
      done[ee[0]] = true;
      Bfs(ee[0]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!done[i]) {
      done[i] = true;
      Bfs(i);
    }
  }
  for (int i = 0; i < n; i++) {
    done[i] = false;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != -1 && a[i] == a[i + 1]) {
      done[a[i]] = true;
    }
  }
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    if (i < n - 1 && a[i] == -1 && a[i + 1] == -1) {
      while (ptr < n && done[ptr]) {
        ptr += 1;
      }
      assert(ptr < n);
      a[i] = a[i + 1] = ptr;
      done[ptr] = true;
      i += 1;
      continue;
    }
    if (a[i] == -1) {
      a[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i] + 1;
  }
  cout << '\n';
  return 0;
}