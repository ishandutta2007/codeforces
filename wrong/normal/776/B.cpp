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

int pr[100050];
void er() {
  for (int i = 2; i <= 100000; ++i) {
    pr[i] = 1;
  }
  for (int i = 2; i <= 100000; ++i) {
    if (pr[i]) {
      for (int j = i+i; j <= 100000; j += i) {
        pr[j] = 0;
      }
    }
  }
}

int main() {
  int n = in();

  if (n <= 2) {
    puts("1");
    for (int i = 0; i < n; ++i) {
      printf("1%c", i+1==n ? '\n' : ' ');
    }
    return 0;
  }

  er();
  puts("2");
  for (int i = 0; i < n; ++i) {
    printf("%d%c", pr[i + 2] ? 1 : 2, i+1 == n ? '\n' : ' ');
  }

  return 0;
}