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
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

const double PI = 2 * acos(0);
typedef long long ll;
typedef pair<int, int> pii;

int solve(ll r) {
  int ret = 0;
  for(int i = 2; i <= 62; i++) {
    ll amt = (1LL << i) - 1;
    for(int a = 0; a + 1 < i; a++) {
      if((amt ^ (1LL << a)) <= r) {
        ret++;
      }
    }
  }
  return ret;
}

void solve() {
  ll a, b;
  scanf("%lld %lld", &a, &b);
  printf("%d\n", solve(b) - solve(a-1));
}

int main() {
  solve();
  return 0;
}