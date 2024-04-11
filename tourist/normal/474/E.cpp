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

const int N = 400010;

int n;
int ma[N], pa[N];
int ml[N], pl[N];
int mr[N], pr[N];

void modify(int q, int v, int p) {
  if (v > ma[q]) {
    ma[q] = v;
    pa[q] = p;
  }
  int x = q;
  while (x <= n) {
    if (v > ml[x]) {
      ml[x] = v;
      pl[x] = p;
    }
    x = (x | (x - 1)) + 1;
  }
  x = q;
  while (x > 0) {
    if (v > mr[x]) {
      mr[x] = v;
      pr[x] = p;
    }
    x &= x - 1;
  }
}

int find_max(int ll, int rr, int &pos) {
  int mx = -1;
  pos = -1;
  int x = ll;
  while ((x | (x - 1)) + 1 <= rr) {
    if (mr[x] > mx) {
      mx = mr[x];
      pos = pr[x];
    }
    x = (x | (x - 1)) + 1;
  }
  if (ma[x] > mx) {
    mx = ma[x];
    pos = pa[x];
  }
  x = rr;
  while ((x & (x - 1)) >= ll) {
    if (ml[x] > mx) {
      mx = ml[x];
      pos = pl[x];
    }
    x &= x - 1;
  }
  return mx;
}

long long h[N];
pair <long long, int> a[N];
int pz[N];
int f[N], fp[N];

int main() {
  int d;
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", h + i);
    a[i] = make_pair(h[i], i);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    pz[a[i].second] = i;
  }
  for (int i = 1; i <= n; i++) {
    ma[i] = 0; pa[i] = 0;
    ml[i] = 0; pl[i] = 0;
    mr[i] = 0; pr[i] = 0;
  }
  int ans = -1, km = -1;
  for (int i = 1; i <= n; i++) {
    f[i] = 1;
    fp[i] = 0;
    int pos;
    int from = (lower_bound(a + 1, a + n + 1, make_pair(h[i] + d, 0)) - a);
    if (from <= n) {
      int u = find_max(from, n, pos) + 1;
      if (u > f[i]) {
        f[i] = u;
        fp[i] = pos;
      }
    }
    int to = (lower_bound(a + 1, a + n + 1, make_pair(h[i] - d, n + 1)) - a) - 1;
    if (to >= 1) {
      int u = find_max(1, to, pos) + 1;
      if (u > f[i]) {
        f[i] = u;
        fp[i] = pos;
      }
    }
    modify(pz[i], f[i], i);
    if (f[i] > ans) {
      ans = f[i];
      km = i;
    }
  }
  vector <int> ret;
  while (km > 0) {
    ret.push_back(km);
    km = fp[km];
  }
  printf("%d\n", ans);
  for (int i = ans - 1; i > 0; i--) {
    printf("%d ", ret[i]);
  }
  printf("%d\n", ret[0]);
  return 0;
}