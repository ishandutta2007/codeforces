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

const int N = 3000;
const int A = 100 + 1;

int a[N], prv[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  dinic<int> flower(n + 2, n + 1, n);
  fill(prv, prv + A, -1);
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;

    if (b > 0) {
      flower.add(flower.s, i, b);
      ans += b;
    } else {
      flower.add(i, flower.t, -b);
    }

    for (int j = 1; j <= a[i]; ++j) {
      if (a[i] % j == 0 && prv[j] != -1) {
        flower.add(i, prv[j], INT_MAX);
      }
    }

    prv[a[i]] = i;
  }

  ans -= flower.max_flow();

  cout << ans << "\n";
}