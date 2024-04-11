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

int rnd(int x) {
  return (x < 0) ? (x+1) : x;
}

int n, i, j, k;
int d[1717], ex[1717], ey[1717];
pair <int, int> p[171717];
int sa[171717], sb[171717], sc[171717];
int x[171717];
int have[171717], id[171717];
int can[171][171];
int a[17], b[17];

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  scanf("%d", &n);
  for (i=1;i<=n;i++) scanf("%d %d", &p[i].first, &p[i].second);
  sort(p+1, p+n+1);
  for (i=1;i<=n;i++) x[i] = p[i].first;
  for (i=1;i<=n;i++) {
    int tmp = p[i].first;
    p[i].first = p[i].second;
    p[i].second = tmp;
  }
  sort(p+1, p+n+1);
  for (i=0;i<9;i++) scanf("%d", a+i);
  sort(a, a+9);
  memset(have, 0, sizeof(have));
  for (i=0;i<9;i++)
    for (j=i+1;j<9;j++)
      for (k=j+1;k<9;k++) have[a[i]+a[j]+a[k]] = 1;
  int kd = 0;
  for (i=1;i<=n;i++)
    if (have[i]) {
      d[++kd] = i;
      id[i] = kd;
    }
  memset(can, 0, sizeof(can));
  for (i=0;i<9;i++)
    for (j=i+1;j<9;j++)
      for (k=j+1;k<9;k++)
        for (int ii=0;ii<9;ii++)
          if (ii != i && ii != j && ii != k)
            for (int jj=0;jj<9;jj++)
              if (jj != i && jj != j && jj != k)
                for (int kk=0;kk<9;kk++)
                  if (kk != i && kk != j && kk != k)
                    can[id[a[i]+a[j]+a[k]]][id[a[ii]+a[jj]+a[kk]]] = 1;
  int ke = 0;
  for (i=1;i<=kd;i++)
    for (j=1;j<=kd;j++)
      if (can[i][j]) {
        ke++;
        ex[ke] = d[i];
        ey[ke] = n-d[j];
      }
  for (j=1;j<=ke;j++) {
    sa[0] = sb[0] = sc[0] = 0;
    for (i=1;i<=n;i++) {
      sa[i] = sa[i-1];
      sb[i] = sb[i-1];
      sc[i] = sc[i-1];
      if (p[i].second <= x[ex[j]]) sa[i]++; else
      if (p[i].second <= x[ey[j]]) sb[i]++;
      else sc[i]++;
    }
    if (sa[n] != ex[j]) continue;
    if (sb[n] != ey[j]-ex[j]) continue;
    for (k=1;k<=ke;k++) {
      if (p[ex[k]].first == p[ex[k]+1].first) continue;
      if (p[ey[k]].first == p[ey[k]+1].first) continue;
      b[0] = sa[ex[k]];
      b[1] = sa[ey[k]]-b[0];
      b[2] = ex[j]-b[0]-b[1];
      b[3] = sb[ex[k]];
      b[4] = sb[ey[k]]-b[3];
      b[5] = (ey[j]-ex[j])-b[3]-b[4];
      b[6] = sc[ex[k]];
      b[7] = sc[ey[k]]-b[6];
      b[8] = (n-ey[j])-b[6]-b[7];
      sort(b, b+9);
      int ok = 1;
      for (i=0;i<9;i++)
        if (a[i] != b[i]) ok = 0;
      if (ok) {
        printf("%d.5 %d.5\n", rnd(x[ex[j]]), rnd(x[ey[j]]));
        printf("%d.5 %d.5\n", rnd(p[ex[k]].first), rnd(p[ey[k]].first));
        return 0;
      }
    }
  }
  printf("%d\n", -1);
  return 0;
}