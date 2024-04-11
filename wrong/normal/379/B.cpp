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

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

char O[1<<20];

int main()
{
  int n, a[333];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  memset(O, 0, sizeof(O));
  int p = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < a[i]; ++j) {
      O[p++] = 'P';
      if (i + 1 < n) {
        O[p++] = 'R';
        O[p++] = 'L';
      } else {
        O[p++] = 'L';
        O[p++] = 'R';
      }
    }
    if (i + 1 < n) {
      O[p++] = 'R';
    }
  }

  puts(O);

  return 0;
}