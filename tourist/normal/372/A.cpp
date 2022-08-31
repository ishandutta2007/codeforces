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

int a[500010];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int ll = 0, rr = n / 2;
  while (ll < rr) {
    int mid = (ll + rr + 1) >> 1;
    bool ok = true;
    for (int i = 0; i < mid; i++)
      if (2 * a[i] > a[n - mid + i]) {
        ok = false;
        break;
      }
    if (ok) ll = mid;
    else rr = mid - 1;
  }
  printf("%d\n", n - ll);
  return 0;
}