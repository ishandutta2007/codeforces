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

inline int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a > b) a %= b;
    else b %= a;
  }
  return a + b;
}

const int N = 800010;

int a[N], t[N];

void build(int x, int l, int r) {
  if (l == r) {
    t[x] = a[l];
  } else {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
    t[x] = gcd(t[x + x], t[x + x + 1]);
  }
}

int get(int x, int l, int r, int ll, int rr) {
  if (r < ll || rr < l) {
    return 0;
  }
  if (ll <= l && r <= rr) {
    return t[x];
  }
  int y = (l + r) >> 1;
  int u = get(x + x, l, y, ll, rr);
  int v = get(x + x + 1, y + 1, r, ll, rr);
  return gcd(u, v);
}

pair <int, int> b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    b[i] = make_pair(a[i], i);
  }
  sort(b + 1, b + n + 1);
  build(1, 1, n);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int low, high;
    scanf("%d %d", &low, &high);
    int u = get(1, 1, n, low, high);
    pair <int, int> p = make_pair(u, low);
    int from = (lower_bound(b + 1, b + n + 1, p) - (b + 1));
    p = make_pair(u, high + 1);
    int to = (lower_bound(b + 1, b + n + 1, p) - (b + 1));
    printf("%d\n", (high - low + 1) - (to - from));
  }
  return 0;
}