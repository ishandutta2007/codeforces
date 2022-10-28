#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 1;
const int P = 10 * N;

array<int, 2> problem[N];
double cost[N][P];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    double c, t;
    cin >> n >> c >> t;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        cin >> problem[i][j];
      }
    }
    sort(problem, problem + n);

    for (int i = 0; i <= n; ++i) {
      fill(cost[i], cost[i] + P, HUGE_VAL);
    }
    cost[0][0] = 0.0;

    int sum = 0;
    double ratio = 10.0 / 9.0;
    for (int i = 0; i < n; ++i) {
      auto [a, p] = problem[i];
      sum += p;

      for (int j = i; j >= 0; --j) {
        for (int k = sum; k >= p; --k) {
          if (cost[j][k - p] != HUGE_VAL) {
            cost[j + 1][k] = min(cost[j + 1][k], ratio * (cost[j][k - p] + a));
          }
        }
      }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= sum; ++j) {
        if (cost[i][j] != HUGE_VAL) {
          double s = max(1.0, sqrt(cost[i][j] * c));
          if (cost[i][j] / s + 10 * i + (s - 1) / c < t) {
            ans = max(ans, j);
          }
        }
      }
    }

    cout << ans << "\n";
  }
}