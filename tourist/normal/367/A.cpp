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

const int N = 2000010;

char s[N];
int x[N], y[N], z[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  x[0] = y[0] = z[0] = 0;
  for (int i = 0; i < n; i++) {
    x[i + 1] = x[i] + (s[i] == 'x');
    y[i + 1] = y[i] + (s[i] == 'y');
    z[i + 1] = z[i] + (s[i] == 'z');
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int nx = x[b] - x[a - 1];
    int ny = y[b] - y[a - 1];
    int nz = z[b] - z[a - 1];
    bool ok = true;
    if (nx - ny > 1 || nx - nz > 1 || ny - nz > 1) ok = false;
    if (ny - nx > 1 || nz - nx > 1 || nz - ny > 1) ok = false;
    if (nx + ny + nz <= 2) ok = true;
    puts(ok ? "YES" : "NO");
  }
  return 0;
}