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

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }

const int MO = 1000000007;

int N;
char X[5050];
int dp1[5050][5050], dp2[5050][5050], acc[5050][5050], asc[5050][5050];
int acc2[5050][5050];

int leq(int x, int y, int len) {
  for (int i = 0; i < len; ++i) {
    if (X[x + i] > X[y + i]) {
      return i;
    } else if (X[x + i] < X[y + i]) {
      return len;
    }
  }
  return len;
}

void solve() {
  X[N] = '1';
  for (int i = 1; i + i <= N; ++i) {
    asc[N - i + 1][i] = leq(N - i + 1 - i, N - i + 1, i);
    for (int j = N - i; j >= i; --j) {
      if (X[j - i] < X[j]) {
        asc[j][i] = i;
      } else if (X[j - i] > X[j]) {
        asc[j][i] = 0;
      } else {
        asc[j][i] = 1 + min(i - 1, asc[j + 1][i]);
      }
    }
  }

  for (int i = 0; i < 5050; ++i) {
    for (int j = 0; j < 5050; ++j) {
      acc2[i][j] = dp2[i][j] = INF;
    }
  }

  dp1[0][0] = 1;
  dp2[0][0] = 0;
  for (int i = 0; i <= N; ++i) {
    for (int k = 0; k <= i; ++k) {
      if (i > 0 && k > 0) {
        (acc[i][k] += acc[i - 1][k - 1]) %= MO;
        chmin(acc2[i][k], acc2[i - 1][k - 1]);
      }
      (dp1[i][k] += acc[i][k]) %= MO;
      chmin(dp2[i][k], acc2[i][k]);
      if (i < N && X[i] != '0') {
        if (k > 0 && asc[i][k] >= k) {
          (dp1[i + k][k] += dp1[i][k]) %= MO;
          chmin(dp2[i + k][k], dp2[i][k] + 1);
        }
        if (i + k + 1 <= N) {
          (acc[i + k + 1][k + 1] += dp1[i][k]) %= MO;
          chmin(acc2[i + k + 1][k + 1], dp2[i][k] + 1);
        }
      }
    }
  }

  int res1 = 0;
  for (int k = 1; k <= N; ++k) {
    (res1 += dp1[N][k]) %= MO;
  }
  cout << res1 << endl;

  int res2 = INF;
  for (int k = 1; k <= 20; ++k) {
    if (dp2[N][k] < INF) {
      int am = 0;
      for (int i = N - k; i < N; ++i) {
        am = am * 2 + X[i] - '0';
      }
      chmin(res2, am + dp2[N][k]);
    }
  }
  if (res2 == INF) {
    for (int k = 21; k <= N; ++k) {
      if (dp2[N][k] < INF) {
        res2 = 0;
        for (int i = N - k; i < N; ++i) {
          res2 = ((res2 * 2) + X[i] - '0') % MO;
        }
        (res2 += dp2[N][k]) %= MO;
        break;
      }
    }
  }
  cout << res2 << endl;
}

int main()
{
  scanf("%s", X);
  N = strlen(X);

  solve();

  return 0;
}