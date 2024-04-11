#include <cstring>
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
#include <cassert>

using namespace std;

const int inf = (int)1e9;
const int N = 1010;

char level[N][13][13];

int g[N][N];
int d[N], pr[N];
bool b[N];

int ans[N];

int main() {
  int h, w, n, c;
  scanf("%d %d %d %d", &h, &w, &n, &c);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < h; j++) {
      scanf("%s", level[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    g[i][i] = 0;
    for (int j = i + 1; j <= n; j++) {
      int cnt = 0;
      for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
          cnt += (level[i][x][y] != level[j][x][y]);
        }
      } 
      g[i][j] = g[j][i] = c * cnt;
    }
  }
  for (int i = 1; i <= n; i++) {
    g[0][i] = g[i][0] = h * w;
  }
  g[0][0] = 0;
  for (int i = 0; i <= n; i++) {
    d[i] = inf;
    b[i] = true;
    pr[i] = -1;
  }
  d[0] = 0;
  int res = 0;
  for (int it = 0; it <= n; it++) {
    int mn = inf, km = -1;
    for (int i = 0; i <= n; i++) {
      if (b[i] && d[i] < mn) {
        mn = d[i];
        km = i;
      }
    }
    b[km] = false;
    res += mn;
    ans[it] = km;
    for (int j = 0; j <= n; j++) {
      if (b[j] && g[km][j] < d[j]) {
        d[j] = g[km][j];
        pr[j] = km;
      }
    }
  }
  printf("%d\n", res);
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", ans[i], pr[ans[i]]);
  }
  return 0;
}