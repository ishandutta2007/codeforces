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

int G[30050];
int dp[30050][512];

int main() {
  int N = in();
  int D = in();

  for (int i = 0; i < N; ++i) {
    ++G[in()];
  }
  for (int i = D; i <= 30000; ++i) {
    fill(dp[i], dp[i] + 512, -INF);
  }

  int res = G[D];
  dp[D][250] = G[D];
  for (int i = D; i < 30000; ++i) {
    for (int d = 0; d <= 500; ++d) {
      if (dp[i][d] >= 0) {
        for (int dd = d - 1; dd <= d + 1; ++dd) {
          if (dd - 250 + D <= 0 || dd < 0 || dd > 500) {
            continue;
          }
          int ii = i + (dd - 250) + D;
          if (ii <= 30000) {
            chmax(dp[ii][dd], dp[i][d] + G[ii]);
            chmax(res, dp[ii][dd]);
          }
        }
      }
    }
  }

  printf("%d\n", res);
  return 0;
}