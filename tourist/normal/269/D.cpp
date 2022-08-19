#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

const int N = 888888;
const int inf = 1000000000;

set < pair <int, int> > s, m1, m2;
set < pair <int, int> >::iterator it;
int h[N], l[N], r[N], pe[N], f[N], x[N], deg[N], ss[N], ff[N], pred[N], last[N], dd[N];
int n, t, i, j, m;
pair <int, int> e[N];

int main() {
  scanf("%d %d", &n, &t);
  for (i=0;i<n;i++) scanf("%d %d %d", h+i, l+i, r+i);
  int ke = 0;
  for (i=0;i<n;i++) {
    e[ke].first = l[i];
    e[ke++].second = i;
    e[ke].first = r[i];
    e[ke++].second = ~i;
  }
  l[n] = l[n+1] = -inf;
  r[n] = r[n+1] = +inf;
  sort(e, e+ke);
  s.clear();
  m1.clear();
  m2.clear();
  s.insert(make_pair(0, n));
  s.insert(make_pair(t, n+1));
  for (i=0;i<ke;i++) {
    pe[i] = e[i].second;
    if (pe[i] < 0) {
      s.erase(make_pair(h[~pe[i]], ~pe[i]));
    } else {
      it = s.lower_bound(make_pair(h[pe[i]], pe[i]));
      int right = (*it).second;
      it--;
      int left = (*it).second;
      m2.insert(make_pair(left, right));
      m1.insert(make_pair(left, pe[i]));
      m1.insert(make_pair(pe[i], right));
      s.insert(make_pair(h[pe[i]], pe[i]));
    }
  }
  it = m1.begin();
  m = 0;
  while (it != m1.end()) {
    if (m2.find(*it) == m2.end()) {
      m++;
      ss[m] = (*it).first;
      ff[m] = (*it).second;
      int ml = l[ss[m]];
      if (l[ff[m]] > ml) ml = l[ff[m]];
      int mr = r[ss[m]];
      if (r[ff[m]] < mr) mr = r[ff[m]];
      dd[m] = mr-ml;
    }
    it++;
  }
  for (i=0;i<n+2;i++) last[i] = deg[i] = 0;
  for (i=1;i<=m;i++) {
    deg[ff[i]]++;
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  int e = 0;
  for (i=0;i<n+2;i++)
    if (deg[i] == 0) {
      e++;
      x[e] = i;
    }
  i = 1;
  while (i <= e) {
    j = last[x[i]];
    while (j > 0) {
      deg[ff[j]]--;
      if (deg[ff[j]] == 0) {
        e++;
        x[e] = ff[j];
      }
      j = pred[j];
    }
    i++;
  }
  for (i=0;i<n+2;i++) f[i] = 0;
  f[n] = 2*inf;
  for (int ii=1;ii<=e;ii++) {
    i = x[ii];
    j = last[i];
    while (j > 0) {
      int ft = f[i];
      if (dd[j] < ft) ft = dd[j];
      if (ft > f[ff[j]]) f[ff[j]] = ft;
      j = pred[j];
    }
  }
  printf("%d\n", f[n+1]);
  return 0;
}