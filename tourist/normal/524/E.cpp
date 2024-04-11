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

const int inf = (int)1e9;
const int N = 800010;

int mx[N];

void build(int x, int l, int r) {
  mx[x] = 0;
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
  }
}

void modify(int x, int l, int r, int p, int v) {
  if (l == r) {
    mx[x] = v;
    return;
  }
  int y = (l + r) >> 1;
  if (p <= y) {
    modify(x + x, l, y, p, v);
  } else {
    modify(x + x + 1, y + 1, r, p, v);
  }
  mx[x] = min(mx[x + x], mx[x + x + 1]);
}

int find_min(int x, int l, int r, int ll, int rr) {
  if (r < ll || rr < l) return inf;
  if (ll <= l && r <= rr) {
    return mx[x];
  }
  int y = (l + r) >> 1;
  int res = find_min(x + x, l, y, ll, rr);
  int other = find_min(x + x + 1, y + 1, r, ll, rr);
  if (other < res) res = other;
  return res;
}

int rx[N], ry[N];
int xa[N], ya[N], xb[N], yb[N];
vector <int> ev[N];
int ans[N];

int main() {
  int h, w, rooks, tt;
  scanf("%d %d %d %d", &h, &w, &rooks, &tt);
  for (int i = 0; i < rooks; i++) {
    scanf("%d %d", rx + i, ry + i);
  }
  for (int i = 0; i < tt; i++) {
    scanf("%d %d %d %d", xa + i, ya + i, xb + i, yb + i);
    ans[i] = 0;
  }
  for (int rot = 0; rot < 2; rot++) {
    for (int i = 1; i <= h; i++) {
      ev[i].clear();
    }
    for (int i = 0; i < rooks; i++) {
      ev[rx[i]].push_back(ry[i]);
    }
    for (int i = 0; i < tt; i++) {
      ev[xb[i]].push_back(~i);
    }
    build(1, 1, w);
    for (int i = 1; i <= h; i++) {
      int sz = ev[i].size();
      for (int j = 0; j < sz; j++) {
        int u = ev[i][j];
        if (u >= 0) {
          modify(1, 1, w, u, i);
        } else {
          u = ~u;
          if (find_min(1, 1, w, ya[u], yb[u]) >= xa[u]) {
            ans[u] = 1;
          }
        }
      }
    }
    swap(h, w);
    for (int i = 0; i < rooks; i++) {
      swap(rx[i], ry[i]);
    }
    for (int i = 0; i < tt; i++) {
      swap(xa[i], ya[i]);
      swap(xb[i], yb[i]);
    }
  }
  for (int i = 0; i < tt; i++) {
    puts(ans[i] ? "YES" : "NO");
  }
  return 0;
}