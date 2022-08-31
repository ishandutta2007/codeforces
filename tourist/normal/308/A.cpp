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

using namespace std;

long long a[4444444];

int main() {
  int n, l, t;
  scanf("%d %d %d", &n, &l, &t);
  for (int i=0;i<n;i++) {
    int foo;
    scanf("%d", &foo);
    a[i] = foo;
  }
  for (int i=0;i<2*n;i++) a[i+n] = a[i] + l;
  double ans = 1.0 * (t / l) * n * (n-1) / 2.0;
  t %= l;
  int j = 0;
  for (int i=0;i<n;i++) {
    while (a[j] <= a[i] + 2*t) j++;
    int cnt = j - i - 1;
    if (j > i+n) cnt--;
    if (j > i+2*n) cnt--;
    ans += 0.25 * cnt;
  }
  printf("%.17lf\n", ans);
  return 0;
}