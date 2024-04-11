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

int from[42], to[42];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", from + i, to + i);
  }
  double res = 0;
  for (int ans = 1; ans <= 10007; ans++) {
    for (int t = 0; t < (1 << n); t++) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (t & (1 << i)) {
          cnt++;
        }
      }
      if (cnt < 2) {
        continue;
      }
      double prob = 1.0;
      for (int i = 0; i < n; i++) {
        int a = from[i];
        int b = to[i];
        if (t & (1 << i)) {
          if (a < ans) a = ans;
        } else {
          if (b > ans - 1) b = ans - 1;
        }
        if (a > b) {
          prob = 0.0;
          break;
        }
        int cur = b - a + 1;
        prob *= 1.0 * cur / (to[i] - from[i] + 1);
      }
      res += prob;
    }
  }
  printf("%.17f\n", res);
  return 0;
}