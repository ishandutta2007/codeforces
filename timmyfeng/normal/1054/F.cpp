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

  int n;
  cin >> n;

  map<int, vector<int>> h, v;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    h[y].push_back(x);
    v[x].push_back(y);
  }

  vector<array<int, 4>> wire;
  for (auto &[y, x] : h) {
    sort(x.begin(), x.end());
    for (int i = 1; i < (int) x.size(); ++i) {
      wire.push_back({x[i - 1], x[i], y, 0});
    }
  }

  for (auto &[x, y] : v) {
    sort(y.begin(), y.end());
    for (int i = 1; i < (int) y.size(); ++i) {
      wire.push_back({y[i - 1], y[i], x, 1});
    }
  }

  int m = wire.size();
  dinic<int> flower(m + 2);

  for (int i = 0; i < m; ++i) {
    if (wire[i][3] == 0) {
      flower.add_edge(m, i, 1);
    } else {
      flower.add_edge(i, m + 1, 1);
    }

    for (int j = 0; j < m; ++j) {
      array<int, 4> u = wire[i], v = wire[j];
      if (u[3] == 0 && v[3] == 1) {
        if (u[0] < v[2] && v[2] < u[1]) {
          if (v[0] < u[2] && u[2] < v[1]) {
            flower.add_edge(i, j, 1);
          }
        }
      }
    }
  }

  flower.solve();
  set<int> independent;
  for (int i = 0; i < m; ++i) {
    if (wire[i][3] == 0 && flower.level[i] != -1) {
      independent.insert(i);
    } else if (wire[i][3] == 1 && flower.level[i] == -1) {
      independent.insert(i);
    }
  }

  vector<array<int, 4>> ans_h, ans_v;
  int index = 0;

  for (auto &[y, x] : h) {
    int j = 0;
    for (int i = 1; i < (int) x.size(); ++i) {
      if (independent.count(index++) == 0) {
        ans_h.push_back({x[j], y, x[i - 1], y});
        j = i;
      }
    }
    ans_h.push_back({x[j], y, x.back(), y});
  }

  for (auto &[x, y] : v) {
    int j = 0;
    for (int i = 1; i < (int) y.size(); ++i) {
      if (independent.count(index++) == 0) {
        ans_v.push_back({x, y[j], x, y[i - 1]});
        j = i;
      }
    }
    ans_v.push_back({x, y[j], x, y.back()});
  }

  cout << ans_h.size() << "\n";
  for (auto i : ans_h) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }

  cout << ans_v.size() << "\n";
  for (auto i : ans_v) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}