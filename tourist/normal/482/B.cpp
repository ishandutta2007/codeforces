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

const int N = 200010;

int from[N], to[N], num[N];
int s[N][30];
int a[N][30];
int sum[N][30];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 30; j++) {
      s[i][j] = 0;
    }
  }
  for (int k = 0; k < m; k++) {
    scanf("%d %d %d", from + k, to + k, num + k);
    from[k]--; to[k]--;
    for (int j = 0; j < 30; j++) {
      if (num[k] & (1 << j)) {
        s[from[k]][j]++;
        s[to[k] + 1][j]--;
      }
    }
  }
  for (int j = 0; j < 30; j++) {
    int bal = 0;
    sum[0][j] = 0;
    for (int i = 0; i < n; i++) {
      bal += s[i][j];
      a[i][j] = (bal > 0);
      sum[i + 1][j] = sum[i][j] + a[i][j];
    }
  }
  for (int k = 0; k < m; k++) {
    for (int j = 0; j < 30; j++) {
      if (!(num[k] & (1 << j))) {
        int get = sum[to[k] + 1][j] - sum[from[k]][j];
        int need = (to[k] + 1) - (from[k]);
        if (get == need) {
          puts("NO");
          return 0;
        }
      }
    }
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    int res = 0;
    for (int j = 0; j < 30; j++) {
      if (a[i][j]) {
        res += (1 << j);
      }
    }
    if (i > 0) printf(" ");
    printf("%d", res);
  }
  printf("\n");
  return 0;
}