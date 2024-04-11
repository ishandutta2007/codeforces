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

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }

int main()
{
  int N, X = 0;
  N = in();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int t = in();
      if (i == j) {
        X ^= t;
      }
    }
  }

  int Q = in();
  for (int i = 0; i < Q; ++i) {
    if (in() == 3) {
      putchar('0' + X);
    } else {
      in();
      X ^= 1;
    }
  }
  puts("");

  return 0;
}