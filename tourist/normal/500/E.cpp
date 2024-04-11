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

const int N = 800010;

int mx[N], rg[N];

void build(int x, int l, int r) {
  if (l == r) {
    mx[x] = l;
  } else {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
    mx[x] = (rg[mx[x + x]] > rg[mx[x + x + 1]] ? mx[x + x] : mx[x + x + 1]);
  }
}

int find_max(int x, int l, int r, int ll, int rr) {
  if (rr < l || r < ll) {
    return -1;
  }
  if (ll <= l && r <= rr) {
    return mx[x];
  }
  int y = (l + r) >> 1;
  int a = find_max(x + x, l, y, ll, rr);
  int b = find_max(x + x + 1, y + 1, r, ll, rr);
  if (a == -1) return b;
  if (b == -1) return a;
  return (rg[a] > rg[b] ? a : b);
}

int x[N], len[N];
int nx[N], cost[N];

const int LOG = 20;

int to[N][LOG], pay[N][LOG];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, len + i);
    rg[i] = x[i] + len[i];
  }
  build(1, 0, n - 1);
  for (int i = 0; i < n - 1; i++) {
    int to = lower_bound(x, x + n, x[i] + len[i] + 1) - x - 1;
    if (to == i) {
      nx[i] = i + 1;
      cost[i] = x[i + 1] - x[i] - len[i];
    } else {
      nx[i] = find_max(1, 0, n - 1, i + 1, to);
      cost[i] = 0;
      if (rg[nx[i]] < rg[i] && to < n - 1) {
        nx[i] = to + 1;
        cost[i] = x[nx[i]] - x[i] - len[i];
      }
    }
  }
  nx[n - 1] = n - 1;
  cost[n - 1] = 0;
  for (int i = 0; i < n; i++) {
    to[i][0] = nx[i];
    pay[i][0] = cost[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i < n; i++) {
      to[i][j] = to[to[i][j - 1]][j - 1];
      pay[i][j] = pay[to[i][j - 1]][j - 1] + pay[i][j - 1];
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int st, fin;
    scanf("%d %d", &st, &fin);
    st--; fin--;
    int ans = 0;
    for (int j = LOG - 1; j >= 0; j--) {
      if (to[st][j] < fin) {
        ans += pay[st][j];
        st = to[st][j];
      }
    }
    if (x[fin] > rg[st]) {
      ans += pay[st][0];
    }
    printf("%d\n", ans);
  }
  return 0;
}