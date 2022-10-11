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

int dp[105][3];

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
    if(k&1) {
      dp[i][1] = 1 + max(dp[i-1][0], dp[i-1][2]);
    }
    if(k&2) {
      dp[i][2] = 1 + max(dp[i-1][0], dp[i-1][1]);
    }
  }
  printf("%d\n", n - max(dp[n][0], max(dp[n][1], dp[n][2])));
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