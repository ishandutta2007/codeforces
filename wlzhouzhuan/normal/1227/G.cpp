#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int b[N][N];
int a[N], id[N], f[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
  sort(id + 1, id + n + 1, [&](int x, int y) {
    return a[x] > a[y];
  });
  for (int i = 1; i <= n; i++) f[id[i]] = i;
  for (int i = 1; i <= n; i++) {
    int k = i;
    while (a[id[i]]--) {
      b[k][i] = 1;
      if (k == n + 1) k = 1;
      else k++;
    }
  }
  printf("%d\n", n + 1);
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d", b[i][f[j]]);
    }
    puts("");
  }
  return 0;
}