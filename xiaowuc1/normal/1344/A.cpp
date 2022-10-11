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

void rsolve() {
  int n;
  cin >> n;
  set<int> s;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x += i;
    x %= n;
    if(x < 0) x += n;
    s.insert(x);
  }
  if(sz(s) == n) cout << "YES\n";
  else cout << "NO\n";
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