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

void rsolve() {
  ll n, g, b;
  cin >> n >> g >> b;
  ll lhs = n;
  ll rhs = 1e18;
  while(lhs < rhs) {
    ll mid = (lhs+rhs)/2;
    ll cand = (mid / (g+b)) * g;
    cand += min(g, (mid % (g+b)));
    if(2*cand >= n) rhs = mid;
    else lhs = mid+1;
  }
  cout << lhs << "\n";
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