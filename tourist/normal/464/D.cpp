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

const int MAGIC = 2000;

long double f[MAGIC + 10], inv[MAGIC + 10];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int j = 1; j < MAGIC; j++) {
    f[j] = 0.0;
    inv[j] = 1.0 / j;
  }
  f[1] = 1.0;
  long double q = 1.0 / k;
  long double ans = 0.0;
  for (int it = 0; it < n; it++) {
    for (int j = MAGIC - 1; j >= 1; j--) {
      if (f[j] < 1e-100) {
        f[j] = 0.0;
        continue;
      }
      ans += f[j] * j * (0.5 + inv[j + 1]);
      long double u = f[j] * q * inv[j + 1];
      f[j + 1] += u;
      f[j] -= u;
    }
  }
  printf("%.17lf\n", (double)ans);
  return 0;
}