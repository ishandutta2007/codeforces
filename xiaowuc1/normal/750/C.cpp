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

void die() {
  cout << "Impossible\n";
  exit(0);
}

void solve() {
  int n;
  cin >> n;
  ll lhs = -1e18;
  ll rhs = 1e18;
  while(n--) {
    int delta, d;
    cin >> delta >> d;
    if(d == 1) {
      if(rhs < 1900) die();
      lhs = max(lhs, 1900LL);
      lhs += delta;
      rhs += delta;
    }
    else {
      if(lhs > 1899) die();
      rhs = min(rhs, 1899LL);
      lhs += delta;
      rhs += delta;
    }
  }
  if(rhs > 1e9) cout << "Infinity\n";
  else cout << rhs << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}