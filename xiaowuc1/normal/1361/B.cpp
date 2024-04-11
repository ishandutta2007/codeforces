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

const int MOD = 1000000007;
ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r*=b;
      r%=m;
    }
    b*=b;
    b%=m;
    e/=2;
  }
  return r;
}

void rsolve() {
  int n, p;
  cin >> n >> p;
  if(p == 1) {
    int ret = n%2;
    while(n--) {
      int x;
      cin >> x;
    }
    cout << ret << "\n";
    return;
  }
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(all(v));
  while(true) {
    // prune all top
    while(sz(v) >= 2 && v.back() == v[sz(v)-2]) {
      v.pop_back();
      v.pop_back();
    }
    if(sz(v) == 0) break;
    // can you prune top?
    ll need = p;
    int expect = v.back()-1;
    bool good = false;
    for(int i = sz(v)-2; i >= 0; i--) {
      assert(expect >= v[i]);
      while(expect > v[i]) {
        expect--;
        need *= p;
        if(need > i) break;
      }
      if(need > i) break;
      assert(expect == v[i]);
      if(--need == 0) {
        good = true;
        // kill everything up to and including i
        while(i < sz(v)) v.pop_back();
        break;
      }
    }
    if(!good) break;
  }
  if(sz(v) == 0) {
    cout << "0\n";
    return;
  }
  ll ret = modpow(p, v.back(), MOD);
  v.pop_back();
  for(int out: v) {
    ret -= modpow(p, out, MOD);
    if(ret < 0) ret += MOD;
  }
  cout << ret << "\n";
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}