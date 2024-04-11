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

long long ff[111], f[111], ans[111];
int s, k, i, j, ka;

void go(int v, int z) {
  if (z == 0) {
    if (ka == 1) ans[ka++] = 0;
    printf("%d\n",ka);
    for (i=0;i<ka-1;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[ka-1]);
    exit(0);
  }
  if (v == 0) return;
  if (ff[v-1] >= z) go(v-1,z);
  if (f[v] <= z) {
    ans[ka++] = f[v];
    go(v-1,z-f[v]);
    ka--;
  }
}

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  scanf("%d %d",&s,&k);
  f[0] = 1;
  for (i=1;i<=50;i++) {
    f[i] = 0;
    for (j=i-1;j>=i-k && j>=0;j--) f[i] += f[j];
    if (f[i] > s) break;
  }
  ff[0] = 0;
  for (j=1;j<i;j++) ff[j] = ff[j-1]+f[j];
  ka = 0;
  go(i-1,s);
  return 0;
}