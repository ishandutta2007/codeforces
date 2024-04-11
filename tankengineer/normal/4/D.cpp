//CF 4D
#include<cstdio>

int n, w[5005], h[5005], ind[5005], qhead, qtail, q[5005], t1, dp[5005], fa[5005];

int main() {
  scanf("%d", &n);
  n++;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &w[i], &h[i]);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (w[i] > w[j] && h[i] > h[j]) {
        ind[j]++;
      }
    }
  }
  
  qhead = 0; qtail = 0;
  for (int i = 1; i <= n; i++) {
    if (!ind[i]) {
      q[++qtail] = i;
      dp[i] = 1;
    }
  }
  
  while (qhead < qtail) {
    t1 = q[++qhead];
    for (int j = 1; j <= n; j++) {
      if (w[t1] > w[j] && h[t1] > h[j]) {
        ind[j]--;
        if (!ind[j]) {
          q[++qtail] = j;
        }
        if (dp[j] < dp[t1] + 1) {
          dp[j] = dp[t1] + 1;
          fa[j] = t1;
        }
      }
    }
  }
  
  if (dp[1] == 1) {
    puts("0");
    return 0;
  } else {
    printf("%d\n", dp[1] - 1);
    t1 = fa[1];
    while (t1 != 0) {
      printf("%d", t1 - 1);
      if (fa[t1]) printf(" "); else printf("\n");
      t1 = fa[t1];
    }
  }
  return 0;
}