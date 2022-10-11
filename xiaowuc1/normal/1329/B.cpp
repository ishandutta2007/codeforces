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
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;

ll count(ll n, ll v) {
  // return the number of numbers with highest bit equal to n <= v
  assert(v >= n);
  ll rhs = 2 * n;
  return min(v+1, rhs) - n;
}

void rsolve() {
  ll d, m;
  cin >> d >> m;
  ll ret = 0;
  ll v = 1;
  while(v <= d) {
    ll amt = count(v, d);
    ll inc = ret + 1;
    ret += inc * amt;
    ret %= m;
    v *= 2;
  }
  cout << ret << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}