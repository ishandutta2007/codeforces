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

int O[1<<20];

int main()
{
  int n = in();
  for (int i = 0; i < n; ++i) {
    O[in() - 1] = 1;
  }

  vector<int> res, fr;
  for (int i = 0; i < 500000; ++i) {
    int o = 999999 - i;
    if (O[i] && !O[o]) {
      O[o] = 2;
      res.push_back(o + 1);
    } else if (!O[i] && O[o]) {
      O[i] = 2;
      res.push_back(i + 1);
    } else if (!O[i] && !O[o]) {
      fr.push_back(i);
    }
  }

  for (int i = 0; i < 500000; ++i) {
    int o = 999999 - i;
    if (O[i] == 1 && O[o] == 1) {
      res.push_back(fr.back() + 1);
      res.push_back(999999 - fr.back() + 1);
      fr.pop_back();
    }
  }

  printf("%d\n", (int)res.size());
  for (int i = 0; i < res.size(); ++i) {
    printf("%d%c", res[i], i+1 == res.size() ? '\n' : ' ');
  }

  return 0;
}