/**
 *  author: milos
 *  created: 21.12.2020 15:49:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    --a, --b;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    auto Bfs = [&](int from, int to) {
      vector<int> dist(n, n + 1);
      vector<bool> was(n, false);
      was[from] = true;
      dist[from] = 0;
      deque<int> q;
      q.push_back(from);
      while (!q.empty()) {
        int x = q[0];
        for (int c : g[x]) {
          dist[c] = min(dist[c], dist[x] + 1);
          if (!was[c]) {
            was[c] = true;
            q.push_back(c);
          }
        }
        q.pop_front();
      }
      return dist[to];
    };
    auto Bfs2 = [&](int from) {
      vector<int> dist(n, n + 1);
      vector<bool> was(n, false);
      was[from] = true;
      dist[from] = 0;
      deque<int> q;
      q.push_back(from);
      while (!q.empty()) {
        int x = q[0];
        for (int c : g[x]) {
          dist[c] = min(dist[c], dist[x] + 1);
          if (!was[c]) {
            was[c] = true;
            q.push_back(c);
          }
        }
        q.pop_front();
      }
      int mx = *max_element(dist.begin(), dist.end());
      for (int i = 0; i < n; i++) {
        if (dist[i] == mx) {
          return i;
        }
      }
    };
    int dist = Bfs(a, b);
    if (da >= dist) {
      cout << "Alice" << '\n';
      continue;
    }
    int u = Bfs2(0);
    int diam = Bfs(u, Bfs2(u));
    if (2 * da >= diam) {
      cout << "Alice" << '\n';
      continue;
    }
    if (da * 2 >= db) {
      cout << "Alice" << '\n';
    } else {
      cout << "Bob" << '\n';
    }
  }
  return 0;
}