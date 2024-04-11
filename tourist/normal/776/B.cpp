#include <bits/stdc++.h>

using namespace std;

int ans[1234567];

int main() {
  int n;
  scanf("%d", &n);
  int mx = 0;
  for (int i = 2; i <= n + 1; i++) {
    int tmp = i;
    ans[i] = 0;
    for (int j = 2; j * j <= tmp; j++) {
      while (tmp % j == 0) {
        ans[i]++;
        tmp /= j;
      }
    }
    if (tmp > 1) {
      ans[i]++;
    }
    if (ans[i] >= 2) {
      ans[i] = 2;
    }
    mx = max(mx, ans[i]);
  }
  printf("%d\n", mx);
  for (int i = 2; i <= n + 1; i++) {
    if (i > 2) putchar(' ');
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}