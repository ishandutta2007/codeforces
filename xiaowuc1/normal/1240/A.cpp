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

ll can(vector<ll>& v, ll x, ll a, ll y, ll b, int sell) {
  ll freqBoth = a * b / __gcd(a, b);
  ll bothDisc = sell / freqBoth;
  ll aOnly = sell / a - bothDisc;
  ll bOnly = sell / b - bothDisc;
  ll ret = 0;
  for(int i = 0; i < sz(v); i++) {
    if(bothDisc == 0 && aOnly == 0 && bOnly == 0) break;
    if(bothDisc) {
      bothDisc--;
      ret += v[i] / 100 * (x+y);
      continue;
    }
    if(aOnly == 0) {
      assert(bOnly > 0);
      bOnly--;
      ret += v[i] / 100 * y;
      continue;
    }
    if(bOnly == 0 || (x > y && aOnly > 0)) {
      assert(aOnly > 0);
      aOnly--;
      ret += v[i] / 100 * x;
      continue;
    }
    assert(bOnly > 0);
    bOnly--;
    ret += v[i] / 100 * y;
  }
  return ret;
}

void realsolve() {
  int n;
  vector<ll> v;
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  ll x, a, y, b, k;
  cin >> x >> a >> y >> b >> k;
  int lhs = 1;
  int rhs = n+1;
  while(lhs != rhs) {
    int mid = (lhs+rhs)/2;
    if(can(v, x, a, y, b, mid) >= k) rhs = mid;
    else lhs = mid+1;
  }
  if(lhs > n) lhs = -1;
  cout << lhs << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}