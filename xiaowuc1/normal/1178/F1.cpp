#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<double, double> pdd;

const int MOD = 998244353;

ll dp[501][501];
int l[501];

ll solve(int lhs, int rhs) {
  if(lhs >= rhs) return 1;
  if(dp[lhs][rhs] >= 0) return dp[lhs][rhs];
  dp[lhs][rhs] = 0;
  int lowest = 1e9;
  int idx = -1;
  for(int i = lhs; i <= rhs; i++) {
    if(l[i] < lowest) {
      lowest = l[i];
      idx = i;
    }
  }
  ll lhsW = 0;
  ll rhsW = 0;
  for(int a = lhs; a <= idx; a++) {
    lhsW += solve(lhs, a-1) * solve(a, idx-1);
    lhsW %= MOD;
  }
  for(int b = idx; b <= rhs; b++) {
    rhsW += solve(idx+1, b) * solve(b+1, rhs);
    rhsW %= MOD;
  }
  dp[lhs][rhs] = lhsW * rhsW;
  dp[lhs][rhs] %= MOD;
  /*
  for(int a = lhs; a <= idx; a++) {
    for(int b = idx; b <= rhs; b++) {
      ll inc = solve(lhs, a-1);
      inc *= solve(a, idx-1);
      inc %= MOD;
      inc *= solve(idx+1, b);
      inc %= MOD;
      inc *= solve(b+1, rhs);
      inc %= MOD;
      dp[lhs][rhs] += inc;
    }
  }
  */
  // cout << lhs << " " << rhs << ": " << dp[lhs][rhs] << endl;
  return dp[lhs][rhs];
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      dp[i][j] = -1;
    }
  }
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    l[i]--;
  }
  cout << solve(0, n-1) << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}