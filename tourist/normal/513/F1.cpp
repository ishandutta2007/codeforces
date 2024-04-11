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
const int N = 100010; // !!!

int fin;
int ss[N], ff[N], c[N], f[N], obr[N], pred[N], last[N], st[N];
int m;

void add(int x, int y, int z, int xx, int yy) {
  m++;
  ss[m] = x;
  ff[m] = y;
  c[m] = z;
  f[m] = xx;
  obr[m] = yy;
}

int x[N], d[N];

bool expath() {
  for (int i = 0; i <= fin; i++) d[i] = -1;
  int b = 1, e = 1;
  x[1] = 0;
  d[0] = 0;
  while (b <= e) {
    int j = last[x[b]];
    while (j > 0) {
      if (c[j] > f[j] && d[ff[j]] == -1) {
        e++;
        x[e] = ff[j];
        d[x[e]] = d[x[b]] + 1;
        if (x[e] == fin) {
          return true;
        }
      }
      j = pred[j];
    }
    b++;
  }
  return false;
}

int rec(int v, int w) {
  if (v == fin) {
    return w;
  }
  int r = 0, j = last[v];
  while (j > 0) {
    last[v] = pred[j];
    if (c[j] > f[j] && d[ff[j]] == d[v] + 1) {
      int ww = c[j] - f[j];
      if (w - r < ww) ww = w - r;
      int t = rec(ff[j], ww);
      if (t > 0) {
        f[j] += t;
        if (obr[j] != 0) f[obr[j]] -= t;
        r += t;
        if (r == w) break;
      }
    }
    j = pred[j];
  }
  return r;
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int h, w, males, females;
int mx[N], my[N], mspeed[N];
int fx[N], fy[N], fspeed[N];
int dist[42][42][42][42];

bool can(long long value) {
  fin = males + 2 * h * w + females + 1;
  m = 0;
  for (int i = 1; i <= males; i++) {
    add(0, i, 1, 0, 0);
  }
  for (int i = 1; i <= females; i++) {
    add(males + 2 * h * w + i, fin, 1, 0, 0);
  }
  for (int i = 1; i <= h * w; i++) {
    add(males + i, males + i + h * w, 1, 0, m + 2);
    add(males + i + h * w, males + i, 0, 0, m);
  }
  for (int i = 1; i <= males; i++) {
    for (int j = 1; j <= h * w; j++) {
      int xa = mx[i - 1] - 1;
      int ya = my[i - 1] - 1;
      int xb = (j - 1) / w;
      int yb = (j - 1) % w;
      if (dist[xa][ya][xb][yb] != -1) {
        if (dist[xa][ya][xb][yb] * 1LL * mspeed[i - 1] <= value) {
          add(i, males + j, 1, 0, m + 2);
          add(males + j, i, 0, 0, m);
        }
      }
    }
  }
  for (int i = 1; i <= females; i++) {
    for (int j = 1; j <= h * w; j++) {
      int xa = fx[i - 1] - 1;
      int ya = fy[i - 1] - 1;
      int xb = (j - 1) / w;
      int yb = (j - 1) % w;
      if (dist[xa][ya][xb][yb] != -1) {
        if (dist[xa][ya][xb][yb] * 1LL * fspeed[i - 1] <= value) {
          add(males + h * w + j, males + 2 * h * w + i, 1, 0, m + 2);
          add(males + 2 * h * w + i, males + h * w + j, 0, 0, m);
        }
      }
    }
  }
  for (int i = 0; i <= fin; i++) {
    last[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  for (int i = 0; i <= fin; i++) {
    st[i] = last[i];
  }
  int ans = 0;
  while (expath()) {
    int t = rec(0, inf);
    ans += t;
    for (int i = 0; i <= fin; i++) {
      last[i] = st[i];
    }
  }
  return (ans == males);
}

char grid[42][42];
int y[N];

int main() {
  scanf("%d %d %d %d", &h, &w, &males, &females);
  if (abs(males - females) != 1) {
    printf("%d\n", -1);
    return 0;
  }
  for (int i = 0; i < h; i++) {
    scanf("%s", grid[i]);
  }
  for (int ii = 0; ii < h; ii++) {
    for (int jj = 0; jj < w; jj++) {
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          dist[ii][jj][i][j] = -1;
        }
      }
      if (grid[ii][jj] == '#') {
        continue;
      }
      int b = 0, e = 0;
      x[0] = ii;
      y[0] = jj;
      dist[ii][jj][ii][jj] = 0;
      while (b <= e) {
        for (int q = 0; q < 4; q++) {
          int xk = x[b] + dx[q];
          int yk = y[b] + dy[q];
          if (xk >= 0 && yk >= 0 && xk < h && yk < w) {
            if (grid[xk][yk] == '.' && dist[ii][jj][xk][yk] == -1) {
              e++;
              x[e] = xk;
              y[e] = yk;
              dist[ii][jj][xk][yk] = dist[ii][jj][x[b]][y[b]] + 1;
            }
          }
        }
        b++;
      }
    }
  }
  if (males < females) {
    males++;
    for (int i = 0; i < males; i++) {
      scanf("%d %d %d", mx + i, my + i, mspeed + i);
    }
    for (int i = 0; i < females; i++) {
      scanf("%d %d %d", fx + i, fy + i, fspeed + i);
    }
  } else {
    females++;
    for (int i = 0; i < 1; i++) {
      scanf("%d %d %d", fx + i, fy + i, fspeed + i);
    }
    for (int i = 0; i < males; i++) {
      scanf("%d %d %d", mx + i, my + i, mspeed + i);
    }
    for (int i = 1; i < females; i++) {
      scanf("%d %d %d", fx + i, fy + i, fspeed + i);
    }
  }
  long long low = 0, high = (long long)1e15;
  while (low < high) {
    long long mid = (low + high) >> 1;
    if (can(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  if (low == (long long)1e15) low = -1;
  cout << low << endl;
  return 0;
}