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

const int N = 1234567;

int w[N], a[N];
bool was[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", w + i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", a + i);
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 1; j <= n; j++) {
      was[j] = false;
    }
    for (int j = i - 1; j >= 0; j--) {
      if (a[j] == a[i]) {
        break;
      }
      if (was[a[j]]) {
        continue;
      }
      was[a[j]] = true;
      ans += w[a[j]];
    }
  }
  cout << ans << endl;
  return 0;
}