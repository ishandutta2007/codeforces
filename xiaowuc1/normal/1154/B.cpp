#include <algorithm>
#include <array>
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
typedef vector<vector<ll>> matrix;

int l[105];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  int ret = 1e9;
  for(int target = -200; target <= 200; target++) {
    set<int> seen;
    for(int i = 0; i < n; i++) {
      if(l[i] == target) continue;
      seen.insert(l[i] - target);
    }
    if(sz(seen) == 0) {
      ret = 0;
      break;
    }
    if(sz(seen) == 1) {
      ret = min(ret, abs(*seen.begin()));
      continue;
    }
    if(sz(seen) > 2) continue;
    assert(sz(seen) == 2);
    if(*seen.begin() + *seen.rbegin() == 0) ret = min(ret, *seen.rbegin());
  }
  if(ret == 1e9) ret = -1;
  cout << ret << "\n";
}

// what would chika do
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