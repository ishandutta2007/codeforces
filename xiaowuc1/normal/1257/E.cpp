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
typedef long double ld;

int val[200005];
int dp[3];
int ndp[3];
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int n = a+b+c;
  while(a--) {
    int x;
    cin >> x;
    val[x] = 0;
  }
  while(b--) {
    int x;
    cin >> x;
    val[x] = 1;
  }
  while(c--) {
    int x;
    cin >> x;
    val[x] = 2;
  }
  for(int i = 1; i <= n; i++) {
    memcpy(ndp, dp, sizeof(dp));
    for(int x = 0; x <= val[i]; x++) {
      ndp[val[i]] = max(ndp[val[i]], dp[x] + 1);
    }
    memcpy(dp, ndp, sizeof(dp));
  }
  cout << n-max(dp[0], max(dp[1], dp[2])) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}