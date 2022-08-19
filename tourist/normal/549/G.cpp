#include <bits/stdc++.h>

using namespace std;

int a[1234567];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i] += i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    a[i] -= i;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      puts(":(");
      return 0;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n - 1]);
  return 0;
}