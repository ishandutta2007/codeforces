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

const int N = 111;

int st, fin, n, m, i, j, k, q, kt;
int a[N][N], b[N][N][N], g[N][N], ta[N], tb[N], ans[N], v[N];
vector <int> u[N][N];

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  scanf("%d %d %d %d", &n, &m, &st, &fin);
  st--; fin--;
  memset(a, 0, sizeof(a));
  for (i=0;i<m;i++) {
    int qs, qf;
    scanf("%d %d", &qs, &qf);
    qs--; qf--;
    a[qs][qf] = 1;
  }
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      if (i == j) g[i][j] = 0; else
      if (a[i][j]) g[i][j] = 1;
      else g[i][j] = 424242;
  for (k=0;k<n;k++)
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        if (g[i][k]+g[k][j] < g[i][j]) g[i][j] = g[i][k]+g[k][j];
  scanf("%d", &kt);
  for (i=0;i<kt;i++) {
    scanf("%d %d", ta+i, tb+i);
    ta[i]--; tb[i]--;
    if (g[ta[i]][tb[i]] < 4242) {
      for (j=0;j<=g[ta[i]][tb[i]];j++) {
        u[i][j].clear();
        for (k=0;k<n;k++)
          if (g[ta[i]][k] == j && g[k][tb[i]] == g[ta[i]][tb[i]]-j) {
            u[i][j].push_back(k);
            b[i][j][k] = 1;
          }
      }
    }
  }
  for (i=0;i<n;i++) ans[i] = 4242;
  ans[fin] = 0;
  int dd = 1, it = 0;
  while (dd) {
    dd = 0;
    it++;
    for (i=0;i<kt;i++) {
      if (g[ta[i]][tb[i]] > 4242) continue;
      v[tb[i]] = ans[tb[i]];
      for (j=g[ta[i]][tb[i]]-1;j>=0;j--) {
        int sz = u[i][j].size();
        for (k=0;k<sz;k++) {
          int w = u[i][j][k];
          v[w] = 0;
          for (q=0;q<n;q++)
            if (a[w][q] && b[i][j+1][q])
              if (v[q] > v[w]) v[w] = v[q];
          if (ans[w] < v[w]) v[w] = ans[w];
        }
        if (sz == 1) {
          int w = u[i][j][0];
          if (ans[w] == 4242 && v[w] < it) {
            ans[w] = it;
            dd = 1;
          }
        }
      }
    }
  }
  printf("%d\n", (ans[st] < 4242) ? (ans[st]) : (-1));
  return 0;
}