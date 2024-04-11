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

int backup[42], b[42], c[42], a[1111111];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int j=0;j<30;j++) c[j] = 0;
  for (int i=0;i<n;i++) {
    scanf("%d", a+i);
    for (int j=0;j<30;j++)
      if (a[i] & (1 << j)) c[j]++;
  }
  for (int j=0;j<30;j++) b[j] = 0;
  for (int i=0;i<m;i++) {
    int foo;
    scanf("%d", &foo);
    b[foo]++;
  }
  for (int j=0;j<30;j++) backup[j] = b[j];
  int ll = 0, rr = m;
  while (ll < rr) {
    int mid = (ll+rr+1) >> 1;
    for (int j=0;j<=30;j++) b[j] = 0;
    int need = mid;
    for (int j=0;j<30;j++)
      if (backup[j] <= need) {
        b[j] = backup[j];
        need -= backup[j];
      } else {
        b[j] = need;
        need = 0;
        break;
      }
    for (int j=0;j<30;j++) {
      int mn = c[j];
      if (b[j] < mn) mn = b[j];
      b[j] -= mn;
      b[j+1] += (b[j]+1)/2;
    }
    if (b[30] == 0) ll = mid;
    else rr = mid-1;
  }
  printf("%d\n", ll);
  return 0;
}