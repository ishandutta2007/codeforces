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

int origColor[105];
int colorCost[105][105];

ll dp[105][105];

void solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &origColor[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= m; j++) {
      scanf("%d", &colorCost[i][j]);
    }
  }
  for(int i = 0; i <= k; i++) {
    for(int j = 0; j <= m; j++) {
      dp[i][j] = 1e18;
    }
  }
  dp[0][0] = 0;
  for(int i = 0; i < n; i++) {
    ll nextDP[105][105];
    for(int a = 0; a <= k; a++) {
      for(int b = 0; b <= m; b++) {
        nextDP[a][b] = 1e18;
      }
    }
    for(int j = 1; j <= m; j++) {
      if(origColor[i] != 0 && origColor[i] != j) continue;
      for(int firstColor = 0; firstColor <= m; firstColor++) {
        for(int numPartition = 0; numPartition <= k; numPartition++) {
          int nextColor = j;
          int nextPartition = numPartition;
          if(firstColor != j) nextPartition++;
          ll cost = dp[numPartition][firstColor];
          if(origColor[i] == 0) {
            cost += colorCost[i][j];
          }
          nextDP[nextPartition][nextColor] = min(nextDP[nextPartition][nextColor], cost);
        }
      }
    }
    for(int a = 0; a <= k; a++) {
      for(int b = 0; b <= m; b++) {
        dp[a][b] = nextDP[a][b];
      }
    }
  }
  ll ret = 1e18;
  for(int i = 1; i <= m; i++) {
    ret = min(ret, dp[k][i]);
  }
  if(ret == 1e18) ret = -1;
  printf("%lld\n", ret);
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