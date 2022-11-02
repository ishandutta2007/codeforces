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

char F[64][64], I[128];
const int DR[] = {1, 0, -1, 0}, DC[] = {0, 1, 0, -1};

int main() {
  int H, W;
  H = in();
  W = in();
  memset(F, '#', sizeof(F));

  int sr, sc, gr, gc;

  for (int i = 1; i <= H; ++i) {
    scanf("%s", &F[i][1]);
    F[i][W + 1] = '#';
    for (int j = 1; j <= W; ++j) {
      if (F[i][j] == 'S') {
        F[i][j] = '.';
        sr = i;
        sc = j;
      } else if (F[i][j] == 'E') {
        F[i][j] = '.';
        gr = i;
        gc = j;
      }
    }
  }
  H += 2;
  W += 2;

  scanf("%s", I);

  int DIR[4] = {0, 1, 2, 3};
  int res = 0;
  do {
    int r = sr, c = sc;
    for (int i = 0; I[i]; ++i) {
      int d = DIR[I[i] - '0'];
      const int rr = r + DR[d], cc = c + DC[d];
      if (F[rr][cc] == '#') {
        break;
      }
      r = rr;
      c = cc;
      if (r == gr && c == gc) {
        ++res;
        break;
      }
    }
  } while (next_permutation(DIR, DIR + 4));

  printf("%d\n", res);

  return 0;
}