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

ll dp[3];
ll ndp[3];
void solve() {
  int n, x;
  cin >> n >> x;
  ll ret = 0;
  while(n--) {
    ll inc;
    cin >> inc;
    memset(ndp, 0, sizeof(ndp));
    ndp[0] = max(0LL, dp[0] + inc);
    ndp[1] = max(dp[0] + inc * x, dp[1] + inc * x);
    ndp[2] = max(dp[0], max(dp[1], dp[2])) + inc;
    ret = max(ret, max(ndp[0], max(ndp[1], ndp[2])));
    memcpy(dp, ndp, sizeof(dp));
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}