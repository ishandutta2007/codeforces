#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 1000010;

int cnt[N], zero;

void add(int x, int v) {
  if (cnt[x] == 0) zero--;
  cnt[x] += v;
  if (cnt[x] == 0) zero++;
}

int a[N], b[N], c[N];
vector <int> ans;
vector < pair <int, int> > e;

int main() {
  int n, m, p;
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) scanf("%d", b + i);
  e.clear();
  for (int i = 0; i < n; i++) e.push_back(make_pair(a[i], i));
  for (int i = 0; i < m; i++) e.push_back(make_pair(b[i], ~i));
  sort(e.begin(), e.end());
  int t = 0;
  for (int i = 0; i < n + m; i++) {
    if (e[i].second >= 0) {
      a[e[i].second] = t;
    } else {
      b[~e[i].second] = t;
    }
    if (i + 1 < n + m && e[i].first != e[i + 1].first) {
      t++;
    }
  }
  for (int i = 0; i < t; i++) cnt[i] = 0;
  zero = t;
  for (int i = 0; i < m; i++) add(b[i], 1);
  ans.clear();
  for (int r = 0; r < p; r++) {
    int k = 0;
    for (int i = r; i < n; i += p) c[k++] = a[i];
    if (k < m) {
      continue;
    }
    for (int i = 0; i < m - 1; i++) add(c[i], -1);
    for (int i = m - 1; i < k; i++) {
      add(c[i], -1);
      if (zero == t) {
        ans.push_back((i - (m - 1)) * p + r);
      }
      add(c[i - (m - 1)], 1);
    }
    for (int i = k - (m - 1); i < k; i++) add(c[i], 1);
  }
  sort(ans.begin(), ans.end());
  int sz = ans.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz - 1; i++) printf("%d ", ans[i] + 1);
  if (sz > 0) printf("%d", ans[sz - 1] + 1);
  printf("\n");
  return 0;
}