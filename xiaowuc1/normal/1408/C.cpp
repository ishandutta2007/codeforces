#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<double>> matrix;

void travel(vector<double>& dp, vector<double>& d, int n) {
  dp.resize(n+1);
  double last = 0;
  for(int i = 0; i < n; i++) {
    dp[i+1] = dp[i] + (d[i] - last) / (i+1);
    last = d[i];
  }
}

double l[1000005];
void rsolve() {
  int n, len;
  cin >> n >> len;
  vector<double> lhsd(n);
  for(int i = 0; i < n; i++) cin >> lhsd[i];
  vector<double> rhsd = lhsd;
  for(int i = 0; i < n; i++) rhsd[i] = len - lhsd[i];
  reverse(all(rhsd));
  vector<double> lhst, rhst;
  travel(lhst, lhsd, n);
  travel(rhst, rhsd, n);
  double ret = 1e9;
  for(int i = 0; i <= n; i++) {
    double distleft = i == n ? len : lhsd[i];
    if(i) distleft -= lhsd[i-1];
    double big = lhst[i];
    double small = rhst[n-i];
    double cand = max(big, big + (distleft - (big - small) * (n-i+1)) / (n+2.));
    ret = min(ret, cand);
  }
  cout << fixed << setprecision(12) << ret << "\n";
}

void solve() { 
  int t;
  cin >> t;
  while(t--) rsolve();
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