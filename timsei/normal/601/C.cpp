#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1005;

int n, m, x, y, P[N];

double dp[N][M * N];

int main() {
  cin >> n >> m;
  if(m == 1) {
    cout << 1 << endl;
    return 0;
  }
  int Sum = 0;
  for(int i = 1; i <= n; ++ i) {
    cin >> P[i];
    Sum += P[i];
  }
  dp[0][0] = 1;
  for(int i = 0; i < n; ++ i) {
    for(int j = 0; j <= n * m; ++ j) {
      dp[i + 1][j + 1] += dp[i][j];
      dp[i + 1][j + m + 1] -= dp[i][j];
    }
    for(int j = 1; j <= n * m; ++ j)
      dp[i + 1][j] += dp[i + 1][j - 1];
    for(int j = 0; j <= n * m; ++ j) {
      dp[i + 1][j + P[i + 1]] -= dp[i][j];
    }
    for(int j = 0; j <= n * m; ++ j) dp[i + 1][j] = dp[i + 1][j] / (m - 1);
  }
  double ans = 0;
  for(int j = 0; j < Sum; ++ j) ans += dp[n][j];
  printf("%.12lf\n", ans * (m - 1) + 1);
}