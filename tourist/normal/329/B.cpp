#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int inf = (int)1e9;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

char s[1111][1111];
int x[1111111], y[1111111];
int dist[1111][1111];

int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  for (int i=0;i<r;i++) scanf("%s", s[i]);
  for (int i=0;i<r;i++)
    for (int j=0;j<c;j++) {
      dist[i][j] = inf;
      if (s[i][j] == 'E') {
        x[1] = i;
        y[1] = j;
        dist[i][j] = 0;
      }
    }
  int b = 1, e = 1;
  while (b <= e) {
    for (int j=0;j<4;j++) {
      int xk = x[b]+dx[j];
      int yk = y[b]+dy[j];
      if (xk >= 0 && yk >= 0 && xk < r && yk < c)
        if (s[xk][yk] != 'T' && dist[xk][yk] == inf) {
          e++;
          x[e] = xk;
          y[e] = yk;
          dist[xk][yk] = dist[x[b]][y[b]]+1;
        }
    }
    b++;
  }
  int thr = -1;
  for (int i=0;i<r;i++)
    for (int j=0;j<c;j++)
      if (s[i][j] == 'S') thr = dist[i][j];
  int ans = 0;
  for (int i=0;i<r;i++)
    for (int j=0;j<c;j++)
      if (s[i][j] >= '0' && s[i][j] <= '9')
        if (dist[i][j] <= thr) ans += s[i][j]-'0';
  printf("%d\n", ans);
  return 0;
}