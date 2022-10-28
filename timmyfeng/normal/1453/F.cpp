#include <bits/stdc++.h>
using namespace std;

const int N = 3000 + 1;

int cost[N][N], sum[N][N], a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] += i;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        sum[i][j + 1] = sum[i][j] + (a[j] >= i);
        cost[i][j] = INT_MAX;
      }
    }
    cost[0][0] = 0;

    for (int i = 0; i < n - 1; ++i) {
      int prefix = cost[i][i];
      for (int j = i + 1; j <= a[i]; ++j) {
        if (prefix < INT_MAX) {
          cost[j][a[i]] = min(cost[j][a[i]], prefix + sum[j][j] - sum[j][i + 1]);
        }
        prefix = min(prefix, cost[i][j]);
      }
    }

    cout << cost[n - 1][n - 1] << "\n";
  }
}