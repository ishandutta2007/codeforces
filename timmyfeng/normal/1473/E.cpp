#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

vector<array<int, 2>> adj[N];
long long dist[N][4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      dist[i][j] = LLONG_MAX;
    }
  }
  dist[0][0] = 0;

  priority_queue<
    tuple<long long, int, int>,
    vector<tuple<long long, int, int>>,
    greater<tuple<long long, int, int>>
  > que;
  que.push({0, 0, 0});

  while (!que.empty()) {
    auto [d, u, m] = que.top();
    que.pop();

    if (d > dist[u][m]) {
      continue;
    }

    for (auto [c, w] : adj[u]) {
      for (int i = 0; i < 4; ++i) {
        if ((m & i) == 0) {
          long long dd = dist[u][m] + w;
          if ((i & 1) > 0) {
            dd -= w;
          }
          if ((i & 2) > 0) {
            dd += w;
          }

          if (dd < dist[c][m | i]) {
            dist[c][m | i] = dd;
            que.push({dd, c, m | i});
          }
        }
      }
    }
  }

  for (int i = 1; i < n; ++i) {
    cout << dist[i][3] << " ";
  }
  cout << "\n";
}