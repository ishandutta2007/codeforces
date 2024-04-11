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

int value[123456];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", value + i);
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int x;
    scanf("%d", &x);
    int ans = k + 1;
    for (int a = 0; a < ans; a++) {
      for (int b = 0; a + b < ans; b++) {
        int j = n - 1;
        for (int i = 0; i < n; i++) {
          int u = x - value[i] * a;
          if (b == 0) {
            if (u == 0) {
              ans = a;
            }
            continue;
          }
          if (u < 0 || u % b != 0) {
            continue;
          }
          u /= b;
          while (j >= 0 && value[j] > u) {
            j--;
          }
          if (j >= 0 && value[j] == u) {
            ans = a + b;
          }
        }
      }
    }
    printf("%d\n", (ans > k ? -1 : ans));
  }
  return 0;
}