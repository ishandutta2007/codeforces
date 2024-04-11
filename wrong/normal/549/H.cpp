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

pair<double, double> range(double a, double b, double m) {
  double as[2] = {a - m, a + m}, bs[2] = {b - m, b + m};
  double f[4];
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      f[i * 2 + j] = as[i] * bs[j];
    }
  }
  sort(f, f + 4);
  return make_pair(f[0], f[3]);
}

int main() {
  double a = fin();
  double b = fin();
  double c = fin();
  double d = fin();

  double lo = 0.0, hi = 1e9;
  for (int loop = 0; loop < 64; ++loop) {
    double mid = (hi + lo) / 2;
    auto ad = range(a, d, mid);
    auto bc = range(b, c, mid);
    if (ad.second < bc.first || bc.second < ad.first) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  printf("%.9f\n", hi);
  
  return 0;
}