#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MAX = 333;

int a[444][444][13], new_a[444][444][13], ever[444][444];

int main() {
  int tt;
  scanf("%d", &tt);
  memset(ever, 0, sizeof(ever));
  memset(a, 0, sizeof(a));
  a[MAX / 2 + 1][MAX / 2][0] = 1;
  while (tt--) {
    int cnt;
    scanf("%d", &cnt);
    while (cnt--) {
      memset(new_a, 0, sizeof(new_a));
      for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
          for (int d = 0; d < 8; d++) {
            if (a[i][j][d]) { 
              int xk = i + dx[d];
              int yk = j + dy[d];
              if (xk >= 0 && yk >= 0 && xk < MAX && yk < MAX) {
                new_a[xk][yk][d] = 1;
              }
            }
          }
        }
      }
      for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
          for (int d = 0; d < 8; d++) {
            a[i][j][d] = new_a[i][j][d];
            ever[i][j] |= a[i][j][d];
          }
        }
      }
    }
    memset(new_a, 0, sizeof(new_a));
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        for (int d = 0; d < 8; d++) {
          if (a[i][j][d]) { 
            new_a[i][j][(d + 1) % 8] = 1;
            new_a[i][j][(d + 7) % 8] = 1;
          }
        }
      }
    }
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        for (int d = 0; d < 8; d++) {
          a[i][j][d] = new_a[i][j][d];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      ans += ever[i][j];
    }
  }
  printf("%d\n", ans);
  return 0;
}