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

const int N = 20'000;
const int L = 15;

vector<array<int, 2>> adj[N];
int n, m, log_n, count_n;

int time_out[N];
int time_in[N];
int par[L][N];
int id[L][N];
int time_dfs;

bool ancestor(int u, int v) {
  return time_in[u] <= time_in[v] && time_out[u] >= time_out[v];
}

void dfs(int u) {
  time_in[u] = time_dfs++;

  for (int i = 1; i < log_n; ++i) {
    if (par[i - 1][u] != -1) {
      par[i][u] = par[i - 1][par[i - 1][u]];
      if (par[i][u] != -1) {
        id[i][u] = count_n++;
      }
    } else {
      par[i][u] = -1;
    }
  }

  for (auto [c, i] : adj[u]) {
    if (c != par[0][u]) {
      id[0][c] = i + m;
      par[0][c] = u;
      dfs(c);
    }
  }

  time_out[u] = time_dfs;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  count_n = n + m - 1;
  log_n = 31 - __builtin_clz(n);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  par[0][0] = -1;
  dfs(0);

  dinic<int> flower(count_n + 2, count_n, count_n + 1);

  for (int i = 0; i < log_n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (par[i][j] != -1) {
        if (i == 0) {
          flower.add_edge(id[i][j], flower.sink, 1);
        } else {
          flower.add_edge(id[i][j], id[i - 1][par[i - 1][j]], INT_MAX);
          flower.add_edge(id[i][j], id[i - 1][j], INT_MAX);
        }
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    for (int k = 0; k < 2; ++k) {
      for (int j = log_n - 1; j >= 0; --j) {
        if (par[j][u] != -1 && !ancestor(par[j][u], v)) {
          flower.add_edge(i, id[j][u], INT_MAX);
          u = par[j][u];
        }
      }
      if (!ancestor(u, v)) {
        flower.add_edge(i, id[0][u], INT_MAX);
        u = par[0][u];
      }
      swap(u, v);
    }
    flower.add_edge(flower.src, i, 1);
  }

  cout << flower.solve() << "\n";

  cout << count(flower.level.begin(), flower.level.begin() + m, -1) << " ";
  for (int i = 0; i < m; ++i) {
    if (flower.level[i] == -1) {
      cout << i + 1 << " ";
    }
  }
  cout << "\n";

  cout << n - 1 - count(flower.level.begin() + m, flower.level.begin() + n + m - 1, -1) << " ";
  for (int i = 0; i < n - 1; ++i) {
    if (flower.level[m + i] != -1) {
      cout << i + 1 << " ";
    }
  }
  cout << "\n";
}