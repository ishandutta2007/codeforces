#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, last1, ans, tmp, dp[105][10005];
char map[105][10005];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", map[i] + 1);
    int last1 = 0;
    for (int j = 1; j <= m; ++j)  if (map[i][j] == '1') last1 = j;
    if (last1 == 0) {
      puts("-1");
      return 0;
    }
    for (int j = 1; j <= m; ++j) {
      if (j > 1) dp[i][j] = dp[i][j - 1] + 1; else dp[i][j] = m - last1 + 1;
      if (map[i][j] == '1') dp[i][j] = 0;
    }
    last1 = m + 1;
    for (int j = m; j >= 1; --j) if (map[i][j] == '1') last1 = j;
    for (int j = m; j >= 1; --j) {
      if (j < m) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1); else dp[i][j] = last1;
      if (map[i][j] == '1') dp[i][j] = 0;
    }
  }
  ans = n * m;
  for (int i = 1; i <= m; ++i) {
    tmp = 0;
    for (int j = 1; j <= n; ++j) tmp += dp[j][i];
    if (tmp < ans) {
      ans = tmp;
    }
  }
  printf("%d\n", ans);
  return 0;
}