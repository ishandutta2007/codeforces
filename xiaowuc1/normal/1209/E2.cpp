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
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
int g[13][2002];
vector<pii> silly;

int dp[1<<12];

// [shift][mask] is the best that can be done, assuming I commit to
// shifting the current column by [shift]
int shiftDP[12][1<<12];

void realsolve() {
  int r, c;
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> g[i][j];
    }
  }
  silly.clear();
  for(int j = 0; j < c; j++) {
    int maxv = 0;
    for(int i = 0; i < r; i++) {
      maxv = max(maxv, g[i][j]);
    }
    silly.push_back({-maxv, j});
  }
  sort(silly.begin(), silly.end());
  c = min(c, r);
  memset(dp, 0, sizeof(dp));
  for(int j = 0; j < c; j++) {
    for(int inc = 0; inc < r; inc++) {
      memcpy(shiftDP[inc], dp, sizeof(dp));
      for(int mask = 0; mask < (1<<r); mask++) {
        for(int i = 0; i < r; i++) {
          if(mask&(1<<i)) continue;
          shiftDP[inc][mask|(1<<i)] = max(shiftDP[inc][mask|(1<<i)], shiftDP[inc][mask] + g[(inc+i)%r][silly[j].second]);
        }
      }
    }
    for(int mask = 0; mask < (1<<r); mask++) {
      for(int i = 0; i < r; i++) {
        dp[mask] = max(dp[mask], shiftDP[i][mask]);
      }
    }
  }
  cout << dp[(1<<r)-1] << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}