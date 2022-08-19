#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000010;

int z[MAX];

const int N = 50010;

int a[N], g[N], b[N];
int from[N], to[N], best[N];

int main() {
  z[0] = 0;
  for (int i = 1; i < MAX; i++) {
    z[i] = z[i - 1] ^ i;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    g[i] = z[a[i]];
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", from + i, to + i);
    from[i]--; to[i]--;
    best[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    int mx = 0;
    for (int j = i; j < n; j++) {
      int cur = g[i] ^ g[j] ^ (a[i] < a[j] ? a[i] : a[j]);
      mx = max(mx, cur);
      b[j] = mx;
    }
    for (int k = 0; k < m; k++) {
      if (from[k] <= i && i <= to[k]) {
        best[k] = max(best[k], b[to[k]]);
      }
    }
  }
  for (int k = 0; k < m; k++) {
    printf("%d\n", best[k]);
  }
  return 0;
}