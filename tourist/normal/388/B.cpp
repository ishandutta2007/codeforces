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

char g[2010][2010];

int main() {
  int k;
  scanf("%d", &k);
  if (k == 1) {
    puts("2");
    puts("NY");
    puts("YN");
    return 0;
  }
  int mx = 0;
  for (int j = 0; j < 30; j++)
    if (k & (1 << j)) {
      mx = j;
    }
  memset(g, 'N', sizeof(g));
  int n = 2;
  int u = 1;
  for (int j = 1; j <= mx; j++) {
    n++;
    g[u][n] = g[n][u] = 'Y';
    int x = n;
    n++;
    g[u][n] = g[n][u] = 'Y';
    int y = n;
    int z;
    if (j == mx) {
      z = 2;
    } else {
      z = ++n;
    }
    g[x][z] = g[z][x] = 'Y';
    g[y][z] = g[z][y] = 'Y';
    u = z;
  }
  for (int j = mx - 1; j >= 0; j--) {
    if (k & (1 << j)) {
      int v = 3 * j + 2;
      if (j == 0) v--;
      int len = 2 * (mx - j);
      for (int it = 0; it < len - 1; it++) {
        n++;
        g[v][n] = g[n][v] = 'Y';
        v = n;
      }
      g[v][2] = g[2][v] = 'Y';
    }
  }
  printf("%d\n", n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) putchar(g[i][j]);
    putchar('\n');
  }
  return 0;
}