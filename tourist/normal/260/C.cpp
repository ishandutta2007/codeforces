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

using namespace std;

long long a[555555];

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  long long n, x, i, j;
  scanf("%I64d %I64d", &n, &x);
  for (i=1;i<=n;i++) scanf("%I64d", a+i);
  long long tot = 0;
  for (i=1;i<=n;i++) tot += a[i];
  long long mn = 2000000000, km = 0;
  for (j=0;j<n;j++) {
    if (a[x] < mn) mn = a[x], km = x;
    x--;
    if (x == 0) x = n;
  }
  long long flag = 0;
  for (j=0;j<n;j++) {
    a[x] -= mn;
    if (x == km) flag = 1;
    if (!flag) a[x]--;
    x--;
    if (x == 0) x = n;
  }
  for (i=1;i<=n;i++) tot -= a[i];
  a[km] += tot;
  for (i=1;i<n;i++) printf("%I64d ", a[i]);
  printf("%I64d\n", a[n]);
  return 0;
}