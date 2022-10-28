#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

array<int, 2> edges[N];
vector<array<int, 2>> adj[N];
int dist[N][N];
int a[N];
int b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {--u, --v};
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for (int i = 0; i < k; ++i) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
  }

  for (int i = 0; i < n; ++i) {
    fill(dist[i], dist[i] + n, INT_MAX);
    dist[i][i] = 0;

    min_queue<array<int, 2>> que;
    que.push({0, i});

    while (!que.empty()) {
      auto [d, u] = que.top();
      que.pop();
      if (d > dist[i][u]) {
        continue;
      }

      for (auto [c, w] : adj[u]) {
        if (dist[i][c] > d + w) {
          dist[i][c] = d + w;
          que.push({d + w, c});
        }
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i < m; ++i) {
    int res = 0;
    auto [u, v] = edges[i];
    for (int j = 0; j < k; ++j) {
      res += min({
          dist[a[j]][b[j]],
          dist[a[j]][u] + dist[v][b[j]],
          dist[a[j]][v] + dist[u][b[j]]
      });
    }
    ans = min(ans, res);
  }

  cout << ans << "\n";
}