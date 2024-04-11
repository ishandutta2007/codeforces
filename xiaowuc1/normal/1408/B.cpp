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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<double>> matrix;

int l[1005];
void rsolve() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> l[i];
  if(k == 1 && l[n-1] != l[0]) {
    cout << "-1\n";
    return;
  }
  int ret = 0;
  while(true) {
    ret++;
    set<int> seen;
    int last = 0;
    for(int i = 0; i < n; i++) {
      if(sz(seen) == k) l[i] -= last;
      else {
        last = max(last, l[i]);
        seen.insert(last);
        l[i] -= last;
      }
    }
    if(l[n-1] == 0) break;
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