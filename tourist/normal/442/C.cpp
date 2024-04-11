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

const int N = 1000010;

int a[N];
pair <int, int> p[N];
int pr[N], ne[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    p[i] = make_pair(a[i], i);
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    pr[i] = i - 1;
    ne[i] = i + 1;
  }
  int low = 0, high = n - 1;
  long long ans = 0;
  for (int i = 0; i < n - 2; i++) {
    int j = p[i].second;
    if (j == low) {
      ans += p[i].first;
      low = ne[low];
      continue;
    }
    if (j == high) {
      ans += p[i].first;
      high = pr[high];
      continue;
    }
    int x = a[pr[j]];
    int y = a[ne[j]];
    if (x < y) {
      ans += x;
    } else {
      ans += y;
    }
    pr[ne[j]] = pr[j];
    ne[pr[j]] = ne[j];
  }
  cout << ans << endl;
  return 0;
}