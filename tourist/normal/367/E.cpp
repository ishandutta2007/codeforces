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

const long long md = 1000000007;
const int N = 333;

int f[N][N], nf[N][N];

int main() {
  int n, m, x;
  scanf("%d %d %d", &n, &m, &x);
  if (n > m) {
    printf("%d\n", 0);
    return 0;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++) f[i][j] = 0;
  f[0][0] = 1;
  for (int v = 1; v <= m; v++) {
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= i; j++) nf[i][j] = 0;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= i; j++)
        for (int dx = (v == x); dx <= 1 && i + dx <= n; dx++)
          for (int dy = 0; dy <= 1 && j + dy <= i + dx; dy++) {
            nf[i + dx][j + dy] += f[i][j];
            if (nf[i + dx][j + dy] >= md) nf[i + dx][j + dy] -= md;
          }
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= i; j++) f[i][j] = nf[i][j];
  }
  int ans = f[n][n];
  for (int i = 1; i <= n; i++) ans = (long long)ans * i % md;
  printf("%d\n", ans);
  return 0;
}