//171H
#include<cstdio>

int a, n, x, y, pow2[55];

void go(int a, int n, int &x, int &y) {
  if (a == 0) {
    x = 0; y = 0;
    return ;
  }
  int cnt;
  cnt = pow2[2 * (a - 1)];
  if (n < cnt) {
     go(a - 1, n, y, x);
     return;
  }
  cnt = cnt + pow2[2 * (a - 1)];
  if (n < cnt) {
    go(a - 1, n - pow2[2 * (a - 1)], x, y);
    y = y + pow2[a - 1];
    return;
  }
  if (n < cnt + pow2[2 * (a - 1)]) {
    go(a - 1, n - cnt, x, y);
    x = x + pow2[a - 1];
    y = y + pow2[a - 1];
    return;
  }
  cnt = cnt + pow2[2 * (a - 1)];
  go(a - 1, n - cnt, y, x);
  x = pow2[a] - x - 1;
  y = pow2[a - 1] - y - 1;
  return;
}

int main() {
  pow2[0] = 1;
  for (int i = 1; i <= 30; i++) pow2[i] = 2 * pow2[i - 1];
  scanf("%d %d", &a, &n);
  go(a, n, x, y);
  printf("%d %d\n", x, y);
  return 0;
}