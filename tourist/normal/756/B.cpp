#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N];
long long f[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  f[0] = 0;
  for (int i = 0; i < n; i++) {
    f[i + 1] = f[i] + 20;
    f[i + 1] = min(f[i + 1], 50 + f[lower_bound(a, a + n, a[i] - 89) - a]);
    f[i + 1] = min(f[i + 1], 120 + f[lower_bound(a, a + n, a[i] - 1439) - a]);
    printf("%d\n", (int) (f[i + 1] - f[i]));
  }
  return 0;
}