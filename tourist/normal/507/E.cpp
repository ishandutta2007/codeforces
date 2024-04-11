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

vector < pair <int, int> > g[N];
int from[N], to[N], value[N];
int d[N], dm[N], x[N], pr[N];
int real[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", from + i, to + i, value + i);
    from[i]--; to[i]--;
    g[from[i]].push_back(make_pair(to[i], i));
    g[to[i]].push_back(make_pair(from[i], i));
  }
  for (int i = 0; i < n; i++) {
    d[i] = -1;
    dm[i] = -1;
  }
  int b = 0, e = 0;
  x[0] = 0;
  d[0] = 0;
  dm[0] = 0;
  while (b <= e) {
    int sz = g[x[b]].size();
    for (int j = 0; j < sz; j++) {
      int u = g[x[b]][j].first;
      int id = g[x[b]][j].second;
      int ndm = dm[x[b]] + (value[id] == 1);
      if (d[u] != -1) {
        if (d[u] == d[x[b]] + 1 && ndm > dm[u]) {
          dm[u] = ndm;
          pr[u] = id;
        }
        continue;
      }
      e++;
      x[e] = u;
      d[u] = d[x[b]] + 1;
      dm[u] = ndm; 
      pr[u] = id;
    }
    b++;
  }
  for (int i = 0; i < m; i++) {
    real[i] = 0;
  }
  int p = n - 1;
  while (p > 0) {
    real[pr[p]] = 1;
    p = from[pr[p]] + to[pr[p]] - p;
  }
  vector <int> ret;
  for (int i = 0; i < m; i++) {
    if (real[i] != value[i]) {
      ret.push_back(i);
    }
  }
  printf("%d\n", (int)ret.size());
  for (int i = 0; i < (int)ret.size(); i++) {
    printf("%d %d %d\n", from[ret[i]] + 1, to[ret[i]] + 1, real[ret[i]]);
  }
  return 0;
}