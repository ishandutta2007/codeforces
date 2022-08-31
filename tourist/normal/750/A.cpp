#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (k + 5 * i <= 240) {
      ans++;
      k += 5 * i;
    }
  }
  printf("%d\n", ans);
  return 0;
}