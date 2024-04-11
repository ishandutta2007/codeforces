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

int n, s[333333], pz[333333], have[333333], p[333333];

void modify(int x, int v) {
  while (x <= n) {
    s[x] += v;
    x = (x | (x-1))+1;
  }
}

int findsum(int x) {
  int v = 0;
  while (x > 0) {
    v += s[x];
    x &= x-1;
  }
  return v;
}

void put(int x, int v) {
  if (have[x] != v) {
    modify(x, v-have[x]);
    have[x] = v;
  }
}

int main() {
  scanf("%d", &n);
  for (int i=1;i<=n;i++) {
    int foo;
    scanf("%d", &foo);
    p[i] = foo;
    pz[foo] = i;
  }
  for (int i=1;i<=n;i++) s[i] = have[i] = 0;
  for (int i=1;i<n;i++)
    if (pz[i] > pz[i+1]) put(i, 1);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int com, x, y;
    scanf("%d %d %d", &com, &x, &y);
    if (com == 1) {
      printf("%d\n", findsum(y-1) - findsum(x-1) + 1);
    } else {
      int tmp = p[x]; p[x] = p[y]; p[y] = tmp;
      pz[p[x]] = x;
      pz[p[y]] = y;
      {
        int z = x;
        if (p[z] > 1)
          if (pz[p[z]-1] > pz[p[z]]) put(p[z]-1, 1);
          else put(p[z]-1, 0);
        if (p[z] < n)
          if (pz[p[z]] > pz[p[z]+1]) put(p[z], 1);
          else put(p[z], 0);
      }
      {
        int z = y;
        if (p[z] > 1)
          if (pz[p[z]-1] > pz[p[z]]) put(p[z]-1, 1);
          else put(p[z]-1, 0);
        if (p[z] < n)
          if (pz[p[z]] > pz[p[z]+1]) put(p[z], 1);
          else put(p[z], 0);
      }
    }
  }
  return 0;
}