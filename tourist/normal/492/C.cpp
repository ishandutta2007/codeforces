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

pair <int, int> a[1234567];

int main() {
  int n, r, avg;
  scanf("%d %d %d", &n, &r, &avg);
  long long sum = avg * 1LL * n;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].second, &a[i].first);
    sum -= a[i].second;
  }
  sort(a, a + n);
  sum = max(sum, 0LL);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = min(sum, r - 0LL - a[i].second);
    ans += cur * 1LL * a[i].first;
    sum -= cur;
  }
  cout << ans << endl;
  return 0;
}