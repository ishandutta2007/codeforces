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

int a[111111];

int main() {
  int n;
  scanf("%d", &n);
  int e = 0, ans = 0;
  for (int i=0;i<n;i++) {
    int x;
    scanf("%d", &x);
    while (e > 0) {
      if ((x ^ a[e]) > ans) ans = (x ^ a[e]);
      if (x > a[e]) e--;
      else break;
    }
    a[++e] = x;
  }
  printf("%d\n", ans);
  return 0;
}