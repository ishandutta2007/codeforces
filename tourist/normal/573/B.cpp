#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N], lf[N], rg[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int q = 1;
  for (int i = 0; i < n; i++) {
    q = min(q, a[i]);
    lf[i] = q;
    q++;
  }
  q = 1;
  for (int i = n - 1; i >= 0; i--) {
    q = min(q, a[i]);
    rg[i] = q;
    q++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, min(lf[i], rg[i]));
  }
  printf("%d\n", ans);
  return 0;
}