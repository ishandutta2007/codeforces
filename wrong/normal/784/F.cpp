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
#include <ctime>

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
  clock_t start = clock();

  int n;
  cin >> n;

  int s[100];
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j > i; --j) {
      if (s[j] < s[j - 1]) {
        int t = s[j];
        s[j] = s[j - 1];
        s[j - 1] = t;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << s[i] << " ";
  }

  while ((clock() - start) / CLOCKS_PER_SEC < 1.5) {

  }

  return 0;
}