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

using namespace std;

const int N = 1000010;

pair <int, int> a[N];
int b[N], ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &(a[i].first));
    a[i].second = i;
  }
  sort(a, a + n);
  b[0] = a[0].first;
  for (int i = 1; i < n; i++) {
    b[i] = a[i].first;
    if (b[i] < b[i - 1] + 1) b[i] = b[i - 1] + 1;
  }
  for (int i = 0; i < n; i++) ans[a[i].second] = b[i];
  for (int i = 0; i < n - 1; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[n - 1]);
  return 0;
}