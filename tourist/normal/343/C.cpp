#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

inline bool can_visit(long long s, long long a, long long b, long long t) {
  if (a > s) a = s;
  if (b < s) b = s;
  long long x = s - a;
  long long y = b - s;
  long long z;
  if (x < y) z = 2 * x + y;
  else z = x + 2 * y;
  return (z <= t);
}

long long h[1234567], p[1234567];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%I64d", h + i);
  for (int i = 0; i < m; i++) scanf("%I64d", p + i);
  long long ll = 0, rr = (long long)1e11;
  while (ll < rr) {
    long long mid = (ll + rr) >> 1;
    int last = 0;
    for (int i = 0; i < n; i++) {
      int low = last, high = m;
      while (low < high) {
        int center = (low + high + 1) >> 1;
        if (can_visit(h[i], p[last], p[center - 1], mid)) low = center;
        else high = center - 1;
      }
      last = low;
    }
    if (last == m) rr = mid;
    else ll = mid + 1;
  }
  cout << ll << endl;
  return 0;
}