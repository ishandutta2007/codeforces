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

const int N = 888888;

int mn[N], add[N], cnt[N];
int ry[N];

void build(int x, int l, int r) {
  mn[x] = 0;
  add[x] = 0;
  cnt[x] = ry[r] - ry[l - 1];
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
  }
}

void modify(int x, int l, int r, int ll, int rr, int v) {
  if (ll <= l && r <= rr) {
    add[x] += v;
    return;
  }
  if (add[x] != 0) {
    add[x + x] += add[x];
    add[x + x + 1] += add[x];
    add[x] = 0;
  }
  int y = (l + r) >> 1;
  if (ll <= y) {
    modify(x + x, l, y, ll, rr, v);
  }
  if (rr > y) {
    modify(x + x + 1, y + 1, r, ll, rr, v);
  }
  int w1 = mn[x + x] + add[x + x];
  int w2 = mn[x + x + 1] + add[x + x + 1];
  mn[x] = (w1 < w2 ? w1 : w2);
  cnt[x] = (w1 == mn[x] ? cnt[x + x] : 0) + (w2 == mn[x] ? cnt[x + x + 1] : 0);
}

int xa[N], ya[N], xb[N], yb[N];
int rya[N], ryb[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d %d", xa + i, ya + i, xb + i, yb + i);
  }
  int step = 1;
  while (step <= k) {
    vector < pair <int, int> > ys;
    for (int i = 0; i < m; i++) {
      if (xa[i] > xb[i] || ya[i] > yb[i]) {
        continue;
      }
      ys.push_back(make_pair(ya[i] - 1, i));
      ys.push_back(make_pair(yb[i], ~i));
    }
    if (ys.empty()) {
      break;
    }
    sort(ys.begin(), ys.end());
    int t = 0;
    ry[0] = ys[0].first;
    int yss = ys.size();
    for (int i = 0; i < yss; i++) {
      if (i > 0 && ys[i].first != ys[i - 1].first) {
        t++;
        ry[t] = ys[i].first;
      }
      if (ys[i].second >= 0) {
        rya[ys[i].second] = t + 1;
      } else {
        ryb[~ys[i].second] = t;
      }
    }
    if (t == 0) {
      break;
    }
    build(1, 1, t);
    vector < pair <int, int> > e;
    for (int i = 0; i < m; i++) {
      if (xa[i] > xb[i] || ya[i] > yb[i]) {
        continue;
      }
      e.push_back(make_pair(xa[i] - 1, i));
      e.push_back(make_pair(xb[i], ~i));
    }
    sort(e.begin(), e.end());
    int es = e.size();
    int ans = 0;
    for (int id = 0; id < es - 1; id++) {
      int i = e[id].second;
      if (i >= 0) {
        modify(1, 1, t, rya[i], ryb[i], 1);
      } else {
        modify(1, 1, t, rya[~i], ryb[~i], -1);
      }
      int dx = e[id + 1].first - e[id].first;
      int mul = ry[t] - ry[0];
      if (mn[1] + add[1] == 0) {
        mul -= cnt[1];
      }
      ans ^= ((dx & 1) * (mul & 1));
    }
    if (ans == 1) {
      puts("Hamed");
      return 0;
    }
    for (int i = 0; i < m; i++) {
      xa[i] = ((xa[i] + 1) >> 1);
      ya[i] = ((ya[i] + 1) >> 1);
      xb[i] = (xb[i] >> 1);
      yb[i] = (yb[i] >> 1);
    }
    n >>= 1;
    step <<= 1;
  }
  puts("Malek");
  return 0;
}