#include <bits/stdc++.h>

using namespace std;

inline int decode(char c) {
  if ('0' <= c && c <= '9') {
    return c - '0';
  }
  return (c - 'a') + 10;
}

const int N = 77;

char foo[N], bar[N];
int a[N];
long long f[N][N][N];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s %s", foo, bar);
    long long ans = 0;
    for (int rot = 0; rot < 2; rot++) {
      int n;
      if (rot == 0) {
        n = strlen(bar);
        for (int i = 0; i < n; i++) {
          a[i] = decode(bar[n - i - 1]);
        }
      } else {
        n = strlen(foo);
        for (int i = 0; i < n; i++) {
          a[i] = decode(foo[n - i - 1]);
        }
        ans = -ans;
      }
      for (int max_d = 0; max_d < 16; max_d++) {
        int pos = max_d / 4;
        int bit = (1 << (max_d % 4));
        if (pos >= n) {
          continue;
        }
        for (int i = 0; i <= n; i++) {
          for (int eq = 0; eq < 2; eq++) {
            for (int was = 0; was < 2; was++) {
              f[i][eq][was] = 0;
            }
          }
        }
        f[n][1][0] = 1;
        for (int i = n; i > 0; i--) {
          for (int eq = 0; eq < 2; eq++) {
            for (int was = 0; was < 2; was++) {
              long long ft = f[i][eq][was];
              if (ft == 0) {
                continue;
              }
              int up = min(max_d, (eq == 0 ? 15 : a[i - 1]));
              for (int d = 0; d <= up; d++) {
                if (i - 1 == pos && !(d & bit)) {
                  continue;
                }
                int new_eq = (eq && (d == a[i - 1]));
                int new_was = (was || (d == max_d));
                f[i - 1][new_eq][new_was] += ft;
              }
            }
          }
        }
        int max_eq = (rot == 0 ? 1 : 0);
        for (int eq = 0; eq <= max_eq; eq++) {
          ans += f[0][eq][1];
        }
      }
      if (rot == 1) {
        ans = -ans;
      }
    }
    cout << ans << endl;
  }
  return 0;
}