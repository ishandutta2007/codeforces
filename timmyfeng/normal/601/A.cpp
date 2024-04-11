#include <bits/stdc++.h>
using namespace std;

const int N = 400 + 1;

int dist[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j) {
        dist[i][j] = n;
      }
    }
  }

  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    dist[u][v] = dist[v][u] = 1;
  }

  if (dist[1][n] == 1) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i != j) {
          dist[i][j] = n + 1 - dist[i][j];
        }
      }
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i ){
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  if (dist[1][n] == n) {
    cout << -1 << "\n";
  } else {
    cout << dist[1][n] << "\n";
  }
}