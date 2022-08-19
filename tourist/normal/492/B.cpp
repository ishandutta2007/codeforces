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

int a[1234567];

int main() {
  int n, len;
  scanf("%d %d", &n, &len);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  double ans = max(a[0], len - a[n - 1]);
  for (int i = 0; i < n - 1; i++) {
    double cur = 0.5 * (a[i + 1] - a[i]);
    if (cur > ans) {
      ans = cur;
    }
  }
  printf("%.17lf\n", ans);
  return 0;
}