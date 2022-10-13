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
typedef pair<ll, ll> pll;

const ll INF = 1LL << 40;

const int MOD = 998244353;

ll dp[2001];
ll ndp[2001];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  // n bricks, m colors, k matches
  dp[0] = m;
  for(int qq = 1; qq < n; qq++) {
    memset(ndp, 0, sizeof(ndp));
    for(int x = 0; x < n; x++) {
      ndp[x] += dp[x];
      ndp[x+1] += dp[x] * (m-1);
      ndp[x] %= MOD;
      ndp[x+1] %= MOD;
    }
    memcpy(dp, ndp, sizeof(dp));
  }
  cout << dp[k] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}