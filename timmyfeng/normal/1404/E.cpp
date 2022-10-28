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

  dinic(int n, int s, int t) : n(n), src(s), sink(t) {
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

  vector<string> grid(n);
  for (auto& i : grid) {
    cin >> i;
  }

  dinic<int> flow(2 * n * m + 2, 2 * n * m, 2 * n * m + 1);
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        ++ans;
        if (i > 0 && grid[i - 1][j] == '#') {
          flow.add_edge(flow.src, (i - 1) * m + j, 1);
          --ans;
        }
        if (j > 0 && grid[i][j - 1] == '#') {
          flow.add_edge((n + i) * m + j - 1, flow.sink, 1);
          --ans;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        vector<int> horizontal;
        if (i > 0 && grid[i - 1][j] == '#') {
          horizontal.push_back((i - 1) * m + j);
        }
        if (i + 1 < n && grid[i + 1][j] == '#') {
          horizontal.push_back(i * m + j);
        }

        vector<int> vertical;
        if (j > 0 && grid[i][j - 1] == '#') {
          vertical.push_back(i * m + j - 1);
        }
        if (j + 1 < m && grid[i][j + 1] == '#') {
          vertical.push_back(i * m + j);
        }

        for (auto h : horizontal) {
          for (auto v : vertical) {
            flow.add_edge(h, n * m + v, 1);
          }
        }
      }
    }
  }

  ans += flow.solve();
  cout << ans << "\n";
}