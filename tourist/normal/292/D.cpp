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

using namespace std;

const int N = 444444;

int p[N], ss[N], ff[N], r[N];
bool imp[N];

int findset(int x) {
  if (x != p[x]) p[x] = findset(p[x]);
  return p[x];
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i=1;i<=m;i++) {
    scanf("%d %d", ss+i, ff+i);
    imp[i] = false;
  }
  int kr = 0;
  for (int i=1;i<=n;i++) p[i] = i;
  for (int i=1;i<=m;i++) {
    int x = findset(ss[i]);
    int y = findset(ff[i]);
    if (x != y) {
      r[kr++] = i;
      imp[i] = true;
      p[x] = y;
    }
  }
  for (int i=1;i<=n;i++) p[i] = i;
  for (int i=m;i>=1;i--) {
    int x = findset(ss[i]);
    int y = findset(ff[i]);
    if (x != y) {
      if (!imp[i]) {
        r[kr++] = i;
        imp[i] = true;
      }
      p[x] = y;
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int from, to;
    scanf("%d %d", &from, &to);
    for (int i=1;i<=n;i++) p[i] = i;
    for (int i=0;i<kr;i++)
      if (r[i] < from || r[i] > to) {
        int x = findset(ss[r[i]]);
        int y = findset(ff[r[i]]);
        if (x != y) p[x] = y;
      }
    int ans = 0;
    for (int i=1;i<=n;i++)
      if (p[i] == i) ans++;
    printf("%d\n", ans);
  }
  return 0;
}