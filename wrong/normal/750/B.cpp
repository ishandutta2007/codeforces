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

int main() {
  int n = in();

  int cur = 20000;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    int t = in();
    char dir[10];
    scanf("%s", dir);
    if (dir[0] == 'N') {
      ok &= cur + t <= 20000;
      cur += t;
    } else if (dir[0] == 'S') {
      ok &= cur - t >= 0;
      cur -= t;
    } else {
      ok &= cur != 20000 && cur != 0;
    }
    if (!ok) {
      break;
    }
  }

  puts((ok && cur == 20000) ? "YES" : "NO");

  return 0;
}