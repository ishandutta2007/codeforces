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
#include <random>
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
const int MAXN = 200050;
Int fac[MAXN], inv[MAXN], ifac[MAXN];

Int comb(int n, int r) {
  return fac[n] * ifac[r] % MO * ifac[n - r] % MO;
}

Int powmod(Int x, Int e) {
  Int v = 1;
  for (; e; e >>= 1, (x *= x) %= MO)
    if (e & 1) (v *= x) %= MO;
  return v;
}

int main() {
  inv[1] = 1;
  for (int i = 2; i < MAXN; ++i) inv[i] = (MO - (MO / i) * inv[MO % i] % MO) % MO;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fac[i] = fac[i - 1] * i % MO;
    ifac[i] = ifac[i - 1] * inv[i] % MO;
  }

  const int N = in();
  const int K = in();
  if (N == 1) {
    printf("%d\n", in());
    return 0;
  }

  Int sum = 0;
  for (int j = 0; j < K; ++j) {
    const Int x = powmod(1 + j, N - 1);
    const Int y = powmod(1 + j, N - 2) * (N - 1) % MO;
    const Int v = comb(K - 1, j) * (x + y) % MO;
    (sum += (K - j - 1) % 2 ? (MO - v) : v) %= MO;
  }

  Int w = 0;
  for (int i = 0; i < N; ++i) {
    (w += in()) %= MO;
  }

  printf("%d\n", (int)(sum * w % MO * ifac[K - 1] % MO));
  return 0;
}