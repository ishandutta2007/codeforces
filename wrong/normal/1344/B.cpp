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

int U[1024], L[1024], D[1024], R[1024];
int RZ[1024], CZ[1024];
char F[1024][1024];

int main() {
  int H = in();
  int W = in();
  for (int r = 0; r < H; ++r) {
    L[r] = INF;
    R[r] = -INF;
  }
  for (int c = 0; c < W; ++c) {
    U[c] = INF;
    D[c] = -INF;
  }
  for (int i = 0; i < H; ++i) {
    scanf("%s", F[i]);
    for (int j = 0; j < W; ++j) {
      if (F[i][j] == '#') {
        chmin(U[j], i);
        chmax(D[j], i);
        chmin(L[i], j);
        chmax(R[i], j);
      }
    }
  }
  for (int r = 0; r < H; ++r) {
    for (int c = 0; c < W; ++c) {
      if (F[r][c] == '.') {
        if ((L[r] < c && c < R[r]) || (U[c] < r && r < D[c])) {
          puts("-1");
          return 0;
        }
      } else {
        ++RZ[r];
        ++CZ[c];
      }
    }
  }
  bool empty_r = *min_element(RZ, RZ + H) == 0;
  bool empty_c = *min_element(CZ, CZ + W) == 0;
  if ((empty_r && !empty_c) || (!empty_r && empty_c)) {
    puts("-1");
    return 0;
  }
  int res = 0;
  for (int r = 0; r < H; ++r) {
    for (int c = 0; c < W; ++c) {
      if (F[r][c] == '#') {
        ++res;
        queue<int> qr, qc;
        F[r][c] = '.';
        qr.push(r);
        qc.push(c);
        const int DR[] = {0, 1, 0, -1}, DC[] = {1, 0, -1, 0};
        while (!qr.empty()) {
          const int sr = qr.front(); qr.pop();
          const int sc = qc.front(); qc.pop();
          for (int d = 0; d < 4; ++d) {
            const int rr = sr + DR[d], cc = sc + DC[d];
            if (rr < 0 || cc < 0 || rr >= H || cc >= W || F[rr][cc] != '#') {
              continue;
            }
            F[rr][cc] = '.';
            qr.push(rr);
            qc.push(cc);
          }
        }
      }
    }
  }
  printf("%d\n", res);
  return 0;
}