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

int a[1234567];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  a[0] = 1;
  int low = 1, high = 1;
  for (int i = 1; i <= k; i++) {
    if (i % 2 == 1) {
      a[i] = ++high;
    } else {
      a[i] = --low;
    }
  }
  for (int i = k + 1; i < n; i++) {
    if (a[k] == low) {
      a[i] = a[i - 1] - 1;
    } else {
      a[i] = a[i - 1] + 1;
    }
  }
  int smallest = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] < smallest) {
      smallest = a[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    printf("%d", a[i] - smallest + 1);
  }
  printf("\n");
  return 0;
}