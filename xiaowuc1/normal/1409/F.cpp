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
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

priority_queue<pii> dp[201];
priority_queue<pii> ndp[201];
void solve() {
  int n, k;
  string s, t;
  cin >> n >> k >> s >> t;
  dp[k].emplace(0, 0);
  for(int i = 0; i < n; i++) {
    map<int, int> thresh;
    for(int a = k; a >= 0; a--) {
      while(sz(dp[a])) {
        pii curr = dp[a].top(); dp[a].pop();
        auto it = thresh.lower_bound(curr.f);
        if(it != thresh.end() && it->s >= curr.s) continue;
        thresh[curr.f] = curr.s;
        // cull the values below that are in violation
        while(true) {
          it = thresh.lower_bound(curr.f);
          if(it == thresh.begin()) break;
          it--;
          if(it->s <= curr.s) thresh.erase(it);
          else break;
        }
        // do nothing
        {
          pii ncurr = curr;
          if(s[i] == t[1]) ncurr.f += ncurr.s;
          if(s[i] == t[0]) ncurr.s++;
          ndp[a].push(ncurr);
        }
        if(a) {
          if(t[0] == t[1] && s[i] != t[0]) {
            pii ncurr = curr;
            ncurr.f += ncurr.s++;
            ndp[a-1].push(ncurr);
          }
          else {
            if(s[i] != t[0]) {
              pii ncurr = curr;
              ncurr.s++;
              ndp[a-1].push(ncurr);
            }
            if(s[i] != t[1]) {
              pii ncurr = curr;
              ncurr.f += ncurr.s;
              ndp[a-1].push(ncurr);
            }
          }
        }
      }
    }
    for(int a = 0; a <= k; a++) {
      ndp[a].swap(dp[a]);
      assert(ndp[a].empty());
    }
  }
  int ret = 0;
  for(int a = 0; a <= k; a++) {
    if(sz(dp[a])) ret = max(ret, dp[a].top().f);
  }
  cout << ret << "\n";
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}