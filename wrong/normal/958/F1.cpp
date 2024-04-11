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
  int m = in();
  vector<int> a(n), k(m);
  for (int i = 0; i < n; ++i) {
    a[i] = in() - 1;
  }
  int s = 0;
  for (int i = 0; i < m; ++i) {
    k[i] = in();
    s += k[i];
  }

  for (int i = 0; i + s <= n; ++i) {
    vector<int> v(m, 0);
    for (int j = i; j < i + s; ++j) {
      ++v[a[j]];
    }
    if (v == k) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");

  return 0;
}