#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

void rsolve() {
  string s;
  int x;
  cin >> s >> x;
  vector<bool> v(sz(s));
  fill(all(v), true);
  for(int i = 0; i < sz(s); i++) {
    if(s[i] == '0') {
      if(i-x >= 0) v[i-x] = false;
      if(i+x < sz(s)) v[i+x] = false;
    }
  }
  for(int i = 0; i < sz(s); i++) {
    if(s[i] == '1') {
      bool found = false;
      found |= i-x >= 0 && v[i-x];
      found |= i+x < sz(s) && v[i+x];
      if(!found) {
        cout << "-1\n";
        return;
      }
    }
  }
  for(int i = 0; i < sz(s); i++) cout << "01"[v[i]];
  cout << "\n";
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
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}