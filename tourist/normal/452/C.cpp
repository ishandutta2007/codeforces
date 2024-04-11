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

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (n == 1) {
    printf("1.0\n");
    return 0;
  }
  if (m == 1) {
    printf("%.17lf\n", (double)(1.0 / n));
    return 0;
  }
  long double prob = 1.0;
  for (int i = 0; i < m; i++) {
    prob *= (m * n - n - i);
    prob /= (m * n - i);
  }
  long double ans = 0.0;
  long double sum = prob;
  for (int k = 0; k <= m && k <= n; k++) {
    ans += prob * k * k;
    if (k == m || k == n) {
      break;
    }
    prob *= (n - k);
    prob /= (m * n - m - n + k + 1);
    prob *= (m - k);
    prob /= (k + 1);
    sum += prob;
  }
  printf("%.17lf\n", (double)(ans / n));
  return 0;
}