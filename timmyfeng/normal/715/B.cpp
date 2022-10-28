#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 10000;

struct dijkstra {

  long long d;
  int u;

  bool operator<(const dijkstra oth) const {
    if (d == oth.d) {
      return u > oth.u;
    }
    return d > oth.d;
  }

};

vector<array<int, 2>> adj[N];
array<int, 3> edge[M];
long long dist_s[N];
long long dist_t[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, l, s, t;
  cin >> n >> m >> l >> s >> t;

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    if (w == 0) {
      w = -i;
    }

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    edge[i] = {u, v, w};
  }

  priority_queue<dijkstra> que;
  fill(dist_t, dist_t + n, LLONG_MAX);
  que.push({0, t});
  dist_t[t] = 0;

  while (!que.empty()) {
    dijkstra u = que.top();
    que.pop();
    if (u.d > dist_t[u.u]) {
      continue;
    }

    for (auto [c, w] : adj[u.u]) {
      if (w > 0 && u.d + w < dist_t[c]) {
        dist_t[c] = u.d + w;
        que.push({u.d + w, c});
      }
    }
  }

  fill(dist_s, dist_s + n, LLONG_MAX);
  que.push({0, s});
  dist_s[s] = 0;

  while (!que.empty()) {
    dijkstra u = que.top();
    que.pop();
    if (u.d > dist_s[u.u]) {
      continue;
    }

    for (auto e : adj[u.u]) {
      int c = e[0];
      int w = e[1];

      if (w <= 0) {
        if (edge[-w][2] <= 0) {
          edge[-w][2] = max(1LL, l - dist_t[c] - u.d);
        }
        w = edge[-w][2];
      }

      if (u.d + w < dist_s[c]) {
        dist_s[c] = u.d + w;
        que.push({u.d + w, c});
      }
    }
  }

  if (dist_s[t] == l) {
    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < 3; ++j) {
        cout << edge[i][j] << " ";
      }
      cout << "\n";
    }
  } else {
    cout << "NO\n";
  }
}