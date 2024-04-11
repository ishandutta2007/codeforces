//14D
#include<cstdio>
#include<cstring>

int n, t1, t2, g[205][205], ans, best;

int go(int i) {
  int qhead = 0, qtail = 1, q[205], dis[205], t1, t2;
  memset(dis, 0, sizeof(dis));
  memset(q, 0, sizeof(q));
  q[1] = i; dis[i] = 1;
  while (qhead < qtail) {
    t1 = q[++qhead];
    for (int j = 1; j <= n; j++) {
      if (g[t1][j] && dis[j] == 0) {
        q[++qtail] = j;
        dis[j] = dis[t1] + 1;
      }
    }
  }
  best = q[qtail];
  return dis[best] - 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &t1, &t2);
    g[t1][t2] = g[t2][t1] = 1;
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (g[i][j]) {
        g[i][j] = g[j][i] = 0;
        go(i); t1 = go(best);
        go(j); t2 = go(best);
        ans = ans < t1 * t2 ? t1 * t2 : ans;
        g[i][j] = g[j][i] = 1;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}