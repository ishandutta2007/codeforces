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

const Int MO = 1000000007;
Int pow10[1024];

int N, X[1024];
Int dp[10][800][800][2];
Int cnt[10][800];

void solve(int D) {
  dp[D][0][0][1] = 1;
  for (int i = 0; i < N; ++i) {
    for (int les = 0; les <= i; ++les) {
      for (int eq = 0; eq < 2; ++eq) {
        if (dp[D][i][les][eq] == 0) {
          continue;
        }
        for (int d = 0; d <= 9; ++d) {
          if (eq == 1 && d > X[i]) continue;
          (dp[D][i + 1][les + (d <= D ? 1 : 0)][eq && (d == X[i])] += dp[D][i][les][eq]) %= MO;
        }
      }
    }
  }

  cnt[D][N] = (dp[D][N][N][0] + dp[D][N][N][1]) % MO;
  for (int u = N - 1; u >= 0; --u) {
    cnt[D][u] = cnt[D][u + 1];
    (cnt[D][u] += dp[D][N][u][0] + dp[D][N][u][1]) %= MO;
  }
}

int main() {
  pow10[0] = 1;
  for (int i = 1; i < 1024; ++i) {
    pow10[i] = pow10[i - 1] * 10 % MO;
  }

  char S[1024];
  scanf("%s", S);
  N = strlen(S);
  for (int i = 0; i < N; ++i) {
    X[i] = S[i] - '0';
  }

  for (int d = 0; d <= 9; ++d) {
    solve(d);
  }

  Int res = 0;
  for (int pos = 0; pos < N; ++pos) {
    const Int ee = pow10[N - pos - 1];
    for (int d = 1; d <= 9; ++d) {
      Int ks = (cnt[d][pos + 1] - cnt[d - 1][pos + 1] + MO) % MO;
      (res += ks * d % MO * ee) %= MO;
    }
  }

  printf("%lld\n", res);

  return 0;
}