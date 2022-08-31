#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

char foo[N];

int a[N], s[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", foo);
  for (int i = 0; i < n; i++) {
    a[i] = (foo[i] == '0');
  }
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
  }
  int ans = (int) 1e9;
  for (int pos = 0; pos < n; pos++) {
    if (a[pos] == 0) {
      continue;
    }
    int low = 0, high = n;
    while (low < high) {
      int mid = (low + high) >> 1;
      int from = max(0, pos - mid);
      int to = min(n - 1, pos + mid);
      int cnt = s[to + 1] - s[from];
      if (cnt >= k + 1) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    ans = min(ans, low);
  }
  printf("%d\n", ans);
  return 0;
}