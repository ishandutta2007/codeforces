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

int main() {
  int n;
  char s[128];

  n = in();
  scanf("%s", s);

  bool res = false;
  for (int d = 1; d <= n; ++d) {
    for (int i = 0; i < n; ++i) {
      if (i + 4 * d < n && s[i] == '*') {
        bool ok = true;
        for (int j = 1; j <= 4; ++j) {
          ok &= s[i + d * j] == '*';
        }
        res |= ok;
      }
    }
  }

  puts(res ? "yes" : "no");

  return 0;
}