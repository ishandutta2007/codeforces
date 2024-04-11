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

char S[128][128];
int A[128], D[128];

int main() {
  int n = in();
  int m = in();
  for (int i = 0; i < n; ++i) {
    scanf("%s", S[i]);
  }

  int res = 0;
  memset(A, 0, sizeof(A));
  for (int j = m - 1; j >= 0; --j) {
    for (int i = 0; i < n; ++i) {
      D[i] = S[i][j] == 'B' ? -1 : 1;
      D[i] -= A[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      if (D[i] != 0) {
        ++res;
        int w = D[i];
        for (int k = i; k >= 0; --k) {
          A[k] += w;
          D[k] -= w;
        }
      }
    }
  }

  printf("%d\n", res);

  return 0;
}