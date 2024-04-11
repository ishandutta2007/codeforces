#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
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
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
#define derr if(0) cerr
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;


const int MOD = 1000000007;
void slow() {
  map<ll, ll> dp;
  map<ll, ll> ndp;
  ll x;
  for(auto out: dp) {
    ndp[out.f+x] += out.s;
    ndp[out.f+x] %= MOD;
    if(out.f) {
      ndp[x] += out.s;
      ndp[x] %= MOD;
    }
  }
  dp.swap(ndp);
}
ll l[200005];
ll p[200005];
void rsolve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    p[i+1] = p[i] + l[i];
  }
  map<ll, ll> dp; // prefix sum of a to the thing
  dp[0] = 1;
  ll frame = 0;
  ll tot = 1;
  for(int i = 0; i < n; i++) {
    ll zerocnt = dp[frame];
    ll zeroinc = (tot - zerocnt + MOD) % MOD;
    frame += l[i];
    dp[-l[i]+frame] += zeroinc;
    dp[-l[i]+frame] += MOD;
    tot += zeroinc;
  }
  ll ret = 0;
  for(auto out: dp) {
    ret += out.s;
    ret %= MOD;
  }
  cout << ret << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

// !editcommand?
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