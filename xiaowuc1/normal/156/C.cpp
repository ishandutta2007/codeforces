#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

ll dp[2605][2605];
const int MOD = 1000000007;

ll solve(int n, int k) {
  if(n == 0) return k == 0 ? 1 : 0;
  if(dp[n][k] >= 0) return dp[n][k];
  ll ret = 0;
  for(int i = 0; i < 26 && i <= k; i++) {
    ret += solve(n-1, k-i);
    ret %= MOD;
  }
  dp[n][k] = ret;
  return ret;
}

void rsolve() {
  string s;
  cin >> s;
  int v = 0;
  for(int i = 0; i < sz(s); i++) {
    v += s[i] - 'a';
  }
  cout << solve(sz(s), v)-1 << '\n';
}

void solve() {
  memset(dp, -1, sizeof(dp));
  int t;
  cin >> t;
  while(t--) rsolve();
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points
// are you not using modint when you should

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}