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
typedef pair<pii, int> ppiii;
const double PI = 2 * acos(0);
const int MOD = 1000000007;
const int HASH = 3137;

int goal[1000000];

void solve() {
  int n, g;
  scanf("%d%d", &n, &g);
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    goal[t]++;
  }
  ll ret = 0;
  for(int i = 0; i < 1000000; i++) {
    if(g == 0) {
      ret += goal[i] * (goal[i] - 1LL) / 2LL;
    }
    else if((g ^ i) < i) {
      ret += goal[i] * 1LL * goal[g^i];
    }
  }
  printf("%lld\n", ret);
}

int main() {
  int qq = 1;
  //int qq = 1e9;
  //int qq; scanf("%d\n", &qq);
  for(int casenum = 1; casenum <= qq; casenum++) {
    solve();
  }
  return 0;
}