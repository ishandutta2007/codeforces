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
#define derr if(1) cerr
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<int, pii> state;

ll l[100005];
int n;

ll getBest(ll a, ll thresh) {
  ll lhs = 0;
  ll rhs = a;
  while(lhs < rhs) {
    ll mid = (lhs+rhs)/2;
    ll val = -3*mid*mid-3*mid-1+a;
    if(val >= thresh) lhs = mid+1;
    else rhs = mid;
  }
  return lhs;
}

ll gen(ll thresh) {
  // compute num to add where derivative >= thresh
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    ret += getBest(l[i], thresh);
  }
  return ret;
}

ll ret[100005];
ll want;
void solve() {
  cin >> n >> want;
  for(int i = 0; i < n; i++) cin >> l[i];
  ll lhs = -9e18;
  ll rhs = 1e9;
  while(lhs != rhs) {
    ll mid = (lhs+rhs)/2;
    if(mid == lhs) mid++;
    if(gen(mid) >= want) lhs = mid;
    else rhs = mid-1;
  }
  vector<int> border;
  for(int i = 0; i < n; i++) {
    ret[i] = getBest(l[i], lhs+1);
    want -= ret[i];
    if(getBest(l[i], lhs) != ret[i]) border.push_back(i);
  }
  assert(sz(border) >= want);
  for(int i = 0; i < want; i++) ret[border[i]]++;
  for(int i = 0; i < n; i++) {
    cout << ret[i] << " \n"[i == n-1];
  }
}
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}