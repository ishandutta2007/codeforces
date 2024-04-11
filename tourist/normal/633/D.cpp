#include <bits/stdc++.h>                          

using namespace std;

const int N = 12345;

int a[N], b[N];
int f[N];
int pos[N];

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    ans += (a[i] == 0);
  }
  sort(a, a + n);
  int nn = 1;
  b[0] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[nn - 1]) {
      b[nn - 1]++;
      continue;
    }
    a[nn] = a[i];
    b[nn] = 1;
    nn++;
  }
  ans = max(ans, 2);
  for (int i0 = 0; i0 < nn; i0++) {
    f[0] = a[i0];
    b[i0]--;
    for (int i1 = 0; i1 < nn; i1++) {
      if (b[i1] == 0 || (a[i0] == 0 && a[i1] == 0)) {
        continue;
      }
      f[1] = a[i1];
      b[i1]--;
      for (int j = 2; ; j++) {
        f[j] = f[j - 1] + f[j - 2];
        pos[j] = lower_bound(a, a + nn, f[j]) - a;
        if (pos[j] == nn || a[pos[j]] != f[j] || b[pos[j]] == 0) {
          while (j > 2) {
            j--;
            b[pos[j]]++;
          }
          break;
        }
        ans = max(ans, j + 1);
        b[pos[j]]--;
      }
      b[i1]++;
    }
    b[i0]++;
  }
  printf("%d\n", ans);
  return 0;
}