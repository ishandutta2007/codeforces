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

using namespace std;

int a[4444444], b[4444444];

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0;i<2*n;i++) {
    char ch = getchar();
    while (ch != '0' && ch != '1') ch = getchar();
    a[i] = ch-48;
  }
  for (int i=0;i<2*n;i++) {
    char ch = getchar();
    while (ch != '0' && ch != '1') ch = getchar();
    b[i] = ch-48;
  }
  int k11 = 0, k01 = 0, k10 = 0, k00 = 0;
  for (int i=0;i<2*n;i++) {
    if (a[i] == 1 && b[i] == 1) k11++;
    if (a[i] == 1 && b[i] == 0) k10++;
    if (a[i] == 0 && b[i] == 1) k01++;
    if (a[i] == 0 && b[i] == 0) k00++;
  }
  int bal = 0;
  for (int i=1;i<=2*n;i++) {
    if (k11 > 0) {
      if (i & 1) bal++;
      else bal--;
      k11--;
    } else
    if (k10 > 0) {
      if (i & 1) bal++;
      else bal = bal;
      k10--;
    } else
    if (k01 > 0) {
      if (i & 1) bal = bal;
      else bal--;
      k01--;
    } else {
      k00--;
    }
  }
  if (bal > 0) puts("First"); else
  if (bal < 0) puts("Second");
  else puts("Draw");
  return 0;
}