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

// remember you may need to clear state

ll rsolve(ll a, ll b, ll x, ll y, ll n) {
  ll dec = min(a-x, n);
  a -= dec;
  n -= dec;
  dec = min(b-y, n);
  b -= dec;
  return a*b;
}

void rsolve() {
  ll a, b, x, y, n;
  cin >> a >> b >> x >> y >> n;
  cout << min(rsolve(a, b, x, y, n), rsolve(b, a, y, x, n)) << "\n";
}

void solve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    rsolve();
  }
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