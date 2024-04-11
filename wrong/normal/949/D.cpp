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

int N, D, B;
int A[100050], OA[100050], L[100050], R[100050], come[100050];

int solve(int N, int sz) {
  int nxt_room = 0, cnt = 0;
  for (int lef = 0; lef < N; ) {
    int cur = 0, rig = lef;
    while (rig < N && cur < B) {
      int b = min(B - cur, A[rig]);
      A[rig] -= b;
      cur += b;
      ++rig;
    }
    const int fil = max(L[rig - 1], nxt_room);
    nxt_room = fil + 1;
    if (fil >= sz) {
      break;
    }
    ++cnt;
    lef = rig - 1;
  }
  return cnt;
}

int main() {
  N = in();
  D = in();
  B = in();
  for (int i = 0; i < N; ++i) {
    OA[i] = A[i] = in();
    come[i] = min(i + 1, N - i);
  }

  for (int i = 0; i < N; ++i) {
    int lo = i, hi = N;
    while (hi - lo > 1) {
      const int mid = (hi + lo) / 2;
      const int step = (mid - i + D - 1) / D;
      if (step <= come[mid]) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    R[i] = lo;
    lo = -1; hi = i;
    while (hi - lo > 1) {
      const int mid = (hi + lo) / 2;
      const int step = (i - mid + D - 1) / D;
      if (step <= come[mid]) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    L[i] = hi;
  }

  const int szL = (N + 1) / 2;
  const int szR = N - szL;
  const int resL = solve(N, szL);

  memcpy(A, OA, sizeof(A));
  reverse(A, A + N);
  reverse(L, L + N);
  reverse(R, R + N);
  for (int i = 0; i < N; ++i) {
    L[i] = N - L[i] - 1;
    R[i] = N - R[i] - 1;
    swap(L[i], R[i]);
  }
  const int resR = solve(N, szR);

  const int res = max(szL - resL, szR - resR);
  printf("%d\n", res);

  return 0;
}