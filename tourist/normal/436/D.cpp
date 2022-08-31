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

const int inf = (int)1e9;
const int N = 1234567;

int a[N], b[N];
int bfrom[N], bto[N];
int f[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) scanf("%d", b + i);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  int beg = 1;
  while (beg <= n) {
    int end = beg;
    while (end + 1 <= n && a[end + 1] == a[end] + 1) {
      end++;
    }
    for (int j = beg; j <= end; j++) {
      bfrom[j] = beg;
      bto[j] = end;
    }
    beg = end + 1;
  }
  for (int i = 0; i <= n; i++) f[i] = -inf;
  f[0] = 0;
  int j = 0;
  for (int i = 1; i <= n; i++) {
    if (i != bto[i]) {
      continue;
    }
    while (j + 1 <= m && b[j + 1] <= a[i]) {
      j++;
    }
    int mx = f[bfrom[i] - 1];
    for (int k = j; k >= 1; k--) {
      int cnt = a[i] - b[k];
      int pos = i - cnt;
      if (pos < 1) {
        break;
      }
      int cur = f[bfrom[pos] - 1] + (j - k + 1);
      if (cur > mx) {
        mx = cur;
      }
    }
    if (mx > f[i]) {
      f[i] = mx;
    }
    for (int k = j + 1; k <= m; k++) {
      int cnt = b[k] - a[i];
      int pos = i + cnt;
      if (pos > n) {
        break;
      }
      int cur = mx + (k - j);
      if (cur > f[bto[pos]]) {
        f[bto[pos]] = cur;
      }
    }
    if (i < n && f[i] > f[bto[i + 1]]) {
      f[bto[i + 1]] = f[i];
    }
  }
  printf("%d\n", f[n]);
  return 0;
}