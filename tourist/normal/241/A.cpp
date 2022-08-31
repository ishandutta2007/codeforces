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

int d[11111];

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  int m, k, i, s, mx = 0;
  scanf("%d %d", &m, &k);
  for (i=0;i<m;i++) scanf("%d", d+i);
  int fuel = 0, ans = 0;
  for (i=0;i<m;i++) {
    scanf("%d", &s);
    if (s > mx) mx = s;
    fuel += s;
    while (fuel < d[i]) fuel += mx, ans += k;
    ans += d[i];
    fuel -= d[i];
  }
  printf("%d\n", ans);
  return 0;
}