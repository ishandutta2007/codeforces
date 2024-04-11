//18E
#include<cstdio>
#include<cstring>

int n, m, cnt[2][26], dp[505][26][26], cost, fa[505][26][26], ansi, ansj, t1;
char flag[505][505];

int main() {
  scanf("%d %d", &n, &m);
  getchar();
  for (int i = 0; i < n; i++) {
    gets(flag[i]);
    memset(cnt, 0, sizeof(cnt));
    for (int j = 0; j < m; j++) {
      flag[i][j] -= 'a';
      cnt[j % 2][flag[i][j]]++;
    }
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        if (j != k) {
          dp[i][j][k] = n * m * 5;
          cost = m - cnt[0][j] - cnt[1][k];
          if (i == 0) {
            dp[i][j][k] = cost;
            continue;
          }
          for (int l = 0; l < 26; l++) {
            if (l == j) continue;
            for (int o = 0; o < 26; o++) {
              if (o == k || o == l) continue;
              if (dp[i][j][k] > dp[i - 1][l][o] + cost) {
                dp[i][j][k] = dp[i - 1][l][o] + cost;
                fa[i][j][k] = l * 27 + o;
              }
            }
          }
        }
      }
    }
  }
  n--;
  ansi = 0; ansj = 1;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i == j) continue;
      if (dp[n][i][j] < dp[n][ansi][ansj]) {
        ansi = i;
        ansj = j;
      }
    }
  }
  printf("%d\n", dp[n][ansi][ansj]);
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (j % 2 == 0) {
        flag[i][j] = 'a' + ansi;
      } else {
        flag[i][j] = 'a' + ansj;
      }
    }
    t1 = fa[i][ansi][ansj];
    ansi = t1 / 27;
    ansj = t1 % 27;
  }
  for (int i = 0; i <= n; i++) {
    puts(flag[i]);
  }
  return 0;
}