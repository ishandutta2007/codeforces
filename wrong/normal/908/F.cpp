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

Int P[300050], dp[300050][2][2];
int C[300050];

int main() {
  const int N = in();
  const int R = 0, B = 1, G = 2;

  bool green = false;
  for (int i = 0; i < N; ++i) {
    char buf[4];
    P[i] = lin();
    scanf("%s", buf);
    C[i] = buf[0] == 'R' ? R : (buf[0] == 'B' ? B : G);
    green |= C[i] == G;
  }

  Int lef[3] = {INF, INF, INF}, rig[3] = {-INF, -INF, -INF};
  for (int i = 0; i < N; ++i) {
    chmin(lef[C[i]], P[i]);
    chmax(rig[C[i]], P[i]);
  }
  if (!green) {
    printf("%lld\n", max(0LL, rig[R] - lef[R]) + max(0LL, rig[B] - lef[B]));
    return 0;
  }

  for (int i = 0; i <= N; ++i) {
    dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = INFLL;
  }

  Int last[3] = {-INFLL, -INFLL, -INFLL};
  dp[0][0][0] = rig[G] - lef[G];
  for (int i = 0; i < N; ++i) {
    if (C[i] == R) {
      for (int b = 0; b < 2; ++b) {
        chmin(dp[i + 1][0][b], dp[i][0][b] + P[i] - max(last[R], last[G]));
        chmin(dp[i + 1][1][b], dp[i][0][b]);
        chmin(dp[i + 1][1][b], dp[i][1][b] + P[i] - last[R]);
      }
    } else if (C[i] == B) {
      for (int r = 0; r < 2; ++r) {
        chmin(dp[i + 1][r][0], dp[i][r][0] + P[i] - max(last[B], last[G]));
        chmin(dp[i + 1][r][1], dp[i][r][0]);
        chmin(dp[i + 1][r][1], dp[i][r][1] + P[i] - last[B]);
      }
    } else {
      for (int r = 0; r < 2; ++r) {
        for (int b = 0; b < 2; ++b) {
          Int v = dp[i][r][b];
          if (r == 1) v += P[i] - last[R];
          if (b == 1) v += P[i] - last[B];
          if (last[G] >= 0 && last[R] > last[G] && last[B] > last[G] && r == 0 && b == 0) v += min(0LL, P[i] - last[R] + P[i] - last[B] - (P[i] - last[G]));
          chmin(dp[i + 1][0][0], v);
        }
      }
    }
    last[C[i]] = P[i];
  }

  printf("%lld\n", dp[N][0][0]);

  return 0;
}