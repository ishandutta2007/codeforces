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
typedef long long ll;

ll amt[100];

void solve() {
  amt[1] = 2;
  amt[2] = 3;
  for(int i = 3; i < 100; i++) {
    amt[i] = amt[i-1] + amt[i-2];
  }
  ll n;
  scanf("%lld", &n);
  int ret = 1;
  while(amt[ret] <= n) ret++;
  printf("%d\n", --ret);
}

int main() {
  solve();
  return 0;
}