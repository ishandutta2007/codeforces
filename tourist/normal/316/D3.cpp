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

const int md = 1000000007;

int g[1111111];

int main() {
  int n;
  scanf("%d", &n);
  int k1 = 0, k2 = 0;
  for (int i=0;i<n;i++) {
    int foo;
    scanf("%d", &foo);
    if (foo == 1) k1++;
    else k2++;
  }
  g[0] = 1;
  for (int i=1;i<=k1;i++) g[i] = (g[i-1] + (long long)g[i-2] * (i-1)) % md;
  int ans = g[k1];
  for (int i=1;i<=k2;i++) ans = (long long)ans * (k1+i) % md;
  printf("%d\n", ans);
  return 0;
}