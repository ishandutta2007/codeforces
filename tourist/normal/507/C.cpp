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
  long long h, n;
  cin >> h >> n;
  long long ans = 0;
  int mv = 0;
  n--;
  for (int i = h - 1; i >= 0; i--) {
    int real = !!(n & (1LL << i));
    if (mv != real) {
      ans += ((1LL << (i + 1)) - 1);
      mv ^= 1;
    }
    mv ^= 1;
    ans++;
  }
  cout << ans << endl;
  return 0;
}