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

const int N = 777;

char s[N][N];
int value[N];
int a[N];
bool was[N];
int x[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; i++) {
    was[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      continue;
    }
    int b = 0, e = 0;
    x[0] = i;
    was[i] = true;
    while (b <= e) {
      for (int j = 0; j < n; j++) {
        if (!was[j] && s[x[b]][j] == '1') {
          e++;
          x[e] = j;
          was[j] = true;
        }
      }
      b++;
    }
    for (int pos = 0; pos <= e; pos++) {
      value[pos] = a[x[pos]];
    }
    sort(x, x + e + 1);
    sort(value, value + e + 1);
    for (int pos = 0; pos <= e; pos++) {
      a[x[pos]] = value[pos];
    }
  }
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n - 1]);
  return 0;
}