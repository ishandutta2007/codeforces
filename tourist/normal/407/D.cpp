#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 444;
const int M = N * N;

short f[N][N][N];

inline void add(int xa, int ya, int xb, int yb) {
  yb--;
  if (yb < f[xa][xb][ya]) {
    f[xa][xb][ya] = yb;
  }
}

int last[M], was[M];
int a[N][N];

int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++) scanf("%d", a[i] + j);
  for (int i1 = 1; i1 <= r; i1++)
    for (int i2 = i1; i2 <= r; i2++)
      for (int j = 1; j <= c; j++) f[i1][i2][j] = c;
  for (int i = 0; i < M; i++) {
    last[i] = 0;
    was[i] = 0;
  }
  int it = 0;
  for (int i = 1; i <= r; i++) {
    it++;
    for (int j = c; j >= 1; j--) {
      if (was[a[i][j]] == it) {
        add(i, j, i, last[a[i][j]]);
      }
      last[a[i][j]] = j;
      was[a[i][j]] = it;
    }
  }
  for (int i1 = 1; i1 <= r; i1++) {
    for (int i2 = i1 + 1; i2 <= r; i2++) {
      it++;
      for (int j = c; j >= 1; j--) {
        if (was[a[i1][j]] == it) {
          add(i1, j, i2, last[a[i1][j]]);
        }
        last[a[i1][j]] = j;
        was[a[i1][j]] = it;
        if (was[a[i2][j]] == it) {
          add(i1, j, i2, last[a[i2][j]]);
        }
        last[a[i2][j]] = j;
        was[a[i2][j]] = it;
      }
    }
  }
  int ans = 0;
  for (int i1 = r; i1 >= 1; i1--)
    for (int i2 = i1; i2 <= r; i2++)
      for (int j = c; j >= 1; j--) {
        int ft = f[i1][i2][j];
        int area = (i2 - i1 + 1) * (ft - j + 1);
        if (area > ans) {
          ans = area;
        }
        if (i1 > 1 && ft < f[i1 - 1][i2][j]) {
          f[i1 - 1][i2][j] = ft;
        }
        if (i2 < r && ft < f[i1][i2 + 1][j]) {
          f[i1][i2 + 1][j] = ft;
        }
        if (j > 1 && ft < f[i1][i2][j - 1]) {
          f[i1][i2][j - 1] = ft;
        }
      }
  printf("%d\n", ans);
  return 0;
}