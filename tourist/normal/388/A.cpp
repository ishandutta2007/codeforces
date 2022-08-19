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

const int co = 1000;

int a[co + 10];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int used = 0, ans = 0;
  while (used < n) {
    ans++;
    int h = 0;
    for (int i = 0; i < n; i++)
      if (a[i] >= h) {
        a[i] = -1;
        h++;
        used++;
      }
  }
  printf("%d\n", ans);
  return 0;
}