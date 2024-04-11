#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

int main() {
  long long x, y, m;
  cin >> x >> y >> m;
  long long ans = -1;
  if (x >= m || y >= m) ans = 0; else
  if (x > 0 || y > 0) {
    ans = 0;
    while (x < m && y < m) {
      if (x > y) {
        long long tmp = x;
        x = y;
        y = tmp;
      }
      long long cnt = (y-x) / y;
      if (cnt < 1) cnt = 1;
      x += cnt*y;
      ans += cnt;
    }
  }
  cout << ans << endl;
  return 0;
}