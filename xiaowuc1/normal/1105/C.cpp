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
#define derr if(0) cerr
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

ll dp[3];
ll ndp[3];
pair<int, pii> amt(int n) {
  int full = n / 3;
  pair<int, pii> ret;
  ret.f = full;
  ret.s.f = full;
  ret.s.s = full;
  n %= 3;
  if(n) {
    n--; ret.f++;
  }
  if(n) {
    n--; ret.s.f++;
  }
  return ret;
}
void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  auto lhs = amt(l-1);
  auto rhs = amt(r);
  // 1 2 0
  dp[0] = 1;
  int inc[3];
  inc[0] = rhs.s.s - lhs.s.s;
  inc[1] = rhs.f - lhs.f;
  inc[2] = rhs.s.f - lhs.s.f;
  int MOD = 1000000007;
  while(n--) {
    memset(ndp, 0, sizeof(ndp));
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        ndp[(i+j)%3] += dp[i] * inc[j];
      }
    }
    for(int i = 0; i < 3; i++) ndp[i] %= MOD;
    memcpy(dp, ndp, sizeof(ndp));
  }
  cout << dp[0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}