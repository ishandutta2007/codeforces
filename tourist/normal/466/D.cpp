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

const int md = 1000000007;

const int N = 4010;

int a[N];
int f[N][N];

int main() {
  int n, h;
  scanf("%d %d", &n, &h);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (a[i] > h) {
      printf("%d\n", 0);
      return 0;
    }
  }
  memset(f, 0, sizeof(f));
  f[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int open = 0; open <= i; open++) {
      int ft = f[i][open];
      if (ft == 0) {
        continue;
      }
      for (int x = 0; x <= 1; x++) {
        for (int y = -1; y <= 0; y++) {
          if (a[i] + open + x != h) {
            continue;
          }
          int now = open + x + y;
          if (now >= 0) {
            if (y == 0) {
              f[i + 1][now] += ft;
              if (f[i + 1][now] >= md) {
                f[i + 1][now] -= md;
              }
            } else {
              f[i + 1][now] = (f[i + 1][now] + (long long)ft * (open + x)) % md;
            }
          }
        }
      }
    }
  }
  printf("%d\n", f[n][0]);
  return 0;
}