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

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  int ret = n;
  while(m--) {
    int lhs, rhs;
    scanf("%d%d", &lhs, &rhs);
    ret = min(ret, rhs - lhs + 1);
  }
  printf("%d\n", ret);
  for(int i = 0; i < n; i++) {
    printf("%d", i%ret);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}