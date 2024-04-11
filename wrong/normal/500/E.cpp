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

struct MaxBIT {
  int N;
  Int B[200050];
  MaxBIT() { }
  MaxBIT(int n) {
    N = n;
    for (int i = 1; i <= N; ++i) {
      B[i] = 0;
    }
  }
  void upd(int x, Int v) {
    ++x;
    while (x <= N) {
      chmax(B[x], v);
      x += x & -x;
    }
  }
  Int query(int x) {
    Int res = 0;
    ++x;
    while (x > 0) {
      chmax(res, B[x]);
      x -= x & -x;
    }
    return res;
  }
};

Int P[200050], L[200050];
MaxBIT to, pos;
Int nxt[20][200050], cst[20][200050];

int main() {
  int N = in();
  for (int i = 0; i < N; ++i) {
    P[i] = in();
    L[i] = in();
  }
  to = MaxBIT(N);
  pos = MaxBIT(N);

  for (int i = N - 1; i >= 0; --i) {
    int lo = i, hi = N;
    while (hi - lo > 1) {
      int mid = (hi + lo) / 2;
      if (P[mid] <= P[i] + L[i]) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    nxt[0][i] = max((Int)i, to.query(lo)) + 1;
    Int pp = max(P[i] + L[i], pos.query(lo));
    cst[0][i] = nxt[0][i] == N ? 0 : P[nxt[0][i]] - pp;
    to.upd(i, nxt[0][i] - 1);
    pos.upd(i, pp);
  }
  nxt[0][N] = N;
  cst[0][N] = 0;

  for (int i = 1; i < 20; ++i) {
    for (int j = 0; j <= N; ++j) {
      nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
      cst[i][j] = cst[i - 1][j] + cst[i - 1][nxt[i - 1][j]];
    }
  }

  int Q = in();
  for (int i = 0; i < Q; ++i) {
    int x = in() - 1;
    int y = in() - 1;
    Int res = 0;
    for (int j = 19; j >= 0; --j) {
      if (nxt[j][x] <= y) {
        res += cst[j][x];
        x = nxt[j][x];
      }
    }
    printf("%I64d\n", res);
  }

  return 0;
}