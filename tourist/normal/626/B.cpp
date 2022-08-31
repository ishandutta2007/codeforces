#include <bits/stdc++.h>

using namespace std;

const int N = 222;

bool was[N][N][N];
char s[N];
int x[N * N * N], y[N * N * N], z[N * N * N];
int e;

inline void put(int i, int j, int k) {
  if (was[i][j][k]) {
    return;
  }
  e++;
  x[e] = i;
  y[e] = j;
  z[e] = k;
  was[i][j][k] = true;
}

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  x[1] = 0;
  y[1] = 0;
  z[1] = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') x[1]++;
    if (s[i] == 'G') y[1]++;
    if (s[i] == 'B') z[1]++;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        was[i][j][k] = false;
      }
    }
  }
  was[x[1]][y[1]][z[1]] = true;
  int b = 1;
  e = 1;
  while (b <= e) {
    int i = x[b], j = y[b], k = z[b];
    if (i > 0 && j > 0) {
      put(i - 1, j - 1, k + 1);
    }
    if (i > 0 && k > 0) {
      put(i - 1, j + 1, k - 1);
    }
    if (j > 0 && k > 0) {
      put(i + 1, j - 1, k - 1);
    }
    if (i > 1) {
      put(i - 1, j, k);
    }
    if (j > 1) {
      put(i, j - 1, k);
    }
    if (k > 1) {
      put(i, j, k - 1);
    }
    b++;
  }
  if (was[0][0][1]) {
    putchar('B');
  }
  if (was[0][1][0]) {
    putchar('G');
  }
  if (was[1][0][0]) {
    putchar('R');
  }
  putchar('\n');
  return 0;
}