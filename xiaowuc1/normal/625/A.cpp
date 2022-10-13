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

const double PI = 2 * acos(0);
typedef long long ll;

// DID YOU FIX GLOBAL STATE

void solve() {
  ll n, a, b, c;
  scanf("%lld", &n);
  scanf("%lld", &a);
  scanf("%lld", &b);
  scanf("%lld", &c);
  ll ret1 = n/a;
  ll ret2 = max(0LL, (n-c)/(b-c));
  ret2 += (n - ret2 * (b-c)) / a;
  printf("%lld\n", max(ret1, ret2));
}

int main() {
  solve();
  return 0;
}