#include <bits/stdc++.h>
using namespace std;

const int N = 400;

int dist[N][N], degree[N];
double prob[N], maxi[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = (i == j) ? 0 : n;
    }
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    ++degree[--u];
    ++degree[--v];
    dist[u][v] = 1;
    dist[v][u] = 1;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  double ans = 0.0;
  for (int i = 0; i < n; ++i) {
    double ans0 = 0.0;
    for (int j = 0; j < n; ++j) {
      vector<int> zero;
      for (int u = 0; u < n; ++u) {
        if (dist[i][u] == j) {
          zero.push_back(u);
        }
      }

      if (zero.empty()) {
        continue;
      }

      vector<int> one;
      for (int v = 0; v < n; ++v) {
        bool add = false;
        for (auto u : zero) {
          if (dist[u][v] == 1) {
            prob[v] += 1.0 / n / degree[u];
            add = true;
          }
        }

        if (add) {
          one.push_back(v);
        }
      }

      double ans1 = 1.0 / n;
      for (int v = 0; v < n; ++v) {
        for (auto u : one) {
          maxi[dist[u][v]] = max(maxi[dist[u][v]], prob[u]);
        }

        double ans2 = 0.0;
        for (auto u : one) {
          ans2 += maxi[dist[u][v]];
          maxi[dist[u][v]] = 0.0;
        }
        ans1 = max(ans1, ans2);
      }

      for (auto u : one) {
        prob[u] = 0.0;
      }

      ans0 += ans1;
    }
    ans = max(ans, ans0);
  }

  cout << ans << "\n";
}