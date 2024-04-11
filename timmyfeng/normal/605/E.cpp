#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

double prob[N][N], dist[N], sum[N], moves[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      prob[i][j] = x / 100.0;
    }
  }

  fill(dist, dist + n - 1, HUGE_VAL);
  fill(sum, sum + n - 1, 1.0);

  set<pair<double, int>> que;
  que.insert({0.0, n - 1});

  while (!que.empty()) {
    auto [d, u] = *que.begin();
    que.erase(que.begin());

    if (u == 0) {
      cout << dist[u] << "\n";
      exit(0);
    }

    for (int c = 0; c < n; ++c) {
      if (dist[c] > d && prob[c][u] > 0.0) {
        double coeff = prob[c][u] * (1.0 - moves[c]);
        sum[c] += coeff * dist[u];
        moves[c] += coeff;
        que.erase({dist[c], c});
        dist[c] = sum[c] / moves[c];
        que.insert({dist[c], c});
      }
    }
  }
}