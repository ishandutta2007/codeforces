#include <bits/stdc++.h>
using namespace std;

template <class T>
struct dinic {

  vector<vector<int>> adj;
  vector<pair<int, T>> e;
  vector<int> level, ptr;
  int n, s, t;

  dinic(int n, int s, int t) : adj(n), n(n), s(s), t(t) {}

  void add(int u, int v, T w) {
    adj[v].push_back(e.size() + 1);
    adj[u].push_back(e.size());
    e.push_back({v, w});
    e.push_back({u, 0});
  }

  bool bfs() {
    level.assign(n, -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int c : adj[u]) {
        auto [to, cap] = e[c];
        if (cap > 0 && level[to] == -1) {
          level[to] = level[u] + 1;
          if (to == t) {
            return true;
          }
          que.push(to);
        }
      }
    }
    return false;
  }

  T dfs(int u, T flow) {
    if (u == t) {
      return flow;
    }

    T initial = flow;
    for ( ; ptr[u] < (int) adj[u].size(); ++ptr[u]) {
      int c = adj[u][ptr[u]];
      auto [to, cap] = e[c];
      if (cap > 0 && level[to] == level[u] + 1) {
        T res = dfs(to, min(flow, cap));
        e[c ^ 1].second += res;
        e[c].second -= res;
        flow -= res;
        if (flow == 0) {
          return initial;
        }
      }
    }
    return initial - flow;
  }

  T max_flow() {
    T res = 0;
    while (bfs()) {
      ptr.assign(n, 0);
      res += dfs(s, numeric_limits<T>::max());
    }
    return res;
  }

};

const int L = 10000000 + 1;
const int N = 750 + 1;
const int A = 2;

int to[L][A], link[L], word[L], id[L];
bitset<N> adj[N];
string ribbon[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int m = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> ribbon[i];
    int u = 0;
    for (auto c : ribbon[i]) {
      if (to[u][c - 'a'] == 0) {
        to[u][c - 'a'] = m++;
      }
      u = to[u][c - 'a'];
    }
    id[u] = i;
  }

  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int u = que.front();
    que.pop();

    int p = link[u];
    word[u] = (id[u] == 0) ? word[p] : u;

    for (int i = 0; i < A; ++i) {
      if (to[u][i] == 0) {
        to[u][i] = to[p][i];
      } else {
        link[to[u][i]] = (u == 0) ? 0 : to[p][i];
        que.push(to[u][i]);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    int u = 0;
    for (auto c : ribbon[i]) {
      u = to[u][c - 'a'];
      int v = word[(id[u] == i) ? link[u] : u];
      while (v != 0 && !adj[id[v]][i]) {
        adj[id[v]][i] = true;
        v = word[link[v]];
      }
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      if (adj[i][k]) {
        adj[i] |= adj[k];
      }
    }
  }

  dinic<int> flower(2 * n + 2, 0, 2 * n + 1);
  for (int i = 1; i <= n; ++i) {
    flower.add(flower.s, i, 1);
    flower.add(n + i, flower.t, 1);
    for (int j = 1; j <= n; ++j) {
      if (adj[i][j]) {
        flower.add(i, n + j, 1);
      }
    }
  }

  cout << n - flower.max_flow() << "\n";
  for (int i = 1; i <= n; ++i) {
    if (flower.level[i] != -1 && flower.level[n + i] == -1) {
      cout << i << " ";
    }
  }
  cout << "\n";
}