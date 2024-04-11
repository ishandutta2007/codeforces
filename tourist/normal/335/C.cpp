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
#include <cassert>
#include <memory.h>

using namespace std;

int g[111][111];

int grundy(int a11, int a12, int an1, int an2, int n) {
  int mask = (a11 << 3) + (a12 << 2) + (an1 << 1) + (an2 << 0);
  if (g[mask][n] != -1) return g[mask][n];
  int a[111][5];
  for (int i=1;i<=n;i++) a[i][1] = a[i][2] = 0;
  a[1][1] = a11;
  a[1][2] = a12;
  a[n][1] = an1;
  a[n][2] = an2;
  bool was[260];
  for (int i=0;i<260;i++) was[i] = false;
  bool alive[111];
  for (int i=1;i<=n;i++)
    for (int j=1;j<=2;j++)
      if (a[i][j] == 0) {
        a[i][j]++;
        a[i-1][3-j]++;
        a[i][3-j]++;
        a[i+1][3-j]++;

        for (int q=1;q<=n;q++) alive[q] = (a[q][1]*a[q][2] == 0);
        int st = 1, res = 0;
        while (st <= n) {
          while (st <= n && !alive[st]) st++;
          if (st > n) break;
          int fin = st;
          while (fin + 1 <= n && alive[fin + 1]) fin++;
          res ^= grundy(a[st][1], a[st][2], a[fin][1], a[fin][2], fin - st + 1);
          st = fin + 1;
        }
        was[res] = true;
        
        a[i][j]--;
        a[i-1][3-j]--;
        a[i][3-j]--;
        a[i+1][3-j]--;
      }
  int &ans = g[mask][n];
  ans = 0;
  while (was[ans]) ans++;
  return ans;
}

int main() {
  int n, cnt, a[111][5];
  scanf("%d %d", &n, &cnt);
  for (int i=1;i<=n;i++) a[i][1] = a[i][2] = 0;
  for (int i=0;i<cnt;i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[x][y] = 1;
    a[x-1][3-y] = 1;
    a[x][3-y] = 1;
    a[x+1][3-y] = 1;
  }
  memset(g, 255, sizeof(g));
  bool alive[111];

  for (int q=1;q<=n;q++) alive[q] = (a[q][1]*a[q][2] == 0);
  int st = 1, res = 0;
  while (st <= n) {
    while (st <= n && !alive[st]) st++;
    if (st > n) break;
    int fin = st;
    while (fin + 1 <= n && alive[fin + 1]) fin++;
    res ^= grundy(a[st][1], a[st][2], a[fin][1], a[fin][2], fin - st + 1);
    st = fin + 1;
  }
  
  puts(res > 0 ? "WIN" : "LOSE");
  return 0;
}