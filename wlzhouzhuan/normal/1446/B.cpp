#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5005;
char a[N], b[N];
int dp[N][N], n, m, ans;

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s%s", a + 1, b + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 2;
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) - 1;
      }
      dp[i][j] = max(dp[i][j], 0);
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}