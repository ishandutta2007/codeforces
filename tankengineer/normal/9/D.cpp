//CF 9D
/*
hn h<=n<=35

f[n][h]nh 

1/h-1 h-1  f[n][h] = 2 * sigma(a)(f[a][h - 1] * sigma(p)(f[n - a - 1][p]))
2h-1  f[n][h] = sigma(a)(f[a][h - 1] * f[n - a - 1][h - 1]);

n == 0 h != 0 --> 0
n != 0 h == 0 --> 0
n == 0 h == 0 --> 1  
*/

#include<stdio.h>

int n, h;
long long f[36][36], ans;
bool vis[36][36];

void dp(int n, int h) {
  if (vis[n][h] || !n || !h) return;
  
  vis[n][h] = true;
  long long tmp;
  for (int i = h - 1; i <= n - 1; i++) {
    tmp = 0;
    for (int j = 0; j <= n - 1 - i && j < h - 1; j++) {
      dp(n - i - 1, j);
      tmp = tmp + f[n - i - 1][j];
    } 
    dp(i, h - 1);
    f[n][h] += 2 * f[i][h - 1] * tmp;
  }
  for (int i = 0; i <= n - 1; i++) {
    dp(i, h - 1);
    dp(n - 1 - i, h - 1);
    f[n][h] += f[i][h - 1] * f[n - 1 - i][h - 1];
  }
} 

int main() {
  scanf("%d %d", &n, &h);
  vis[0][0] = true;
  f[0][0] = 1;
  ans = 0;
  for (int i = h; i <= n; i++) {
    dp(n, i);
    ans += f[n][i];
  }
  printf("%I64d\n", ans);
  return 0;
}