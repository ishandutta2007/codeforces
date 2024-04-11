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

long long n, i, m;
long long a[444444];

int main() {
  scanf("%I64d", &n);
  for (i=1;i<=n;i++) scanf("%I64d", a+i);
  scanf("%I64d", &m);
  long long mx = 0;
  while (m--) {
    long long w, h;
    scanf("%I64d %I64d", &w, &h);
    long long ans = a[w];
    if (mx > ans) ans = mx;
    printf("%I64d\n", ans);
    if (ans+h > mx) mx = ans+h;
  }
  return 0;
}