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

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  int n, x, i, ok = 1;
  scanf("%d %d",&n,&x);
  for (i=0;i<n;i++) {
    int q, w;
    scanf("%d %d",&q,&w);
    if (q == x || q == 7-x || w == x || w == 7-x) ok = 0;
  }
  if (ok) puts("YES"); else puts("NO");
  return 0;
}