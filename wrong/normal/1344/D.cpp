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

int N;
Int K, A[100050], MB[100050], B[100050];

Int dif(Int a, Int b) { // b -> b+1
  return a - 3 * b * b - 3 * b - 1;
}

Int ldif(Int a, Int b) { // b -> b-1
  return -dif(a, b - 1);
}

Int more_use(Int a, Int mb, Int dmin) { // >= dmin
  if (mb == a) return 0;
  Int lo = 0, hi = a - mb + 1;
  while (hi - lo > 1) {
    Int md = (hi + lo) / 2;
    if (dif(a, mb + md - 1) >= dmin) {
      lo = md;
    } else {
      hi = md;
    }
  }
  return lo;
}

Int less_use(Int a, Int mb, Int dmin) { // >= dmin
  if (mb == 0) return 0;
  Int lo = 0, hi = mb + 1;
  while (hi - lo > 1) {
    Int md = (hi + lo) / 2;
    if (ldif(a, mb - md + 1) >= dmin) {
      lo = md;
    } else {
      hi = md;
    }
  }
  return lo;
}

void les(Int exc) {
  Int maxdif = -INFLL;
  for (int i = 0; i < N; ++i) {
    if (MB[i] > 0) {
      chmax(maxdif, ldif(A[i], MB[i]));
    }
  }

  Int hi = maxdif + 1, lo = -INF;
  while (hi - lo > 1) {
    Int md = (hi + lo) / 2;
    Int canuse = 0;
    for (int i = 0; i < N; ++i) {
      canuse += less_use(A[i], MB[i], md);
    }
    if (exc <= canuse) {
      lo = md;
    } else {
      hi = md;
    }
  }

  for (int i = 0; i < N; ++i) {
    const Int u = less_use(A[i], MB[i], lo + 1);
    B[i] = MB[i] - u;
    exc -= u;
  }
  for (int i = 0; i < N; ++i) {
    if (B[i] > 0 && exc > 0 && ldif(A[i], B[i]) == lo) {
      --B[i];
      --exc;
    }
  }
}

void mor(Int exc) {
  Int maxdif = -INFLL;
  for (int i = 0; i < N; ++i) {
    if (MB[i] < A[i]) {
      chmax(maxdif, dif(A[i], MB[i]));
    }
  }

  Int hi = maxdif + 1, lo = -4 * INFLL;
  while (hi - lo > 1) {
    Int md = (hi + lo) / 2;
    Int canuse = 0;
    for (int i = 0; i < N; ++i) {
      canuse += more_use(A[i], MB[i], md);
    }
    if (exc <= canuse) {
      lo = md;
    } else {
      hi = md;
    }
  }
  
  for (int i = 0; i < N; ++i) {
    const Int u = more_use(A[i], MB[i], lo + 1);
    B[i] = MB[i] + u;
    exc -= u;
  }
  for (int i = 0; i < N; ++i) {
    if (B[i] < A[i] && exc > 0 && dif(A[i], B[i]) == lo) {
      ++B[i];
      --exc;
    }
  }
}

int main() {
  N = in();
  K = lin();
  for (int i = 0; i < N; ++i) {
    A[i] = lin();
    MB[i] = (Int)sqrt(A[i] / 3.0);
  }

  Int used = 0;
  for (int i = 0; i < N; ++i) {
    used += MB[i];
  }
  if (used < K) {
    mor(K - used);
  } else if (used > K) {
    les(used - K);
  } else {
    memcpy(B, MB, sizeof(B));
  }

  for (int i = 0; i < N; ++i) {
    printf("%lld%c", B[i], i==N-1 ? '\n' : ' ');
  }

  return 0;
}