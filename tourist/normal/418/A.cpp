#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k > (n - 1) / 2) {
    printf("%d\n", -1);
  } else {
    printf("%d\n", n * k);
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < k; j++) printf("%d %d\n", i, (i + j) % n + 1);
  }
  return 0;
}