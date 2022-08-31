#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

const int N = 310;

long double c[N][N];
long double fact[1234567];

int main() {
  for (int i = 0; i < N; i++) {
    c[i][0] = c[i][i] = 1.0;
    for (int j = 1; j < i; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    for (int j = i + 1; j < N; j++) {
      c[i][j] = 0.0;
    }
  }
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  fact[0] = 0.0;
  for (int i = 1; i <= m; i++) {
    fact[i] = fact[i - 1] + log(i);
  }
  long double ans = 0.0;
  for (int x = n; x >= 0; x--) {
    for (int y = n; y >= 0; y--) {
      int cnt = n * (x + y) - x * y;
      if (cnt <= k) {
        ans += expl((fact[k] - fact[k - cnt]) - (fact[m] - fact[m - cnt])) * c[n][x] * c[n][y];
      }
    }
  }
  if (ans > 1e99) {
    ans = 1e99;
  }
  printf("%.15le\n", (double)ans);
  return 0;
}