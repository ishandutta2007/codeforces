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

// remember you may need to clear state

vector<int> rsolve(int n, int x, int y, int d) {
  vector<int> ret;
  if((y-x)%d || (y-x)/d + 1 > n) return ret;
  for(int i = y; i > 0 && sz(ret) < n; i -= d) ret.push_back(i);
  for(int i = y+d; sz(ret) < n; i += d) ret.push_back(i);
  sort(all(ret));
  return ret;
}

void rsolve() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> ans;
  for(int d = 1; d <= 50; d++) {
    vector<int> cand = rsolve(n, x, y, d);
    if(sz(cand) == 0) continue;
    if(sz(ans) == 0) ans.swap(cand);
    else if(ans.back() > cand.back()) ans.swap(cand);
  }
  for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
}

void solve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    rsolve();
  }
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