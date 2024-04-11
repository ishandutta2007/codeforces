/**
 *    author:  tourist
 *    created: 01.11.2020 18:46:06       
**/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

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
vector<int> find_topsort(const digraph<T> &g) {
  vector<int> deg(g.n, 0);
  for (int id = 0; id < (int) g.edges.size(); id++) {
    deg[g.edges[id].to]++;
  }
  vector<int> x;
  for (int i = 0; i < g.n; i++) {
    if (deg[i] == 0) {
      x.push_back(i);
    }
  }
  for (int ptr = 0; ptr < (int) x.size(); ptr++) {
    int i = x[ptr];
    for (int id : g.g[i]) {
      auto &e = g.edges[id];
      int to = e.to;
      if (--deg[to] == 0) {
        x.push_back(to);
      }
    }
  }
  if ((int) x.size() != g.n) {
    return vector<int>();
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, tt;
  cin >> n >> m >> tt;
  vector<vector<int>> g(n, vector<int>(n, 0));
  digraph<int> gr(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x][y] = 1;
    gr.add(x, y);
  }
  vector<int> order = find_topsort(gr);
  reverse(order.begin(), order.end());
  int magic = min(n, MAX);
  vector<int> masks;
  for (int bc = 0; bc <= magic; bc++) {
    for (int mask = 0; mask < (1 << magic); mask++) {
      if (__builtin_popcount(mask) == bc) {
        masks.push_back(mask);
      }
    }
  }
  vector<tuple<char, int, int>> ops;
  for (int i = 0; i < magic; i++) {
    for (int j = i + 1; j < magic; j++) {
      if (g[order[j]][order[i]] == 0) {
        ops.emplace_back('+', order[j], order[i]);
        g[order[j]][order[i]] = 1;
      }
    }
  }
  vector<bool> used(1 << magic);
  vector<int> got(n, -1);
  for (int i = magic; i < n; i++) {
    int me = 0;
    for (int j = 0; j < magic; j++) {
      if (g[order[i]][order[j]]) {
        me |= (1 << j);
      }
    }
    int goal = -1;
    for (int x : masks) {
      if (!used[me ^ x]) {
        goal = me ^ x;
        used[me ^ x] = true;
        break;
      }
    }
    assert(goal != -1);
    got[order[i]] = goal;
    for (int j = 0; j < magic; j++) {
      if ((me ^ goal) & (1 << j)) {
        ops.emplace_back(g[order[i]][order[j]] == 1 ? '-' : '+', order[i], order[j]);
      }
    }
    ops.emplace_back('+', order[i], order[i]);
    g[order[i]][order[i]] = 1;
  }
  cout << ops.size() << endl;
  for (auto& op : ops) {
    cout << get<0>(op) << " " << get<1>(op) + 1 << " " << get<2>(op) + 1 << endl;
  }
  while (tt--) {
    bool found = false;
    int mask = 0;
    for (int i = 0; i < magic; i++) {
      cout << "? 1 " << order[i] + 1 << endl;
      string foo;
      cin >> foo;
      if (foo == "Lose") {
        cout << "! " << order[i] + 1 << endl;
        string bar;
        cin >> bar;
        assert(bar == "Correct");
        found = true;
        break;
      }
      if (foo == "Win") {
        mask |= (1 << i);
      }
    }
    if (!found) {
      for (int i = 0; i < n; i++) {
        if (got[i] == mask) {
          cout << "! " << i + 1 << endl;
          string bar;
          cin >> bar;
          assert(bar == "Correct");
          found = true;
          break;
        }
      }
      assert(found);
    }
  }
  return 0;
}