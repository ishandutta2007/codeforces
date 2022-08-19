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

const long long inf = (long long)1e18;

const int N = 400010;

pair <int, int> h[N];
long double xs[N];
int st[N];
long long value[N], cost[N], f[N], g[N];

long double inter(int i, int j) {
  long double vv = value[i];
  vv *= value[j];
  long double fvv = vv * (f[j] - f[i]);
  long double gv = ((long double)g[i] * value[j]) - ((long double)g[j] * value[i]);
  long double vmv = value[j] - value[i];
  return (fvv + gv) / vmv;
}

int main() {
  int n;
  long long goal;
  cin >> n >> goal;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &(h[i].second), &(h[i].first));
    h[i].second = -h[i].second;
  }
  sort(h, h + n);
  int m = 1;
  for (int i = 1; i < n; i++) {
    int profit = -h[i].second;
    int last_p = -h[m - 1].second;
    if (profit > last_p) {
      h[m] = h[i];
      m++;
    }
  }
  n = m;
  for (int i = 0; i < n; i++) {
    cost[i] = h[i].first;
    value[i] = -h[i].second;
  }
  int e = 0;
  for (int i = 0; i < n; i++) {
    f[i] = inf;
    g[i] = 0;
    if (cost[i] == 0) {
      f[i] = 0;
      g[i] = 0;
    } else {
      int ll = 1, rr = e;
      while (ll < rr) {
        int mid = (ll + rr) >> 1;
        if (xs[mid] < cost[i]) ll = mid + 1;
        else rr = mid;
      }
      for (int u = ll - 5; u <= ll + 5; u++) {
        if (u < 1 || u > e) continue;
        int j = st[u];
        long long nf = f[j], ng = g[j];
        if (ng < cost[i]) {
          long long need = cost[i] - ng;
          if (need > 0) {
            long long days = (need + value[j] - 1) / value[j];
            nf += days;
            ng += days * value[j];
          }
        }
        ng -= cost[i];
        if (nf < f[i] || nf == f[i] && ng > g[i]) {
          f[i] = nf;
          g[i] = ng;
        }
      }
    }
    while (e > 1) {
      long double xx = inter(st[e], i);
      if (xx < xs[e - 1]) e--;
      else break;
    }
    e++;
    st[e] = i;
    if (e > 1) {
      xs[e - 1] = inter(st[e - 1], st[e]);
    }
  }
  long long ans = inf;
  for (int i = 0; i < n; i++) {
    long long cur = f[i];
    if (g[i] < goal) {
      long long need = goal - g[i];
      cur += (need + value[i] - 1) / value[i];
    }
    if (cur < ans) ans = cur;
  }
  cout << ans << endl;
  return 0;
}