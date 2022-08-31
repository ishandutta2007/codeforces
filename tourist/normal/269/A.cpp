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

int n, i, a, b, ans;

int main() {
  scanf("%d", &n);
  ans = 0;
  for (i=0;i<n;i++) {
    scanf("%d %d", &a, &b);
    if (a+1 > ans) ans = a+1;
    b--;
    while (b > 0) {
      a++;
      b >>= 2;
    }
    if (a > ans) ans = a;
  }               
  printf("%d\n", ans);
  return 0;
}