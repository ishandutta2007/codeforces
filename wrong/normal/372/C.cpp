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

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int A[333], B[333], T[333];
Int dp[155555];
Int M1[155555], M2[155555];

void slide_min(Int *X, Int K, Int D) {
  if (D == 1) {
    return;
  }

  for (Int i = 0; i < K; i += D) {
    Int to = min(i + D, K);

    M1[i] = X[i];
    for (int j = i + 1; j < to; ++j) {
      M1[j] = min(M1[j - 1], X[j]);
    }
    M2[to - 1] = X[to - 1];
    for (int j = to - 2; j >= i; --j) {
      M2[j] = min(M2[j + 1], X[j]);
    }
  }

  for (int i = 0; i < K; ++i) {
    X[i] = min(M1[i], M2[i]);
    X[i] = min(X[i], M1[min(i + D - 1, K - 1)]);
    X[i] = min(X[i], M2[max(i - D + 1, 0LL)]);
  }
}

int main()
{
  int n, m, d;
  scanf("%d%d%d", &n, &m, &d);

  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &A[i], &B[i], &T[i]);
  }

  int t = 1;
  for (int i = 0; i < m; ++i) {
    Int t_diff = T[i] - t;
    slide_min(dp, n, t_diff * d + 1);
    for (int j = 0; j < n; ++j) {
      dp[j] += abs(A[i] - 1 - j);
    }
    t = T[i];
  }

  Int res = 0;
  for (int i = 0; i < m; ++i) {
    res += B[i];
  }

  cout << res - *min_element(dp, dp + n) << endl;

  return 0;
}