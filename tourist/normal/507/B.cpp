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
  long long r, x, y, xx, yy;
  cin >> r >> x >> y >> xx >> yy;
  long long dist = (x - xx) * (x - xx) + (y - yy) * (y - yy);
  long long step = 4 * r * r;
  long long res = (dist + step - 1) / step;
  long long ans = sqrt(1.0 * res);
  while (ans * ans < res) ans++;
  while (ans > 0 && (ans - 1) * (ans - 1) >= res) ans--;
  cout << ans << endl;
  return 0;
}