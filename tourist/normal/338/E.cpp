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

const int N = 2000010;

int mx[N], add[N], a[N], b[N];

void modify(int x, int l, int r, int ll, int rr, int v) {
  if (l > rr || ll > r) return;
  if (l >= ll && r <= rr) {
    add[x] += v;
    return;
  }
  if (add[x] != 0) {
    add[x + x] += add[x];
    add[x + x + 1] += add[x];
    add[x] = 0;
  }
  int y = (l + r) >> 1;
  modify(x + x, l, y, ll, rr, v);
  modify(x + x + 1, y + 1, r, ll, rr, v);
  mx[x] = mx[x + x + 1] + add[x + x + 1];
  if (mx[x + x] + add[x + x] > mx[x]) mx[x] = mx[x + x] + add[x + x];
}

int main() {
  int n, len, h;
  scanf("%d %d %d", &n, &len, &h);
  for (int i=1;i<=len;i++) scanf("%d", b+i);
  sort(b + 1, b + len + 1);
  reverse(b + 1, b + len + 1);
  for (int i=1;i<=n;i++) {
    int foo;
    scanf("%d", &foo);
    int ll = 0, rr = len;
    while (ll < rr) {
      int mid = (ll + rr + 1) >> 1;
      if (foo + b[mid] >= h) ll = mid;
      else rr = mid - 1;
    }
    a[i] = ll;
  }
  memset(mx, 0, sizeof(mx));
  memset(add, 0, sizeof(add));
  for (int i=1;i<=len;i++) modify(1, 0, len, i, i, -i);
  for (int i=1;i<=len-1;i++) modify(1, 0, len, a[i], len, 1);
  int ans = 0;
  for (int i=len;i<=n;i++) {
    modify(1, 0, len, a[i], len, 1);
    if (mx[1] + add[1] == 0) ans++;
    modify(1, 0, len, a[i - len + 1], len, -1);
  }
  printf("%d\n", ans);
  return 0;
}