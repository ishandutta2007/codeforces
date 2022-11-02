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

int C[200050], D[200050];

int main() {
  int n = in();
  bool all1 = true;
  for (int i = 0; i < n; ++i) {
    C[i] = in();
    D[i] = in();
    all1 &= D[i] == 1;
  }

  if (all1) {
    puts("Infinity");
    return 0;
  }

  int lo = -INF, hi = INF;
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    bool ok = true;
    int r = mid;
    for (int i = 0; i < n; ++i) {
      if (D[i] == 2) {
        ok &= r < 1900;
      }
      r += C[i];
    }
    if (ok) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  bool ok = true;
  int r = lo;
  for (int i = 0; i < n; ++i) {
    if (D[i] == 1) {
      ok &= r >= 1900;
    } else {
      ok &= r < 1900;
    }
    r += C[i];
  }

  if (ok) {
    printf("%d\n", r);
  } else {
    puts("Impossible");
  }

  return 0;
}