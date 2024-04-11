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

pii dp[1 << 21];
int l[1000000];

inline void mergeIn(pii& x, int y) {
  if(y == -1) return;
  if(y == x.first || y == x.second) return;
  if(x.second == -1) {
    x.second = y;
    return;
  }
  else if(x.first == -1) {
    x.first = y;
    if(x.first > x.second) swap(x.first, x.second);
    return;
  }
  if(y > x.first) {
    x.first = y;
    if(x.first > x.second) swap(x.first, x.second);
    return;
  }
}

void solve() {
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  for(int i = n-1; i >= 0; i--) {
    mergeIn(dp[l[i]], i);
  }
  for(int mask = (1 << 21)-1; mask >= 0; mask--) {
    for(int i = 0; i < 21; i++) {
      if(mask&(1<<i)) {
        mergeIn(dp[mask ^ (1<<i)], dp[mask].first);
        mergeIn(dp[mask ^ (1<<i)], dp[mask].second);
      }
    }
  }
  int ret = 0;
  for(int bit = 20; bit >= 0; bit--) {
    int cand = ret | (1 << bit);
    bool can = false;
    for(int i = 0; i < n-2; i++) {
      int have = cand & (l[i]);
      if(dp[cand^have].first > i) can = true;
    }
    if(can) ret = cand;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}