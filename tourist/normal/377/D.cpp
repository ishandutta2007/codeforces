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

const int co = 300000;
const int TREE = 10 * co + 10;

int max[TREE], add[TREE], index[TREE];

void build(int x, int l, int r) {
  max[x] = add[x] = 0;
  index[x] = l;
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
  }
}

void modify(int x, int l, int r, int ll, int rr, int v) {
  if (r < ll || rr < l) return;
  if (l >= ll && r <= rr) {
    add[x] += v;
    return;
  }
  int y = (l + r) >> 1;
  modify(x + x, l, y, ll, rr, v);
  modify(x + x + 1, y + 1, r, ll, rr, v);
  int wl = max[x + x] + add[x + x];
  int wr = max[x + x + 1] + add[x + x + 1];
  if (wl > wr) {
    max[x] = wl;
    index[x] = index[x + x];
  } else {
    max[x] = wr;
    index[x] = index[x + x + 1];
  }
}

const int N = 100010;

int low[N], v[N], high[N];
int r[N];

std::vector <int> left[co + 10], skill[co + 10];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d %d %d", low + i, v + i, high + i);
  for (int i = 1; i <= co; i++) {
    left[i].clear();
    skill[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    left[low[i]].push_back(i);
    skill[v[i]].push_back(i);
  }
  build(1, 1, co);
  int ans = 0, a_from = 0, a_to = 0;
  for (int from = 1; from <= co; from++) {
    {
      int sz = left[from].size();
      for (int j = 0; j < sz; j++) {
        int id = left[from][j];
        modify(1, 1, co, v[id], high[id], 1);
      }
    }
    int cur = max[1] + add[1];
    if (cur > ans) {
      ans = cur;
      a_from = from;
      a_to = index[1];
    }
    {
      int sz = skill[from].size();
      for (int j = 0; j < sz; j++) {
        int id = skill[from][j];
        modify(1, 1, co, v[id], high[id], -1);
      }
    }
  }
  int kr = 0;
  for (int i = 1; i <= n; i++)
    if (low[i] <= a_from && a_from <= v[i] && v[i] <= a_to && a_to <= high[i]) {
      r[++kr] = i;
    }
  printf("%d\n", kr);
  for (int i = 1; i < kr; i++) printf("%d ", r[i]);
  printf("%d\n", r[kr]);
  return 0;
}