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

const Int MO = 1000000007;

vector<Int> prs;
int pr[1<<20];
void er() {
  for (int i = 2; i < (1<<20); ++i) {
    pr[i] = 1;
  }
  for (int i = 2; i < (1<<20); ++i) {
    if (pr[i]) {
      for (int j = i + i; j < (1<<20); j += i) {
        pr[j] = 0;
      }
    }
  }
  for (int i = 2; i < (1<<20); ++i) {
    if (pr[i]) {
      prs.push_back(i);
    }
  }
}

Int totient(Int n) {
  Int v = n;
  for (int i = 0; prs[i] * prs[i] <= n; ++i) {
    if (n % prs[i] == 0) {
      v -= v / prs[i];
      while (n % prs[i] == 0) {
        n /= prs[i];
      }
    }
  }
  if (n > 1) {
    v -= v / n;
  }
  return v;
}

int main() {
  er();

  Int n = lin();
  Int k = lin();

  for (Int i = 0; i < (k + 1) / 2; ++i) {
    n = totient(n);
    if (n == 1) {
      break;
    }
  }

  printf("%lld\n", n % MO);

  return 0;
}