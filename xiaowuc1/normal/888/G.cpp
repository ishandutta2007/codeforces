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

int exactlyone(vector<int>& v1, vector<int>& v2, int k) {
  assert(sz(v1));
  assert(sz(v2));
  if(k < 0) return 0;
  sort(all(v1));
  sort(all(v2));
  {
    int a = 0;
    int b = 0;
    while(a < sz(v1) && b < sz(v2)) {
      if(v1[a] == v2[b]) return 0;
      if(v1[a] < v2[b]) a++;
      else b++;
    }
  }
  if(sz(v1) * (ll)sz(v2) < 1e4) {
    int ret = 1e9;
    for(int a: v1) for(int b: v2) ret = min(ret, a^b);
    return ret;
  }
  vector<int> ona, offa;
  for(int out: v1) {
    assert(out < (2 << k));
    if(out&(1<<k)) {
      ona.push_back(out^(1<<k));
    }
    else {
      offa.push_back(out);
    }
  }
  vector<int> onb, offb;
  for(int out: v2) {
    assert(out < (2 << k));
    if(out&(1<<k)) {
      onb.push_back(out^(1<<k));
    }
    else {
      offb.push_back(out);
    }
  }
  int ret = 1e9;
  if(sz(ona) >= 1 && sz(onb) >= 1) {
    ret = min(ret, exactlyone(ona, onb, k-1));
  }
  if(sz(offa) >= 1 && sz(offb) >= 1) {
    ret = min(ret, exactlyone(offa, offb, k-1));
  }
  if((2<<k) <= ret) {
    if(sz(ona) >= 1 && sz(offb) >= 1) {
      ret = min(ret, (1<<k) + exactlyone(ona, offb, k-1));
    }
    if(sz(offa) >= 1 && sz(onb) >= 1) {
      ret = min(ret, (1<<k) + exactlyone(offa, onb, k-1));
    }
  }
  return ret;
}

ll mst(vector<int>& v, int b) {
  if(b < 0) return 0;
  if(sz(v) == 1) return 0;
  if(sz(v) == 2) return v[0] ^ v[1];
  vector<int> lhs, rhs;
  for(int out: v) {
    assert(out < (2 << b));
    if(out&(1<<b)) lhs.push_back(out^(1<<b));
    else rhs.push_back(out);
  }
  if(sz(lhs) == 0) return mst(rhs, b-1);
  if(sz(rhs) == 0) return mst(lhs, b-1);
  return mst(lhs, b-1) + mst(rhs, b-1) + (1 << b) + exactlyone(lhs, rhs, b-1);
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  cout << mst(v, 29) << "\n";
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