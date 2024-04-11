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

int a[42];
int n;
int sum, total;

void dfs(int op) {
  if (op == 0) {
    total++;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (a[i] > a[j]) {
          sum++;
        }
      }
    }
    return;
  }
  for (int ll = 1; ll <= n; ll++) {
    for (int rr = ll; rr <= n; rr++) {
      reverse(a + ll, a + rr + 1);
      dfs(op - 1);
      reverse(a + ll, a + rr + 1);
    }
  }
}

int main() {
  int k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sum = 0;
  total = 0;
  dfs(k);
  printf("%.17f\n", 1.0 * sum / total);
  return 0;
}