//22B
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, ans, sum[30][30];
char map[30][30];

int main() {
  scanf("%d %d", &n, &m);
  getchar();
  for (int i = 1; i <= n; i++) {
    gets(map[i]);
    for (int j = 1; j <= m; j++) {
      sum[i][j] = map[i][j - 1] - '0';
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int a = 1; i + a - 1 <= n; a++) {
        for (int b = 1; j + b - 1 <= m; b++) {
          if (sum[i + a - 1][j + b - 1] - sum[i + a - 1][j - 1] - sum[i - 1][j + b - 1] + sum[i - 1][j - 1] == 0) {
            ans = max(ans, 2 * (a + b));
            //printf("%d %d %d %d\n", i, j, a, b);
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}