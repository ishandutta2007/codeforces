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

int can[1111111];
int a[111111], next[111111][33];
int x[33], y[33];
int n, i, j, k;

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  scanf("%d", &n);
  for (i=0;i<n;i++) scanf("%d", a+i);
  for (j=0;j<20;j++) {
    int last = n;
    for (i=n-1;i>=0;i--) {
      if (a[i] & (1 << j)) last = i;
      next[i][j] = last;
    }
  }
  for (i=0;i<(1<<20);i++) can[i] = 0;
  for (i=0;i<n;i++) {
    for (j=0;j<20;j++) {
      x[j] = next[i][j];
      y[j] = (1 << j);
    }
    for (j=0;j<20;j++)
      for (k=j+1;k<20;k++)
        if (x[j] > x[k]) {
          int tmp;
          tmp = x[j]; x[j] = x[k]; x[k] = tmp;
          tmp = y[j]; y[j] = y[k]; y[k] = tmp;
        }
    int cur = 0;
    j = 0;
    while (j < 20) {
      if (x[j] == n) break;
      k = j;
      while (k < 20 && x[j] == x[k]) k++;
      for (int u=j;u<k;u++) cur += y[u];
      can[cur] = 1;
      j = k;
    }
  }
  for (i=0;i<n;i++) can[a[i]] = 1;
  int ans = 0;
  for (i=0;i<(1<<20);i++) ans += can[i];
  printf("%d\n", ans);
  return 0;
}