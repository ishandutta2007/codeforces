#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int md = 1000000007;
const int N = 1234567;

int p[N], f[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  f[1] = 2;
  for (int i = 2; i <= n; i++) {
    f[i] = 2;
    for (int k = p[i]; k < i; k++) {
      f[i] += f[k];
      if (f[i] >= md) f[i] -= md;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += f[i];
    if (ans >= md) ans -= md;
  }
  printf("%d\n", ans);
  return 0;
}