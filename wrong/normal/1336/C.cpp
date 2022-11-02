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

const Int MO = 998244353;

int slen, tlen;
char S[3333], T[3333];
Int dp[3333][3333];

int main() {
  scanf("%s%s", S, T);
  slen = strlen(S);
  tlen = strlen(T);

  for (int i = 0; i < tlen; ++i) {
    if (S[0] == T[i]) {
      dp[i][i + 1] = 2;
    }
  }
  for (int i = tlen; i < slen; ++i) {
    dp[i][i + 1] = 2;
  }

  for (int len = 1; len < slen; ++len) {
    for (int i = 0; i + len <= slen; ++i) {
      const int j = i + len;
      if (j < slen && (j >= tlen || S[len] == T[j])) {
        (dp[i][j + 1] += dp[i][j]) %= MO;
      }
      if (i > 0 && (i - 1 >= tlen || S[len] == T[i - 1])) {
        (dp[i - 1][j] += dp[i][j]) %= MO;
      }
    }
  }

  Int res = 0;
  for (int i = tlen; i <= slen; ++i) {
    (res += dp[0][i]) %= MO;
  }
  cout << res << endl;

  return 0;
}