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

char S[64][64];

int main() {
  int n = in();
  int m = in();

  for (int i = 0; i < n; ++i) {
    scanf("%s", S[i]);
  }

  int res = 0;
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) {
      int cnt[256] = {};
      for (int di = 0; di <= 1; ++di) {
        for (int dj = 0; dj <= 1; ++dj) {
          ++cnt[(int)S[i + di][j + dj]];
        }
      }
      if (cnt['f'] && cnt['a'] && cnt['c'] && cnt['e']) {
        ++res;
      }
    }
  }

  printf("%d\n", res);

  return 0;
}