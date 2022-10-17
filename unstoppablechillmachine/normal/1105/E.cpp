#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;

void source() {
  int n, m;
  cin >> n >> m;
  int mask1 = 0, mask2 = 0, sz1 = m / 2, sz2 = m - sz1;
  vector<int> kek1(m), kek2(m);
  unordered_map<string, int> was;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      for (int j = 0; j < sz1; j++) {
        if ((mask1 >> j) & 1) {
          kek1[j] |= mask1 ^ (1 << j);
          kek2[j] |= mask2;
        }
      }
      for (int j = 0; j < sz2; j++) {
        if ((mask2 >> j) & 1) {
          kek1[sz1 + j] |= mask1;
          kek2[sz1 + j] |= mask2 ^ (1 << j);
        }
      }
      mask1 = mask2 = 0;
    }
    else {
      string s;
      cin >> s;
      if (was.find(s) == was.end()) {
        was[s] = ++cnt;
      }
      int cr = was[s];
      if (cr <= sz1) {
        mask1 |= 1 << (cr - 1);
      }
      else {
        mask2 |= 1 << (cr - sz1 - 1);
      }
    }
  }
  for (int j = 0; j < sz1; j++) {
    if ((mask1 >> j) & 1) {
      kek1[j] |= mask1 ^ (1 << j);
      kek2[j] |= mask2;
    }
  }
  for (int j = 0; j < sz2; j++) {
    if ((mask2 >> j) & 1) {
      kek1[sz1 + j] |= mask1;
      kek2[sz1 + j] |= mask2 ^ (1 << j);
    }
  }
  /*for (int i = 0; i < 4; i++) {
    cout << kek1[i] << ' ' << kek2[i] << '\n';
  }*/
  vector<int> dp(1 << sz1);
  for (int i = 0; i < (1 << sz1); i++) {
    bool ok = true;
    for (int j = 0; j < sz1; j++) {
      if ((i >> j) & 1) {
        dp[i] = max(dp[i], dp[i ^ (1 << j)]);
        if ((kek1[j] & i) != 0) {
          ok = false;
        }
      } 
    }
    if (ok) {
      dp[i] = __builtin_popcount(i);
    }    
  }
  int ans = 0;
  for (int i = 0; i < (1 << sz2); i++) {
    bool ok = true;
    int mask = 0;
    for (int j = 0; j < sz2; j++) {
      if ((i >> j) & 1) {
        mask |= kek1[sz1 + j];
        if ((kek2[sz1 + j] & i) != 0) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      ans = max(ans, __builtin_popcount(i) + dp[((1 << sz1) - 1) ^ mask]);
    }
  }
  cout << ans;
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}