#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

int next[1111], a[1111], t[1111];
bool can[1111];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i=1;i<=n;i++) next[i] = 0;
  for (int i=1;i<=n;i++) {
    scanf("%d", a+i);
    next[a[i]] = i;
  }
  int x = 0, kt = 0;
  for (int i=1;i<=n;i++)
    if (a[i] == 0) {
      int p = i, len = 1;
      bool here = false;
      if (p == k) x = 1, here = true;
      while (next[p] != 0) {
        p = next[p];
        len++;
        if (p == k) x = len, here = true;
      }
      if (!here) t[kt++] = len;
    }
  for (int i=1;i<=n;i++) can[i] = false;
  can[x] = true;
  for (int i=0;i<kt;i++)
    for (int j=n;j>=1;j--)
      if (can[j]) can[j+t[i]] = true;
  for (int i=1;i<=n;i++)
    if (can[i]) printf("%d\n", i);
  return 0;
}