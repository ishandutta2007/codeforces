#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int x[N], y[N];
char s[N];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  x[0] = 0;
  y[0] = 0;
  for (int i = 0; i < n; i++) {
    x[i + 1] = x[i] + (s[i] == 'R' ? 1 : (s[i] == 'L' ? -1 : 0));
    y[i + 1] = y[i] + (s[i] == 'U' ? 1 : (s[i] == 'D' ? -1 : 0));
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (x[i] == x[j] && y[i] == y[j]) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}