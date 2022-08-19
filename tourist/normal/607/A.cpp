#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int f[N], nxt[N];
pair <int, int> a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    int low = -1, high = i - 1;
    while (low < high) {
      int mid = low + (high - low + 1) / 2;
      if (a[mid].first < a[i].first - a[i].second) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    nxt[i] = low;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    f[i] = 1 + (nxt[i] >= 0 ? f[nxt[i]] : 0);
    ans = max(ans, f[i]);
  }
  printf("%d\n", n - ans);
  return 0;
}