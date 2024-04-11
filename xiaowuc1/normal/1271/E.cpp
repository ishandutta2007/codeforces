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

ll solveOdd(ll n, ll k) {
  ll scale = 1;
  ll amt = 0;
  while(true) {
    if(amt + scale >= k) {
      ll rhs = k - amt - 1;
      // scale * x + rhs == n
      ll cand = (n-rhs) / scale;
      return cand;
    }
    amt += scale;
    scale *= 2;
  }
}

ll solveEven(ll n, ll k) {
  ll scale = 1;
  ll amt = 0;
  while(true) {
    if(amt + 2*scale >= k) {
      ll rhs = k - amt - 1;
      // scale * x + rhs == n
      ll cand = (n-rhs) / scale;
      if(cand%2) cand--;
      return cand;
    }
    amt += 2*scale;
    scale *= 2;
  }
}

void solve() {
  ll n, k;
  cin >> n >> k;
  ll ret = 1;
  ret = max(ret, solveOdd(n, k));
  ret = max(ret, solveEven(n, k));
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}