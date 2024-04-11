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
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 444444;

int n, m, e;
bool was[N];
int g[N][5], kg[N];
int ver[N], x[N], xx[N], st[N], fin[N], sz[N], xxx[N];
vector <int> u[N];
int gg[42][42];

void go(int v, int w) {
  if (w == m || (w == n-1 && n == m)) {
    if (w == n-1 && n == m && gg[ver[0]][ver[w]] == 0) return;
    for (int i=0;i<w;i++) printf("%d %d\n", ver[i], ver[i+1]);
    if (w == n-1 && n == m) printf("%d %d\n", ver[w], ver[0]);
    exit(0);
  }
  for (int i=1;i<=n;i++)
    if (!was[i] && gg[v][i] == 1) {
      ver[w+1] = i;
      was[i] = true;
      go(i, w+1);
      was[i] = false;
    }
}              

void dfs(int v) {
          for (int q=0;q<kg[v];q++) {
            int j = g[v][q];
            if (!was[j]) {
              e++;
              x[e] = j;
              was[j] = true;
              dfs(j);
            }
          }
}

int main() {
  scanf("%d %d", &n, &m);
  if (n <= 9) {
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++) gg[i][j] = (i != j);
    for (int i=1;i<=m;i++) {
      int qs, qf;
      scanf("%d %d", &qs, &qf);
      gg[qs][qf] = gg[qf][qs] = 0;
    }
    for (int i=1;i<=n;i++) was[i] = false;
    for (int i=1;i<=n;i++) {
      ver[0] = i;
      was[i] = true;
      go(i, 0);
      was[i] = false;
    }
    printf("%d\n", -1);
  } else {
    for (int i=1;i<=n;i++) kg[i] = 0;
    for (int i=1;i<=m;i++) {
      int qs, qf;
      scanf("%d %d", &qs, &qf);
      g[qs][kg[qs]++] = qf;
      g[qf][kg[qf]++] = qs;
    }
    for (int i=1;i<=n;i++) was[i] = false;
    int kc = 0;
    for (int i=1;i<=n;i++)
      if (!was[i]) {
        kc++;
        st[kc] = e+1;
        e++;
        x[e] = i;
        was[i] = true;
        dfs(i);
        fin[kc] = e;
        sz[kc] = fin[kc] - st[kc] + 1;
      }
    for (int q=1;q<=kc;q++)
      if (sz[q] >= (n+1)/2) {
        int i = st[q], r = 0;
        for (int j=1;j<=sz[q];j++) {
          r++;
          xx[r] = x[i];
          i += 2;
          if (i > fin[q]) {
            i = st[q] + (i - fin[q] - 1);
            if (sz[q] % 2 == 0) i++;
          }
        }
        if (sz[q] % 2 == 0) {
          int tmp = xx[r-1];
          xx[r-1] = xx[r];
          xx[r] = tmp;
        }
        for (int i=1;i<=r;i++) u[i].clear();
        for (int w=1;w<=kc;w++)
          if (q != w) {
            for (int i=st[w];i<=fin[w];i++) u[i-st[w]+1].push_back(x[i]);
          }
        int z = 0;
        for (int i=1;i<=r;i++) {
          z++;
          xxx[z] = xx[i];
          int sss = u[i].size();
          for (int j=0;j<sss;j++) {
            z++;
            xxx[z] = u[i][j];
          }
        }
        for (int q=1;q<=m && q<n;q++) printf("%d %d\n", xxx[q], xxx[q+1]);
        if (m == n) printf("%d %d\n", xxx[n], xxx[1]);
        exit(0);
      }
    int i = 1, j = (n + 1) / 2 + 1;
    for (int q=1;q<=n;q++)
      if (q & 1) xx[q] = x[i++];
      else xx[q] = x[j++];
    for (int q=1;q<=m && q<n;q++) printf("%d %d\n", xx[q], xx[q+1]);
    if (m == n) printf("%d %d\n", xx[n], xx[1]);
  }
  return 0;
}