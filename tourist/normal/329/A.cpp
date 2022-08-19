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

char a[111][111];

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0;i<n;i++) scanf("%s", a[i]);
  bool row = false, col = false;
  for (int i=0;i<n;i++) {
    row = true;
    for (int j=0;j<n;j++)
      if (a[i][j] != 'E') row = false;
    if (row) break;
  }
  for (int j=0;j<n;j++) {
    col = true;
    for (int i=0;i<n;i++)
      if (a[i][j] != 'E') col = false;
    if (col) break;
  }
  if (row && col) printf("%d\n", -1); else
  if (!row) {
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        if (a[i][j] != 'E') {
          printf("%d %d\n", i+1, j+1);
          break;
        }
  } else {
    for (int j=0;j<n;j++)
      for (int i=0;i<n;i++)
        if (a[i][j] != 'E') {
          printf("%d %d\n", i+1, j+1);
          break;
        }
  }
  return 0;
}