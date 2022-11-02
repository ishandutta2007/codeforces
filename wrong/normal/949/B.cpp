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

Int solve(Int n, Int x) {
  if (n == 1 || x == 0) {
    return 1;
  }
  if (n % 2 == 1) {
    return solve(n - 1, (x - 2 + n - 1) % (n - 1)) + 1;
  }
  if (x % 2 == 0) {
    return x / 2 + 1;
  }
  return solve(n / 2, x / 2) + n / 2;
}

int main() {
  Int N = lin();
  int Q = in();

  while (Q--) {
    Int x = lin() - 1;
    printf("%I64d\n", solve(N, x));
  }

  return 0;
}