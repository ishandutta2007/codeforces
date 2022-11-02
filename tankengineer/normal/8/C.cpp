//CF 8C
#include<stdio.h>

const int cn = 16777216;

int dp[cn], fa[cn], x[25], y[25], dis[25], cost[25][25], n, tx, ty, t1, fw[25], nx[25], head;
bool vis[cn];

void inline del(const int i) {
  if (fw[i] == -1) {
    head = nx[i];
    if (nx[i] != -1) {
      fw[nx[i]] = -1;
    }
  } else if (nx[i] == -1) {
    nx[fw[i]] = -1;
  } else {
    nx[fw[i]] = nx[i];
    fw[nx[i]] = fw[i];
  }
}

void inline rev(const int i) {
  if (fw[i] == -1) {
    head = i;
    if (nx[i] != -1) {
      fw[nx[i]] = i;
    }
  } else if (nx[i] == -1) {
    nx[fw[i]] = i;
  } else {
    nx[fw[i]] = i;
    fw[nx[i]] = i;
  }
}

void dps(const int cod) {
  if (vis[cod]) return;

  int tmp, i = head;
  vis[cod] = true;
  dp[cod] = 200000000;
  tmp = cod - (1 << i);
  del(i);
  dps(tmp);
  if (dp[cod] > dp[tmp] + dis[i]) {
    dp[cod] = dp[tmp] + dis[i];
    fa[cod] = i;
  }
  for (int j = nx[i]; j != -1; j = nx[j]) {
    del(j);
    tmp = cod - (1 << i) - (1 << j);
    dps(tmp);
    if (dp[cod] > dp[tmp] + cost[i][j]) {
      dp[cod] = dp[tmp] + cost[i][j];
      fa[cod] = j * n + i;
    }
    rev(j);
  }
  rev(i);
}

int main() {
  scanf("%d %d", &tx, &ty);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    x[i] -= tx; y[i] -= ty;
    dis[i] = 2 * (x[i] * x[i] + y[i] * y[i]);
    nx[i] = i + 1;
    fw[i] = i - 1;
  }
  head = 0;
  nx[n - 1] = -1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cost[i][j] = (dis[i] + dis[j]) / 2 + (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    }
  }
  vis[0] = true; dp[0] = 0;
  t1 = (1 << n) - 1;
  dps(t1);
  printf("%d\n", dp[t1]);
  printf("0");
  while (t1) {
    if (fa[t1] < n) {
      printf(" %d 0", fa[t1] + 1);
      t1 -= (1 << fa[t1]);
    } else {
      printf(" %d %d 0", fa[t1] % n + 1, fa[t1] / n + 1);
      t1 -= (1 << (fa[t1] % n)) + (1 << (fa[t1] / n));
    }
  }
  printf("\n");
  return 0;
}