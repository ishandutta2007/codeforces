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

int b[2000010];

int main() {
  int n;
  scanf("%d", &n);
  int m = 0;
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    for (int j = 0; j < foo; j++) {
      b[++m] = i + 1;
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int foo;
    scanf("%d", &foo);
    printf("%d\n", b[foo]);
  }
  return 0;
}