#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 200000000;

int n, m, l, r, cnt[1005], f[1005][1005], g[1005][1005], ans;
char map[1005][1005];

int main() {
  scanf("%d %d %d %d", &n, &m, &l, &r);
  r = min(r, m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", map[i] + 1);
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      cnt[j] += map[i][j] == '.';
    }
  }
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      f[i][j] = INF;
      g[i][j] = INF;
    }
  }
  f[0][0] = 0;
  g[0][0] = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= r; ++j) {
      f[i][j] = min(f[i][j], f[i - 1][j - 1] + cnt[i]);
    }
    for (int j = l; j <= r; ++j) {
      f[i][1] = min(f[i][1], g[i - 1][j] + cnt[i]);
    }
    for (int j = 1; j <= r; ++j) {
      g[i][j] = min(g[i][j], g[i - 1][j - 1] + n - cnt[i]);
    }
    for (int j = l; j <= r; ++j) {
      g[i][1] = min(g[i][1], f[i - 1][j] + n - cnt[i]);
    }
  }
  ans = INF;
  for (int i = l; i <= r; ++i) ans = min(ans, min(f[m][i], g[m][i]));
  printf("%d\n", ans);
  return 0;
}