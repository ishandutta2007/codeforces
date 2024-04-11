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

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int ans = 0, bad = 0;
  while (a > 0) {
    ans++;
    a--;
    bad++;
    if (bad == b) {
      bad = 0;
      a++;
    }
  }
  printf("%d\n", ans);
  return 0;
}