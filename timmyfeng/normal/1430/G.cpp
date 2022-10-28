#include <bits/stdc++.h>
using namespace std;

template <class T>
struct dinic {

  struct edge {
    int u, v;
    T cap, flow;
  };

  vector<vector<int>> adj;
  vector<int> level;
  vector<int> ptr;
  vector<edge> e;

  int n, src, sink;

  dinic(int n) : n(n), src(n - 2), sink(n - 1) {
    adj.assign(n, vector<int>());
    level.assign(n, -1);
    ptr.assign(n, 0);
  }

  void add_edge(int u, int v, T w) {
    e.push_back({u, v, w, 0});
    e.push_back({v, u, w, w});
    adj[u].push_back(e.size() - 2u);
    adj[v].push_back(e.size() - 1u);
  }

  bool bfs() {
    fill(level.begin(), level.end(), -1);
    level[src] = 0;
    queue<int> que;
    que.push(src);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int c : adj[u]) {
        if (level[e[c].v] == -1 && e[c].flow < e[c].cap) {
          level[e[c].v] = level[u] + 1;
          que.push(e[c].v);
        }
      }
    }
    return level[sink] != -1;
  }

  T dfs(int u, T cnt) {
    if (u == sink)
      return cnt;
    for ( ; ptr[u] < int(adj[u].size()); ++ptr[u]) {
      int c = adj[u][ptr[u]];
      if (level[e[c].v] == level[u] + 1 && e[c].flow < e[c].cap) {
        T res = dfs(e[c].v, min(cnt, e[c].cap - e[c].flow));
        if (res > 0) {
          e[c].flow += res;
          e[c ^ 1].flow -= res;
          return res;
        }
      }
    }
    return 0;
  }

  T solve() {
    T res = 0;
    while (bfs()) {
      fill(ptr.begin(), ptr.end(), 0);
      T delta = -1;
      while (delta != 0) {
        delta = dfs(src, numeric_limits<T>::max());
        res += delta;
      }
    }
    return res;
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  dinic<long long> flower(n * n + 2);
  vector<int> coeff(n);

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    coeff[--u] += w;
    coeff[--v] -= w;

    for (int j = 0; j < n; ++j) {
      flower.add_edge(v * n + j, (j == n - 1) ? flower.sink : u * n + j + 1, INT_MAX);
    }
  }

  int offset = -*min_element(coeff.begin(), coeff.end()) * n;

  for (int i = 0; i < n; ++i) {
    flower.add_edge(flower.src, i * n, INT_MAX);
    for (int j = 0; j < n; ++j) {
      flower.add_edge(i * n + j, (j == n - 1) ? flower.sink : i * n + j + 1, coeff[i] * j + offset);
    }
  }

  flower.solve();

  for (int i = 0; i < n; ++i) {
    int a = 0;
    while (a < n - 1 && flower.level[i * n + a + 1] != -1) {
      ++a;
    }
    cout << a << " ";
  }

  cout << "\n";
}