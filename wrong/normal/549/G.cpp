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

int A[200050];

int main() {
  int N = in();
  for (int i = 0; i < N; ++i) {
    A[i] = in() + i;
  }
  sort(A, A + N);

  bool ok = true;
  for (int i = 0; i < N; ++i) {
    ok &= A[i] - i >= 0;
    if (i > 0) {
      ok &= A[i] > A[i - 1];
    }
  }
  if (!ok) {
    puts(":(");
    return 0;
  }

  for (int i = 0; i < N; ++i) {
    printf("%d%c", A[i] - i, i == N - 1 ? '\n' : ' ');
  }

  return 0;
}