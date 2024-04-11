#include<cstdio>
#include<algorithm>
using namespace std;

int n, m;
char map[505][505];
bool dp[505][505][10][16];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", map[i] + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (map[i][j] == '*') {
        dp[i][j][0][0] = true;
      } else {
        for (int k = 1; k <= 15; ++k) dp[i][j][0][k] = true;
      }
    }
  }
  for (int k = 1; k <= 9; ++k) {
    int tl = 1 << (k - 1);
    for (int i = 1; i <= n - tl * 2 + 1; ++i) {
      for (int j = 1; j <= m - tl * 2 + 1; ++j) {
        for (int st = 0; st < 16; ++st) {
          dp[i][j][k][st] = dp[i][j][k - 1][((st >> 0) & 1) ? st : 0] && 
                            dp[i][j + tl][k - 1][((st >> 1) & 1) ? st : 0] && 
                            dp[i + tl][j + tl][k - 1][((st >> 2) & 1) ? st : 0] && 
                            dp[i + tl][j][k - 1][((st >> 3) & 1) ? st : 0];
          if (k > 1 && dp[i][j][k][st]) {
            ++ans;
            //printf("%d %d %d\n", i, j, k);
          }       
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}