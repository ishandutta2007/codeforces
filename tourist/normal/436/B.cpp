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

int ans[1234567];
char foo[1234567];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int j = 0; j < m; j++) {
    ans[j] = 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", foo);
    for (int j = 0; j < m; j++) {
      if (foo[j] == 'L') {
        if (j - i >= 0) {
          ans[j - i]++;
        }
      }
      if (foo[j] == 'R') {
        if (j + i < m) {
          ans[j + i]++;
        }
      }
      if (foo[j] == 'U') {
        if (i % 2 == 0) {
          ans[j]++;
        }
      }
    }
  }
  for (int j = 0; j < m - 1; j++) {
    printf("%d ", ans[j]);
  }
  printf("%d\n", ans[m - 1]);
  return 0;
}