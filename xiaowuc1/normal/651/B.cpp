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

void solve() {
  map<int, int> dp;
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    dp[t]++;
  }
  int ret = 0;
  while(!dp.empty()) {
    int now = dp.begin()->first;
    if(--dp[now] == 0) dp.erase(now);
    while(true) {
      map<int, int>::iterator it = dp.upper_bound(now);
      if(it == dp.end()) break;
      ret++;
      if(--dp[it->first] == 0) {
        dp.erase(it->first);
      }
      now = it->first;
    }
  }
  printf("%d\n", ret);
}

int main() {
  /*
  freopen("integral.in","r",stdin);
  freopen("integral.out","w",stdout);
  */
  int qq = 1;
  //int qq = 1e9;
  //int qq; scanf("%d\n", &qq);
  for(int casenum = 1; casenum <= qq; casenum++) {
    solve();
  }
  return 0;
}