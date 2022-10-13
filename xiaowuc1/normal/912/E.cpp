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

vector<ll> gen(vector<int>& s) {
  vector<ll> v;
  v.push_back(1);
  for(int scale: s) {
    vector<ll> nv;
    for(ll out: v) {
      while(true) {
        nv.push_back(out);
        if(scale <= 1e18 / out) {
          out *= scale;
        }
        else {
          break;
        }
      }
    }
    v = nv;
  }
  sort(all(v));
  return v;
}

ll gen(ll mid, vector<ll>& av, vector<ll>& bv) {
  ll cand = 0;
  int rhsi = sz(bv)-1;
  for(ll out: av) {
    while(rhsi >= 0) {
      if(out > mid / bv[rhsi]) rhsi--;
      else if(out * bv[rhsi] <= mid) break;
      else rhsi--;
    }
    if(rhsi < 0) break;
    cand += rhsi + 1;
  }
  // cerr << mid << ": " << cand << endl;
  return cand;
}

void solve() {
  int n;
  cin >> n;
  vector<int> lhs, rhs;
  ll lhsp = 1, rhsp = 1;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if(lhsp <= rhsp) {
      lhs.push_back(a);
      lhsp *= a;
    }
    else {
      rhs.push_back(a);
      rhsp *= a;
    }
  }
  ll vv;
  cin >> vv;
  vector<ll> av = gen(lhs);
  vector<ll> bv = gen(rhs);
  ll retl = 1;
  ll retr = 1e18;
  while(retl < retr) {
    ll mid = (retl+retr)/2;
    if(gen(mid, av, bv) >= vv) retr = mid;
    else retl = mid+1;
  }
  cout << retl << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}