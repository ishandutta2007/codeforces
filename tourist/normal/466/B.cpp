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
  long long n, a, b;
  cin >> n >> a >> b;
  n *= 6;
  bool flag = false;
  if (a > b) {
    swap(a, b);
    flag = true;
  }
  long long ans = (long long)9e18;
  long long ax = -1, ay = -1;
  for (long long xx = 1; xx <= n; xx++) {
    long long x = xx;
    long long y = (n + x - 1) / x;
    if (y < x) {
      break;
    }
    if (x < a) x = a;
    if (y < b) y = b;
    if (x * y < ans) {
      ans = x * y;
      ax = x;
      ay = y;
    }
  }
  if (flag) {
    swap(ax, ay);
  }
  cout << ans << endl;
  cout << ax << " " << ay << endl;
  return 0;
}