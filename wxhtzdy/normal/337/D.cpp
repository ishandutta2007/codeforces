#include <bits/stdc++.h>

using ll = long long;

const int nmax = 100005;

std::vector<int> g[nmax];
bool mark[nmax];
int dist[nmax][2];

void dfs1(int u, int p) {
  dist[u][0] = (mark[u] ? 0 : -1e9);
  for (int v : g[u]) {
    if (v != p) {
      dfs1(v, u);
      dist[u][0] = std::max(dist[u][0], dist[v][0] + 1);
    }
  }
}

void dfs2(int u, int p) {
  if (u == 1) dist[u][1] = (mark[u] ? 0 : -1e9);
  if (mark[u]) dist[u][1] = std::max(dist[u][1], 0);
  int mx = -1e9;
  for (int v : g[u]) {
    if (v != p) {
      dist[v][1] = dist[u][1] + 1;
      dist[v][1] = std::max(dist[v][1], mx + 2);
      mx = std::max(mx, dist[v][0]);
    }
  }
  reverse(g[u].begin(), g[u].end());
  mx = -1e9;
  for (int v : g[u]) {
    if (v != p) {
      dist[v][1] = std::max(dist[v][1], mx + 2);
      mx = std::max(mx, dist[v][0]);
      dfs2(v, u);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, d;
  std::cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int u;
    std::cin >> u;
    mark[u] = true;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dist[0][0] = -1e9;
  dist[0][1] = -1e9;
  dfs1(1, 0);
  dfs2(1, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i][0] <= d && dist[i][1] <= d) {
      ans++;
    }
  }
  std::cout << ans << '\n';
  return 0;
}