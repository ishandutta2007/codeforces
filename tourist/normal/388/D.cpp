#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline int mul(int a, int b) {
  return 1LL * a * b % md;
}

const int N = 222;

int c[N][N];

int f[N][N][2];

int d[N];

int main() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (j == 0) c[i][j] = 1; else
      if (i < j) c[i][j] = 0; else {
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        if (c[i][j] >= md) c[i][j] -= md;
      }
  int k;
  scanf("%d", &k);
  for (int j = 0; j < 30; j++)
    if (k & (1 << j)) d[j] = 1;
    else d[j] = 0;
  memset(f, 0, sizeof(f));
  f[30][0][1] = 1;
  for (int j = 30; j > 0; j--)
    for (int open = 0; open <= 30 - j; open++)
      for (int eq = 0; eq <= 1; eq++) {
        int ft = f[j][open][eq];
        if (ft == 0) {
          continue;
        }
        if (eq == 0 || d[j - 1] == 1) {
          add(f[j - 1][open + 1][eq], ft);
        }
        for (int u = 0; u <= open; u++)
          if (u & 1) {
            if (eq == 0 || d[j - 1] == 1) {
              add(f[j - 1][open][eq], mul(ft, c[open][u]));
            }
          } else {
            int neq = eq;
            if (d[j - 1] == 1) neq = 0;
            add(f[j - 1][open][neq], mul(ft, c[open][u]));
          }
      }
  int ans = 0;
  for (int open = 0; open <= 30; open++)
    for (int eq = 0; eq <= 1; eq++)
      add(ans, f[0][open][eq]);
  printf("%d\n", ans);
  return 0;
}