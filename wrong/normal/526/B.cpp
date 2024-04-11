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

int A[100050], M[100050];

int main() {
  int N = in();
  for (int i = 2; i < 1 << (N + 1); ++i) {
    A[i] = in();
  }

  int res = 0;
  for (int i = (1 << N) - 1; i >= 1; --i) {
    int lef = M[2 * i] + A[2 * i];
    int rig = M[2 * i + 1] + A[2 * i + 1];
    res += max(lef, rig) - min(lef, rig);
    M[i] = max(lef, rig);
  }

  printf("%d\n", res);

  return 0;
}