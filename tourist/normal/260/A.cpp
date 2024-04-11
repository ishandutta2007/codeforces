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

int ans[111111];

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  int a, b, n;
  scanf("%d %d %d", &a, &b, &n);
  int x = a % b, i, j;
  for (i=0;i<n;i++) {
    ans[i] = -1;
    for (j=0;j<10;j++)
      if ((x*10+j) % b == 0) {
        ans[i] = j;
        x = (x*10+j) % b;
        break;
      }
    if (ans[i] == -1) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%d", a);
  for (i=0;i<n;i++) printf("%d", ans[i]);
  printf("\n");
  return 0;
}