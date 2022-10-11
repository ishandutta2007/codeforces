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
ll ret;

bool solve(vector<ll>& v, int b) {
  ll curr = 1;
  ll cand = 0;
  for(ll out: v) {
    cand += abs(curr - out);
    if(cand >= ret) return false;
    curr *= b;
  }
  ret = cand;
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(all(v));
  for(auto out: v) ret += abs(out - 1);
  int x = 2;
  while(solve(v, x++));
  cout << ret << "\n";
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