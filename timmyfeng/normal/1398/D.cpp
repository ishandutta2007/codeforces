#include <bits/stdc++.h>
using namespace std;

const int N = 201;

int n[3];
int a[3][N];
long long dp[N][N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int& i : n) {
    cin >> i;
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n[i]; ++j) {
      cin >> a[i][j];
    }
    sort(a[i], a[i] + n[i]);
    reverse(a[i], a[i] + n[i]);
  }

  long long ans = 0;
  for (int i = 0; i <= n[0]; ++i) {
    for (int j = 0; j <= n[1]; ++j) {
      for (int k = 0; k <= n[2]; ++k) {
        if (j < n[1] && k < n[2]) {
          dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + a[1][j] * a[2][k]);
        }
        if (i < n[0] && k < n[2]) {
          dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + a[0][i] * a[2][k]);
        }
        if (i < n[0] && j < n[1]) {
          dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + a[0][i] * a[1][j]);
        }
        ans = max(ans, dp[i][j][k]);
      }
    }
  }

  cout << ans << "\n";
}