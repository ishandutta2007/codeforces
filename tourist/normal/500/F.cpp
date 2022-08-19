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

const int MAX = 4010;

int c[MAX], h[MAX], t[MAX];
pair <int, int> e[MAX];
int nc[MAX], nh[MAX], nt[MAX];
int f[MAX];
int l_to_r[MAX][MAX];
int r_to_l[MAX][MAX];

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", c + i, h + i, t + i);
    e[i] = make_pair(t[i], i);
  }
  sort(e, e + n);
  for (int i = 0; i < n; i++) {
    int id = e[i].second;
    nc[i] = c[id];
    nh[i] = h[id];
    nt[i] = t[id];
  }
  for (int i = 0; i < n; i++) {
    c[i] = nc[i];
    h[i] = nh[i];
    t[i] = nt[i];
  }
  int beg = 0;
  while (beg < n) {
    int end = beg;
    while (end + 1 < n && t[end + 1] / p == t[beg] / p) {
      end++;
    }
    {
      for (int j = 0; j < MAX; j++) {
        f[j] = 0;
      }
      for (int id = beg; id <= end; id++) {
        for (int j = MAX - 1 - c[id]; j >= 0; j--) {
          if (f[j] + h[id] > f[j + c[id]]) {
            f[j + c[id]] = f[j] + h[id];
          }
        }
        for (int j = 0; j < MAX; j++) {
          l_to_r[id][j] = f[j];
        }
      }
    }
    {
      for (int j = 0; j < MAX; j++) {
        f[j] = 0;
      }
      for (int id = end; id >= beg; id--) {
        for (int j = MAX - 1 - c[id]; j >= 0; j--) {
          if (f[j] + h[id] > f[j + c[id]]) {
            f[j + c[id]] = f[j] + h[id];
          }
        }
        for (int j = 0; j < MAX; j++) {
          r_to_l[id][j] = f[j];
        }
      }
    }
    beg = end + 1;
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
      if (t[i] <= foo && foo <= t[i] + p - 1) {
        if (first == -1) {
          first = i;
        }
        last = i;
      }
    }
    if (first == -1) {
      printf("%d\n", 0);
      continue;
    }
    if (t[first] / p == foo / p) {
      printf("%d\n", l_to_r[last][bar]);
      continue;
    }
    if (t[last] / p == foo / p - 1) {
      printf("%d\n", r_to_l[first][bar]);
      continue;
    }
    int ans = 0;
    for (int part = 0; part <= bar; part++) {
      int cur = l_to_r[last][part] + r_to_l[first][bar - part];
      if (cur > ans) {
        ans = cur;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}