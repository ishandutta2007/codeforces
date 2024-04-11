#include<cstdio>
#include<algorithm>
using namespace std;

const int dis[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
const int N = 2001, M = 2001, S = N * M;

int n, m, k, qhead, qtail, x[S], y[S], d[N][M], at, ans;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d %d", &n, &m, &k);
  qhead = qtail = 0;
  for (int i = 1; i <= k; ++i) {
    ++qtail;
    scanf("%d %d", &x[qtail], &y[qtail]);
    d[x[qtail]][y[qtail]] = 1;
  }
  at = k == 0 ? 0 : 1;
  while (qhead < qtail) {
    ++qhead;
    int tx = x[qhead], ty = y[qhead], ttx, tty;
    for (int i = 0; i < 4; ++i) {
      ttx = tx + dis[i][0];
      tty = ty + dis[i][1];
      if (ttx > 0 && ttx <= n && tty > 0 && tty <= m && d[ttx][tty] == 0) {
        d[ttx][tty] = d[tx][ty] + 1;
        at = max(at, d[ttx][tty]);
        ++qtail;
        x[qtail] = ttx;
        y[qtail] = tty;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (d[i][j] == at) {
        printf("%d %d\n", i, j);
        return 0;
      }
    }
  }
  return 0;
}