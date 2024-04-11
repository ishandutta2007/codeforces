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
  int n, m, a, b;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  int ans = 123456789;
  for (int x = 0; x <= n; x++) {
    int ab = (n - x + m - 1) / m;
    int cur = a * x + ab * b;
    if (cur < ans) ans = cur;
  }
  printf("%d\n", ans);
  return 0;
}