#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

int VO[310][310], T[32], X[156];
bool V[310][310][151][4];

int DX[2][4] = {{0, -1, 0, 1}, {1, -1, -1, 1}};
int DY[2][4] = {{1, 0, -1, 0}, {1, 1, -1, -1}};

#define st(x, y, t, d) ((((((x<<9)|y)<<8)|t)<<2)|d)

int main() {
  int n = in();
  int tt = 0;
  for (int i = 0; i < n; ++i) {
    T[i] = in();
    for (int j = 0; j < T[i]; ++j) {
      X[tt++] = i;
    }
  }
  X[tt] = -1;

  queue<int> Q;
  Q.push(st(155, 155, 0, 0));
  VO[155][155] = 1;
  V[155][155][0][0] = true;

  while (!Q.empty()) {
    int state = Q.front(); Q.pop();
    int d = state & ((1<<2) - 1); state >>= 2;
    int t = state & ((1<<8) - 1); state >>= 8;
    int y = state & ((1<<9) - 1); state >>= 9;
    int x = state & ((1<<9) - 1);

    int tt = t + 1;
    if (X[tt] == -1) {
      break;
    }

    if (X[t] == X[tt]) {
      x += DX[X[t] & 1][d];
      y += DY[X[t] & 1][d];
      if (!V[x][y][tt][d]) {
        V[x][y][tt][d] = true;
        VO[x][y] = 1;
        Q.push(st(x, y, tt, d));
      }
    } else {
      for (int p = 0; p < 2; ++p) {
        int dd = (X[t] % 2 == 0 ? (d + p) % 4 : (d - p + 4) % 4);
        int xx = x + DX[X[tt] & 1][dd];
        int yy = y + DY[X[tt] & 1][dd];
        if (!V[xx][yy][tt][dd]) {
          V[xx][yy][tt][dd] = true;
          VO[xx][yy] = 1;
          Q.push(st(xx, yy, tt, dd));
        }
      }
    }
  }

  int res = 0;
  for (int x = 0; x < 310; ++x) {
    for (int y = 0; y < 310; ++y) {
      if (VO[x][y]) {
        ++res;
      }
    }
  }

  // for (int y=155+15;y>=155-1;--y){
  //   for (int x=155-10;x<=155+10;++x){
  //     putchar(".*"[VO[x][y]]);
  //   }
  //   puts("");
  // }

  printf("%d\n", res);

  return 0;
}