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

const int inf = (int)2e9;
const int N = 2010;

int a[N][N];
long long d[N];
bool b[N];
int pr[N];
vector < pair <int, int> > g[N];
int x[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    d[i] = inf;
    b[i] = true;
    pr[i] = -1;
  }
  d[0] = 0;
  for (int it = 0; it < n; it++) {
    int km = -1;
    for (int i = 0; i < n; i++) {
      if (!b[i]) {
        continue;
      }
      if (km == -1 || d[i] < d[km]) {
        km = i;
      }
    }
    b[km] = false;
    if (pr[km] != -1) {
      if (d[km] == 0) {
        puts("NO");
        return 0;
      }
      g[km].push_back(make_pair(pr[km], d[km]));
      g[pr[km]].push_back(make_pair(km, d[km]));
    }
    for (int j = 0; j < n; j++) {
      if (b[j] && a[km][j] < d[j]) {
        d[j] = a[km][j];
        pr[j] = km;
      }
    }
  }
  for (int st = 0; st < n; st++) {
    for (int i = 0; i < n; i++) {
      d[i] = -1;
    }
    d[st] = 0;
    int b = 0, e = 0;
    x[0] = st;
    while (b <= e) {
      int sz = g[x[b]].size();
      for (int j = 0; j < sz; j++) {
        int u = g[x[b]][j].first;
        if (d[u] == -1) {
          e++;
          x[e] = u;
          d[u] = d[x[b]] + g[x[b]][j].second;
        }
      }
      b++;
    }
    for (int i = 0; i < n; i++) {
      if (d[i] != a[st][i]) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}