#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
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

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;

void ans(int x) {
  printf("! %d\n", x); fflush(stdout);
  exit(0);
}

int question(int x) {
  printf("? %d\n", x); fflush(stdout);
  int ret; scanf("%d", &ret); return ret;
}

const int MOD = 1000003;
int dp[11][MOD];
void solve() {
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i <= 10; i++) {
    dp[10][i] = question(i);
  }
  for(int x = 9; x >= 0; x--) {
    for(int i = 0; i + 1 < MOD; i++) {
      if(dp[x+1][i+1] == -1) break;
      dp[x][i] = dp[x+1][i+1] - dp[x+1][i];
      if(dp[x][i] < 0) dp[x][i] += MOD;
    }
  }
  for(int x = 10; x >= 0; x--) {
    set<int> s;
    for(int i = 0; i < MOD; i++) {
      if(dp[x][i] < 0) continue;
      s.insert(dp[x][i]);
    }
    if(sz(s) > 1) continue;
    for(int i = 0; i < MOD; i++) dp[x][i] = *s.begin();
    for(int y = x+1; y <= 10; y++) {
      for(int i = 1; i < MOD; i++) {
        dp[y][i] = dp[y-1][i-1] + dp[y][i-1];
        if(dp[y][i] >= MOD) dp[y][i] -= MOD;
      }
    }
    break;
  }
  for(int i = 0; i < MOD; i++) {
    if(dp[10][i] == 0) ans(i);
  }
  ans(-1);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL); cout.tie(NULL);
  solve();
}