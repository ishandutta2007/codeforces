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

int a[1234];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int mx = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > mx) mx = a[i];
  for (int u = 1; u <= mx; u++) {
    for (int i = 0; i < n; i++) {
      if (a[i] >= u) putchar('P');
      if (i < n - 1) putchar('R'); else {
        for (int j = 0; j < n - 1; j++) putchar('L');
      }
    }
  }
  printf("\n");
  return 0;
}