#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const long long inf = (long long)4e18;

const int N = 12345;
const int T = (1 << 21);

int x[N], k[N], mask[N];
long long f[T];

int main() {
  int n, m, b;
  scanf("%d %d %d", &n, &m, &b);
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d %d %d", x + i, k + i, &foo);
    mask[i] = 0;
    while (foo--) {
      int bar;
      scanf("%d", &bar);
      mask[i] |= (1 << (bar - 1));
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (k[i] > k[j]) {
        swap(x[i], x[j]);
        swap(k[i], k[j]);
        swap(mask[i], mask[j]);
      }
  for (int i = 0; i < (1 << m); i++) f[i] = inf;
  f[0] = 0;
  long long ans = inf;
  for (int i = 0; i < n; i++) {
    for (int t = 0; t < (1 << m); t++)
      if (f[t] + x[i] < f[t | mask[i]]) {
        f[t | mask[i]] = f[t] + x[i];
      }
    long long cur = f[(1 << m) - 1];
    cur += 1LL * k[i] * b;
    if (cur < ans) ans = cur;
  }
  cout << (ans == inf ? -1 : ans) << endl;
  return 0;
}