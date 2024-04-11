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

int b[123456];

int main() {
  int n;
  scanf("%d", &n);
  vector <int> a;
  int x = 0, y = 0;
  while (n--) {
    int foo;
    scanf("%d", &foo);
    for (int i = 0; i < foo; i++) {
      scanf("%d", b + i);
    }
    for (int i = 0; i < foo / 2; i++) {
      x += b[i];
      y += b[foo - (foo / 2) + i];
    }
    if (foo % 2 == 1) {
      a.push_back(b[foo / 2]);
    }
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (int i = 0; i < (int)a.size(); i++)
    if (i % 2 == 0) x += a[i];
    else y += a[i];
  printf("%d %d\n", x, y);
  return 0;
}