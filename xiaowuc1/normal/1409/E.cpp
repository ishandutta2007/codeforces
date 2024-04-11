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
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;


void load(vector<int>& v, int n) {
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
}

void rsolve() {
  int n, k;
  cin >> n >> k;
  vector<int> v;
  load(v, n);
  {
    vector<int> y;
    load(y, n);
  }
  sort(all(v));
  vector<int> pdp(n), sdp(n);
  {
    int lhs = 0;
    for(int i = 0; i < n; i++) {
      while(v[i] - v[lhs] > k) lhs++;
      pdp[i] = i - lhs + 1;
    }
  }
  {
    int rhs = n-1;
    for(int i = n-1; i >= 0; i--) {
      while(v[rhs] - v[i] > k) rhs--;
      sdp[i] = rhs - i + 1;
    }
  }
  for(int i = 1; i < n; i++) pdp[i] = max(pdp[i], pdp[i-1]);
  for(int i = n-2; i >= 0; i--) sdp[i] = max(sdp[i], sdp[i+1]);
  int ret = 0;
  for(int i = -1; i < n; i++) {
    int cand = 0;
    if(i >= 0) cand += pdp[i];
    if(i+1 < n) cand += sdp[i+1];
    ret = max(ret, cand);
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
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}