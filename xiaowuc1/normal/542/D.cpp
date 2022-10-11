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

map<ll, set<ll>> dp;

ll n;
ll fpow(ll b, ll e) {
  ll r = 1;
  for(int i = 0; i < e; i++) {
    if(n/b < r) return n+1;
    r *= b;
  }
  return r;
}

bool isprime(ll x) {
  if(x < 2) return false;
  int rhs = sqrt(x);
  for(int i = 2; i <= rhs; i++) {
    if(x%i==0) return false;
  }
  return true;
}

void upd(ll x) {
  // write x as 1 + p^a
  if(isprime(x-1)) dp[x-1].insert(x);
  for(int a = 2; fpow(2, a) <= x; a++) {
    int lhs = 2;
    int rhs = 1e6;
    while(lhs <= rhs) {
      int mid = (lhs+rhs)/2;
      ll midr = fpow(mid, a);
      if(midr == x-1) {
        if(isprime(mid)) {
          dp[mid].insert(x);
        }
        break;
      }
      if(midr > x-1) rhs = mid-1;
      else lhs = mid+1;
    }
  }
}

void solve() {
  cin >> n;
  vector<ll> divs;
  for(ll i = 1; i * i <= n; i++) {
    if(n%i) continue;
    divs.push_back(i);
    upd(i);
    if(i*i != n) divs.push_back(n/i);
    upd(n/i);
  }
  sort(all(divs));
  vector<ll> ret(sz(divs));
  ret[0] = 1;
  for(auto out: dp) {
    vector<ll> nret(sz(ret));
    for(int i = 0; i < sz(ret); i++) {
      if(ret[i] == 0) continue;
      nret[i] += ret[i];
      for(ll cand: out.second) {
        if(divs[i] <= n / cand) {
          int idx = lower_bound(all(divs), divs[i] * cand) - divs.begin();
          if(divs[idx] == divs[i] * cand) nret[idx] += ret[i];
        }
        else {
          break;
        }
      }
    }
    ret = nret;
  }
  cout << ret.back() << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}