#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

int a[N], to[N];
long long s[N];

int main() {
  int n, tt;
  scanf("%d %d", &n, &tt);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    a[n + i] = a[i];
  }
  s[0] = 0;
  for (int i = 0; i < 2 * n; i++) {
    s[i + 1] = s[i] + a[i];
  }
  for (int qq = 0; qq < tt; qq++) {
    long long b;
    cin >> b;
    int j = 2 * n;
    for (int i = 2 * n - 1; i >= 0; i--) {
      while (s[j] - s[i] > b) {
        j--;
      }
      to[i] = j;
    }
    int best = 0;
    for (int i = 1; i < n; i++) {
      if (to[i] - i < to[best] - best) {
        best = i;
      }
    }
    int ans = n;
    int start = best;
    for (int z = best; z <= to[best]; z++) {
      int steps = 0;
      int where = start;
      while (where < start + n) {
        steps++;
        where = to[where];
      }
      if (steps < ans) {
        ans = steps;
      }
      start++;
      if (start >= n) {
        start -= n;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}