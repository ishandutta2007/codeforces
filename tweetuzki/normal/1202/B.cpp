#include <bits/stdc++.h>
using namespace std;

int f[10][10][10];

int main() {
  memset(f, -1, sizeof f);
  for (int n = 0; n < 10; ++n) {
    for (int a = 0; a < 10; ++a) {
      for (int b = 0; b < 10; ++b) {
        for (int i = 0; i < 10; ++i) {
          for (int j = 0; j < 10; ++j) {
            if (i == 0 && j == 0) continue;
            int s = (a * i + b * j) % 10;
            if (s == n) {
              if (f[n][a][b] == -1) f[n][a][b] = i + j;
              else f[n][a][b] = min(f[n][a][b], i + j);
            }
          }
        }
//        printf("f[%d][%d][%d] = %d\n", n, a, b, f[n][a][b]);
      }
    }
  }
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      int ans = -n + 1;
      for (int k = 1; k < n; ++k) {
        int d = s[k] - s[k - 1];
        if (d < 0) d += 10;
        if (f[d][i][j] == -1) {
          ans = -1;
          break;
        }
        ans += f[d][i][j];
      }
      printf("%d%c", ans, j == 9 ? '\n' : ' ');
    }
  }
  return 0;
}