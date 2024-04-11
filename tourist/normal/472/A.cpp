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
  if (n % 2 == 0) printf("%d %d\n", 4, n - 4);
  else printf("%d %d\n", 9, n - 9);
  return 0;
}