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

const int N = 444444;

pair <int, int> a[N];
int b[N], ans[N];
int n, h, i, k;

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  scanf("%d %d", &n, &h);
  for (i=0;i<n;i++) {
    int foo;
    scanf("%d", &foo);
    a[i] = make_pair(foo, i+1);
  }
  sort(a, a+n);
  for (i=0;i<n;i++) b[i] = a[i].first;
  int diff = (b[n-1]+b[n-2]) - (b[0]+b[1]);
  int km = 0;
  for (k=1;k<n;k++) {
    int other;

    int small = (int)1e9;
    if (k >= 2) {
      other = b[1]+b[2];
      if (other < small) small = other;
    }
    other = b[0]+b[1]+h;
    if (other < small) small = other;
    if (k < n-1) {
      other = b[0]+b[k+1];
      if (other < small) small = other;
    }

    int big = b[n-1]+h;
    if (k == n-1) big += b[0];
    else big += b[k];
    other = b[n-1]+b[n-2];
    if (other > big) big = other;

    if (big-small < diff) {
      diff = big-small;
      km = k;
    }
  }
  printf("%d\n", diff);
  for (i=1;i<=n;i++) ans[i] = 1;
  for (i=1;i<=km;i++) ans[a[i].second] = 2;
  for (i=1;i<n;i++) printf("%d ", ans[i]);
  printf("%d\n", ans[n]);
  return 0;
}