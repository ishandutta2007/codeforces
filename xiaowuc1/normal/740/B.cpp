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

typedef long long ll;
typedef pair<int, int> pii;
const double PI = 2 * acos(0);
const int MOD = 1000000007;

int n;
int amt[105];

void solve() {
  int m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &amt[i]);
  }
  ll ret = 0;
  while(m--) {
    int lhs, rhs;
    scanf("%d%d", &lhs, &rhs);
    lhs--;
    rhs--;
    int inc = 0;
    for(int i = lhs; i <= rhs; i++) {
      inc += amt[i];
    }
    ret += max(inc, 0);
  }
  printf("%lld\n", ret);
}

int main() {
  solve();
  return 0;
}