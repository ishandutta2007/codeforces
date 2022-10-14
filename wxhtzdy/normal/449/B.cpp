#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, K;
  cin >> N >> M >> K;

  vector<pair<int, int>> graph[N];
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;

    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  const int64_t inf = 1e18;

  vector<int64_t> dist(N, inf);
  dist[0] = 0;
  vector<bool> taken(N, false);
  for (int i = 0; i < K; i++) {
    int u;
    int64_t w;
    cin >> u >> w;
    --u;

    dist[u] = min(dist[u], w);
    taken[u] = true;
  }

  set<pair<int64_t, int>> que;
  for (int i = 0; i < N; i++) {
    if (dist[i] != inf) {
      que.insert({dist[i], i});
    }
  }

  while (!que.empty()) {
    auto it = que.begin();
    int u = it -> second;
    que.erase(it);

    for (auto edge : graph[u]) {
      int v = edge.first, w = edge.second;

      if (dist[v] >= dist[u] + w)
        taken[v] = false;

      if (dist[v] > dist[u] + w) {
        que.erase({dist[v], v});
        dist[v] = dist[u] + w;
        que.insert({dist[v], v});
      }
    }
  }

  int count = 0;
  for (int i = 0; i < N; i++)
    count += taken[i];

  cout << K - count << "\n";
  return 0;
}