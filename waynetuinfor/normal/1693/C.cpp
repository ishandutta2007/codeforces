#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(N);
  vector<vector<int>> r(N);
  vector<int> deg(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    r[v].push_back(u);
  }

  constexpr int kInf = 1'000'000'000;
  vector<int> dist(N, kInf);
  vector<bool> vis(N);
  dist[N - 1] = 0;
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, N - 1);
  while (!pq.empty()) {
    int x = pq.top().second;
    pq.pop();
    if (vis[x]) {
      continue;
    }
    vis[x] = true;
    for (int u : r[x]) {
      if (!vis[u]) {
        ++deg[u];
        if (dist[x] + 1 + g[u].size() - deg[u] < dist[u]) {
          dist[u] = dist[x] + 1 + g[u].size() - deg[u];
          pq.emplace(-dist[u], u);
        }
      }
    }
  }
  cout << dist[0] << "\n";
  return 0;
}