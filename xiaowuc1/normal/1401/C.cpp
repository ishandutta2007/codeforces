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

int want[100005];
int l[100005];
int n;
void rsolve() {
  cin >> n;
  int lhs = 2e9;
  for(int i = 0; i < n; i++) cin >> l[i];
  for(int i = 0; i < n; i++) lhs = min(lhs, l[i]);
  for(int i = 0; i < n; i++) want[i] = l[i];
  sort(want, want+n);
  for(int i = 0; i < n; i++) {
    if(want[i] != l[i]) {
      if(__gcd(want[i], lhs) != lhs) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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