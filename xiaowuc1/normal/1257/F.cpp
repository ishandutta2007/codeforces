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

void normalize(vector<int>& v, bool makeNeg) {
  int small = v[0];
  for(int out: v) small = min(small, out);
  for(int& out: v) {
    out -= small;
  }
  if(makeNeg) {
    int small = v[0];
    for(int out: v) small = max(out, small);
    for(int& out: v) {
      out = -(out - small);
    }
  }
}

int l[100];
const int BOTTOM = (1<<15) - 1;
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  map<vector<int>, int> dp;
  for(int x = 0; x < (1<<15); x++) {
    vector<int> v;
    for(int i = 0; i < n; i++) {
      v.push_back(__builtin_popcount((l[i]&BOTTOM) ^ x));
    }
    normalize(v, true);
    dp[v] = x;
  }
  for(int i = 0; i < n; i++) l[i] >>= 15;
  for(int x = 0; x < (1<<15); x++) {
    vector<int> v;
    for(int i = 0; i < n; i++) {
      v.push_back(__builtin_popcount((l[i]&BOTTOM) ^ x));
    }
    normalize(v, false);
    if(dp.count(v)) {
      cout << ((x << 15) | dp[v]) << "\n";
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}