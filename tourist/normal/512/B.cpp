#include <cstring>
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
#include <cassert>

using namespace std;

inline int gcd(int a, int b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

const int inf = (int)1e9;
const int N = 310;
const int MAX = 150010;

int a[N], c[N];
int f[N][MAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  vector <int> divs;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        divs.push_back(j);
        if (j * j < a[i]) {
          divs.push_back(a[i] / j);
        }
      }
    }
  }
  sort(divs.begin(), divs.end());
  divs.resize(unique(divs.begin(), divs.end()) - divs.begin());
  int sz = divs.size();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < sz; j++) {
      f[i][j] = inf;
    }
  }
  for (int i = 0; i < n; i++) {
    f[i][lower_bound(divs.begin(), divs.end(), a[i]) - divs.begin()] = c[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz; j++) {
      if (f[i][j] == inf) {
        continue;
      }
      if (f[i][j] < f[i + 1][j]) {
        f[i + 1][j] = f[i][j];
      }
      int u = gcd(divs[j], a[i]);
      int pos = lower_bound(divs.begin(), divs.end(), u) - divs.begin();
      if (f[i][j] + c[i] < f[i + 1][pos]) {
        f[i + 1][pos] = f[i][j] + c[i];
      }
    }
  }
  printf("%d\n", (f[n][0] == inf ? -1 : f[n][0]));
  return 0;
}