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

const int N = 1000010;

int ss[N], ff[N], pred[N], last[N], deep[N];
bool was[N], bad[N];
int d, ans;

void build(int v) {
  was[v] = true;
  deep[v] = -1;
  if (bad[v]) deep[v] = 0;
  int j = last[v];
  while (j > 0) {
    if (!was[ff[j]]) {
      build(ff[j]);
      if (deep[ff[j]] >= 0) {
        int cur = deep[ff[j]] + 1;
        if (cur > deep[v]) deep[v] = cur;
      }
    }
    j = pred[j];
  }
}

void go(int v, int up) {
  if (deep[v] <= d && up <= d) ans++;
  was[v] = true;
  vector <int> values, vertices;
  int j = last[v];
  while (j > 0) {
    if (!was[ff[j]]) {
      values.push_back(deep[ff[j]] == -1 ? -1 : (2 + deep[ff[j]]));
      vertices.push_back(ff[j]);
    }
    j = pred[j];
  }
  int sz = values.size();
  if (sz == 0) return;
  vector <int> prefmax(sz), sufmax(sz);
  int mx = -1;
  for (int i=0;i<sz;i++) {
    prefmax[i] = mx;
    if (values[i] > mx) mx = values[i];
  }
  mx = -1;
  for (int i=sz-1;i>=0;i--) {
    sufmax[i] = mx;
    if (values[i] > mx) mx = values[i];
  }
  for (int i=0;i<sz;i++) {
    int newup = up == -1 ? -1 : (up + 1);
    if (prefmax[i] > newup) newup = prefmax[i];
    if (sufmax[i] > newup) newup = sufmax[i];
    if (bad[v] && 1 > newup) newup = 1;
    go(vertices[i], newup);
  }
}

int main() {
  int n, m;
  scanf("%d %d %d", &n, &m, &d);
  for (int i=1;i<=n;i++) bad[i] = false;
  for (int i=0;i<m;i++) {
    int foo;
    scanf("%d", &foo);
    bad[foo] = true;
  }
  for (int i=1;i<=n-1;i++) {
    scanf("%d %d", ss+i, ff+i);
    ss[i + n - 1] = ff[i];
    ff[i + n - 1] = ss[i];
  }
  for (int i=1;i<=n;i++) last[i] = 0;
  for (int i=1;i<=n+n-2;i++) {
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  for (int i=1;i<=n;i++) was[i] = false;
  build(1);
  for (int i=1;i<=n;i++) was[i] = false;
  ans = 0;
  go(1, -1);
  printf("%d\n", ans);
  return 0;
}