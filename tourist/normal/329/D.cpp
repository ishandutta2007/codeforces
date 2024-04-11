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
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=n;j++) {
      char c = '.';
      if (i % 2 == 1) {
        if (j == 1 && i == 1) c = '>'; else
        if (j == 1) c = '^'; else
        if (j == n) c = 'v'; else
        if (j <= n/3 || j % 2 == 1) c = '>';
      } else {
        if (j == 2 && i == n) c = '<'; else
        if (j == 2) c = 'v'; else
        if (j == 1) c = '^'; else
        if (j >= 2*n/3 || j % 2 == 1) c = '<';
      }
      if (n == 5 && (i == 3 || i == 5) && j == 2) c = '>';
      if (n == 5 && i == 4 && j == 4) c = '.';
      putchar(c);
    }
    printf("\n");
  }
  printf("%d %d\n", 1, 1);
  return 0;
}