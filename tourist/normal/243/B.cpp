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

const int N = 400010;

int n, m, h, t, i;
int deg[N], ss[N], ff[N], pred[N], last[N], used[N];

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  scanf("%d %d %d %d", &n, &m, &h, &t);
  for (i=0;i<m;i++) scanf("%d %d", ss+i, ff+i);
  for (i=0;i<m;i++) {
    ss[i+m] = ff[i];
    ff[i+m] = ss[i];
  }
  for (i=1;i<=n;i++) last[i] = -1;
  for (i=0;i<m+m;i++) {
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  memset(deg, 0, sizeof(deg));
  for (i=0;i<m;i++) deg[ss[i]]++, deg[ff[i]]++;
  for (i=1;i<=n;i++) used[i] = 0;
  int it = 0;
  for (i=0;i<m+m;i++)
    if (deg[ss[i]] >= h+1 && deg[ff[i]] >= t+1) {
      int good = 0;
      if (deg[ss[i]] >= h+t+2 || deg[ff[i]] >= h+t+2) good = 1;
      if (!good) {
        it++;
        int cnt = 0;
        int j = last[ss[i]];
        while (j >= 0) {
          if (used[ff[j]] != it) {
            used[ff[j]] = it;
            cnt++;
          }
          j = pred[j];
        }
        j = last[ff[i]];
        while (j >= 0) {
          if (used[ff[j]] != it) {
            used[ff[j]] = it;
            cnt++;
          }
          j = pred[j];
        }
        if (cnt >= h+t+2) good = 1;
      }
      if (good) {
        printf("YES\n");
        printf("%d %d\n", ss[i], ff[i]);
        int ii;
        for (ii=1;ii<=n;ii++) used[ii] = 0;
        int j = last[ss[i]];
        while (j >= 0) {
          used[ff[j]] |= 1;
          j = pred[j];
        }
        j = last[ff[i]];
        while (j >= 0) {
          used[ff[j]] |= 2;
          j = pred[j];
        }
        used[ss[i]] = 0;
        used[ff[i]] = 0;
        vector <int> b, c;
        b.clear();
        c.clear();
        for (ii=1;ii<=n;ii++)
          if (used[ii] == 1) b.push_back(ii); else
          if (used[ii] == 2) c.push_back(ii);
        for (ii=1;ii<=n;ii++)
          if (used[ii] == 3)
            if (b.size() < h) b.push_back(ii);
            else c.push_back(ii);
        for (i=0;i<h-1;i++) printf("%d ", b[i]);
        printf("%d\n", b[h-1]);
        for (i=0;i<t-1;i++) printf("%d ", c[i]);
        printf("%d\n", c[t-1]);
        return 0;
      }
    }
  printf("NO\n");
  return 0;
}