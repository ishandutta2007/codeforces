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

long long s[1234567];

int main() {
  int n;
  scanf("%d", &n);
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    s[i + 1] = s[i] + foo;
  }
  long long ans = 0;
  if (s[n] % 3 == 0) {
    long long u = s[n] / 3, v = 2 * s[n] / 3;
    long long cnt = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == v) {
        ans += cnt;
      }
      if (s[i] == u) {
        cnt++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}