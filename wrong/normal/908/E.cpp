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
Int comb[1024][1024], dp[1024];

int en[1024][1024];
char S[1024];

int main() {
  for (int i = 0; i < 1024; ++i) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MO;
    }
  }

  dp[0] = dp[1] = 1;
  for (int i = 2; i < 1024; ++i) {
    for (int s = 0; s < i; ++s) {
      (dp[i] += comb[i - 1][s] * dp[s]) %= MO;
    }
  }

  const int B = in();
  const int N = in();
  for (int i = 0; i < B; ++i) {
    for (int j = 0; j < B; ++j) {
      en[i][j] = 1;
    }
  }

  for (int i = 0; i < N; ++i) {
    scanf("%s", S);
    vector<int> zer, one;
    for (int j = 0; j < B; ++j) {
      if (S[j] == '0') {
        zer.push_back(j);
      } else {
        one.push_back(j);
      }
    }
    for (const int z : zer) {
      for (const int o : one) {
        en[z][o] = en[o][z] = 0;
      }
    }
  }

  vector<int> done(B, 0);
  Int res = 1;
  for (int i = 0; i < B; ++i) {
    if (done[i]) {
      continue;
    }
    int sz = 0;
    for (int j = 0; j < B; ++j) {
      if (en[i][j]) {
        ++sz;
        done[j] = 1;
      }
    }
    (res *= dp[sz]) %= MO;
  }

  printf("%lld\n", res);

  return 0;
}