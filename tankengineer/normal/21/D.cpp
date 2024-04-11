//21D
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, g[16][16], sum, d[16], u, v, l, f[65536], p;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) g[i][j] = 200000000;
    }
  }
  sum = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &l);
    u--; v--;
    d[u]++; d[v]++;
    g[v][u] = g[u][v] = min(g[u][v], l);
    sum += l;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (d[i] > 0 && g[0][i] == 200000000) {
      puts("-1");
      return 0;
    }
  }
  f[0] = 0;
  for (int i = 1, j = 0; i < (1 << n); i++) {
    f[i] = 200000000;
    if (i == (1 << j + 1)) j++;
    for (int k = 0; k < j; k++) {
      f[i] = min(f[i], f[i ^ ((1 << j) + (1 << k))] + g[j][k]);
    }
  }
  
  p = 0;
  for (int i = 0; i < n; i++) {
    if (d[i] % 2) p = p + (1 << i);
  }
  if (f[p] == 200000000) {
    puts("-1");
  } else {
    printf("%d\n", f[p] + sum);
  }
  
  return 0;
}