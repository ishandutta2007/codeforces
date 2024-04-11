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
Int inv[1<<21];
Int K, PA, PB;

int memo[1024][1024];

Int solve(int ks, int as) {
  if (ks >= K) {
    return ks;
  }
  if (ks + as >= K) {
    return (as + ks + PA * inv[PB]) % MO;
  }

  if (memo[ks][as] >= 0) {
    return memo[ks][as];
  }

  const Int ra = solve(ks, as + 1) * PA % MO * inv[PA + PB] % MO;
  const Int rb = solve(ks + as, as) * PB % MO * inv[PA + PB] % MO;

  return (memo[ks][as] = (ra + rb) % MO);
}

int main() {
  K = in();
  PA = in();
  PB = in();

  inv[1] = 1;
  for (int i = 2; i < 1<<21; ++i) {
    inv[i] = MO - MO / i * inv[MO % i] % MO;
  }

  for (int i = 0; i <= 1000; ++i) {
    for (int j = 0; j <= 1000; ++j) {
      memo[i][j] = -1;
    }
  }

  printf("%lld\n", solve(0, 1));

  return 0;
}