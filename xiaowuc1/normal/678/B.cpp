#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

const double PI = 2 * acos(0);

bool leap(int n) {
  return n%400 == 0 || (n%100 != 0 && n%4 == 0);
}

void solve() {
  int n;
  scanf("%d", &n);
  int ret = n+1;
  int add = leap(n) ? 2 : 1;
  while(add != 0 || leap(n) != leap(ret)){
    add += leap(ret) ? 2 : 1;
    add %= 7;
    ret++;
  }
  printf("%d\n", ret);
}

int main() {
  solve();
  return 0;
}