/**
 *    author:  tourist
 *    created: 16.09.2017 20:41:02       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N], f[N];

int main() {
  int n;
  scanf("%d", &n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    total += a[i];
  }
  f[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    f[i] = abs(a[i] - f[i + 1]);
  }
  printf("%d %d\n", (total - f[0]) / 2, (total + f[0]) / 2);
  return 0;
}