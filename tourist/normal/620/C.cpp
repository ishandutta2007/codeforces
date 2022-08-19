#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N], x[N], y[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  set <int> used;
  int cnt = 0;
  int from = 0;
  for (int i = 0; i < n; i++) {
    if (used.find(a[i]) != used.end()) {
      x[cnt] = from;
      y[cnt] = i;
      cnt++;
      used.clear();
      from = i + 1;
    } else {
      used.insert(a[i]);
    }
  }
  if (cnt == 0) {
    printf("%d\n", -1);
    return 0;
  }
  y[cnt - 1] = n - 1;
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) {
    printf("%d %d\n", 1 + x[i], 1 + y[i]);
  }
  return 0;
}