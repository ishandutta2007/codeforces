#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
#define derr if(0) cerr
// END NO SAD

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template<class T>
bool updmin(T& a, T b) {
  if(b < a) {
    a = b;
    return true;
  }
  return false;
}
template<class T>
bool updmax(T& a, T b) {
  if(b > a) {
    a = b;
    return true;
  }
  return false;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

void solve() {
  int n;
  cin >> n;
  vector<vector<ll>> pref(n+1);
  auto getrect = [&](int xl, int yl, int xr, int yr) -> ll {
    if(xr < xl || yr < yl) return 0;
    return pref[xr+1][yr+1] - pref[xl][yr+1] - pref[xr+1][yl] + pref[xl][yl];
  };
  auto getcost = [&](int lhs, int rhs) -> ll {
    if(lhs > rhs) return 0;
    return getrect(lhs, 0, rhs, lhs-1) + getrect(lhs, rhs+1, rhs, n-1);
  };
  for(int i = 0; i < sz(pref); i++) pref[i].assign(n+1, 0);
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
    cin >> pref[i][j];
    pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
  }
  vector<vector<pair<ll, int>>> dp(n);
  for(auto& x: dp) x.assign(n, mp(1e18, -1));
  vector<int> par(n, -1);
  auto dfs = y_combinator([&](auto self, int lhs, int rhs, bool doit) -> pair<ll, int> {
    if(lhs > rhs) return mp(0, -1);
    if(lhs == rhs) return mp(0, lhs);
    if(doit) {
      int used = -1;
      for(int i = lhs; i <= rhs; i++) {
        ll cost = self(lhs, i-1, false).f + self(i+1, rhs, false).f + getcost(lhs, i-1) + getcost(i+1, rhs);
        if(cost < dp[lhs][rhs].f || (used == -1 && cost == dp[lhs][rhs].f)) {
          dp[lhs][rhs] = mp(cost, i);
          used = i;
        }
      }
      assert(used >= 0);
      if(used != lhs) par[self(lhs, used-1, true).s] = used;
      if(used != rhs) par[self(used+1, rhs, true).s] = used;
      return dp[lhs][rhs];
    }
    if(dp[lhs][rhs].s >= 0) return dp[lhs][rhs];
    for(int i = lhs; i <= rhs; i++) {
      ll cost = self(lhs, i-1, false).f + self(i+1, rhs, false).f + getcost(lhs, i-1) + getcost(i+1, rhs);
      if(cost < dp[lhs][rhs].f) {
        dp[lhs][rhs] = mp(cost, i);
      }
    }
    return dp[lhs][rhs];
  });
  dfs(0, n-1, true);
  for(int i = 0; i < n; i++) cout << par[i]+1 << " \n"[i == n-1];
}

// what would chika do
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}