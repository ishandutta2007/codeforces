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

using namespace std;

const int inf = (int)1e9;

char c[123];
int who[123], skill[123];

int f[1234567];
int kb[1234567];

int main() {
  int _n;
  scanf("%d", &_n);
  for (int i = 0; i < _n; i++) scanf("%d", skill + i);
  sort(skill, skill + _n);
  reverse(skill, skill + _n);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    char ch = getchar();
    while (ch != 'p' && ch != 'b') ch = getchar();
    c[i] = ch;
    scanf("%d", who + i);
  }
  kb[0] = 0;
  for (int t = 1; t < (1 << m); t++) kb[t] = kb[t & (t - 1)] + 1;
  f[(1 << m) - 1] = 0;
  for (int t = (1 << m) - 2; t >= 0; t--) {
    if (who[kb[t]] == 1) {
      f[t] = -inf;
      for (int i = 0; i < m; i++)
        if (!(t & (1 << i))) {
          int ft = f[t + (1 << i)];
          if (c[kb[t]] == 'p') ft += skill[i];
          if (ft > f[t]) f[t] = ft;
        }
    } else {
      f[t] = inf;
      for (int i = 0; i < m; i++)
        if (!(t & (1 << i))) {
          int ft = f[t + (1 << i)];
          if (c[kb[t]] == 'p') ft -= skill[i];
          if (ft < f[t]) f[t] = ft;
        }
    }
  }
  printf("%d\n", f[0]);
  return 0;
}