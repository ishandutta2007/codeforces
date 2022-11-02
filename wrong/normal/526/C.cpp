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

Int gcd(Int m, Int n) {
  return n == 0 ? m : gcd(n, m % n);
}

int main() {
  Int C = in();
  Int Hr = in();
  Int Hb = in();
  Int Wr = in();
  Int Wb = in();

  Int L = Wr * Wb / gcd(Wr, Wb);

  if (Wr < Wb) {
    swap(Wr, Wb);
    swap(Hr, Hb);
  }

  Int res = 0;
  if (Wr >= 1000) {
    for (Int i = 0; Wr * i <= C; ++i) {
      chmax(res, Hr * i + (C - Wr * i) / Wb * Hb);
    }
  } else {
    if (Hr * Wb > Hb * Wr) {
      swap(Wr, Wb);
      swap(Hr, Hb);
    }
    for (Int i = 0; Wr * i <= min(C, L); ++i) {
      chmax(res, Hr * i + (C - Wr * i) / Wb * Hb);
    }
  }

  cout << res << endl;

  return 0;
}