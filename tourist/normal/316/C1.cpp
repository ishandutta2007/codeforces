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

const int M = 100010;

int qs[M], qf[M], c[M], f[M], s[M], obr[M], pr[M], ls[M], kr, r[M], d[M], pj[M], was[M], v[M], nv[M];
int fin, mm, ans;

void add(int x, int y, int z, int xx, int yy, int zz) {
  mm++;
  qs[mm] = x;
  qf[mm] = y;
  c[mm] = z;
  f[mm] = xx;
  s[mm] = yy;
  obr[mm] = zz;
  pr[mm] = ls[x];
  ls[x] = mm;
}
 
bool expath() {
  for (int i=0;i<=fin;i++) d[i] = 1000000, pj[i] = 0, was[i] = 0;
  d[0] = 0;
  int kv = 1, it = 0;
  v[0] = 0;
  while (kv > 0) {
    it++;
    int nkv = 0;
    for (int ii=0;ii<kv;ii++) {
      int i = v[ii];
      int j = ls[i];
      while (j > 0) {
        if (c[j] > f[j])
          if (d[i]+s[j] < d[qf[j]]) {
            d[qf[j]] = d[i]+s[j];
            pj[qf[j]] = j;
            if (was[qf[j]] < it) {
              nv[nkv++] = qf[j];
              was[qf[j]] = it;
            }
          }
        j = pr[j];
      }
    }
    kv = nkv;
    for (int i=0;i<kv;i++) v[i] = nv[i];
  }
  if (d[fin] >= 10000) return false;
  ans += d[fin];
  kr = 0;
  int p = fin;
  while (p > 0) {
    r[kr++] = pj[p];
    p = qs[pj[p]];
  }
  return true;
}

int q[88][88];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++) scanf("%d", &q[i][j]);
  fin = n*m+1; mm = 0;
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++) {
      if ((i+j) & 1) {
        add(0, i*m+j+1, 1, 0, 0, 0);
        for (int dx=-1;dx<=1;dx++)
          for (int dy=-1;dy<=1;dy++)
            if (dx+dy != 0 && (dx == 0 || dy == 0)) {
              int x = i+dx, y = j+dy;
              if (x >= 0 && y >= 0 && x < n && y < m) {
                add(i*m+j+1, x*m+y+1, 1, 0, (q[i][j] != q[x][y]), mm+2);
                add(x*m+y+1, i*m+j+1, 0, 0, -(q[i][j] != q[x][y]), mm);
              }
            }
      } else {
        add(i*m+j+1, fin, 1, 0, 0, 0);
      }
    }
  ans = 0;
  while (expath())
    for (int j=0;j<kr;j++) {
      f[r[j]]++;
      if (obr[r[j]] != 0) f[obr[r[j]]]--;
    }
  printf("%d\n", ans);
  return 0;
}