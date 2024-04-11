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
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

const int MOD = 1000000007;

string s[100005];
string sRev[100005];
char buf[100005];

int cost[100005];
ll dp[100005][2];

void solve() {
  int n;
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &cost[i]);
  }
  gets(buf);
  for(int i = 0; i < n; i++) {
    gets(buf);
    s[i] = string(buf);
    sRev[i] = string(buf);
    reverse(sRev[i].begin(), sRev[i].end());
  }
  dp[0][1] = cost[0];
  for(int i = 1; i < n; i++) {
    dp[i][0] = 1e18;
    dp[i][1] = 1e18;
    if(s[i] >= s[i-1]) {
      dp[i][0] = min(dp[i][0], dp[i-1][0]);
    }
    if(s[i] >= sRev[i-1]) {
      dp[i][0] = min(dp[i][0], dp[i-1][1]);
    }
    if(sRev[i] >= s[i-1]) {
      dp[i][1] = min(dp[i][1], dp[i-1][0] + cost[i]);
    }
    if(sRev[i] >= sRev[i-1]) {
      dp[i][1] = min(dp[i][1], dp[i-1][1] + cost[i]);
    }
  }
  ll ret = min(dp[n-1][0], dp[n-1][1]);
  if(ret == 1e18) ret = -1;
  printf("%lld\n", ret);
}

int main() {
  solve();
  return 0;
}