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

int main() {
  int n;
  scanf("%d", &n);
  int x = 1;
  int cur = 1;
  while (n >= cur) {
    n -= cur;
    x++;
    cur += x;
  }
  printf("%d\n", x - 1);
  return 0;
}