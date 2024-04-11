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

int pp(int b, int e) {
  int r = 1;
  while(e) {
    r *= b;
    e--;
  }
  return r;
}
bool p(int x) {
  if(x == 1) return false;
  for(int i = 2; i * i <= x; i++) if(x%i==0) return false;
  return true;
}
vector<int> smallestp[10];
void rsolve() {
  int a, b, c;
  cin >> a >> b >> c;
  int scale = c-1;
  int fa = a - scale;
  int fb = b - scale;
  scale = pp(10, scale);
  if(fa == fb) {
    cout << smallestp[fa][0] * scale << " " << smallestp[fb][1] * scale << "\n";
    return;
  }
  cout << smallestp[fa][0] * scale << " " << smallestp[fb][0] * scale << "\n";
  return;
}
void init() {
  for(int d = 1; d <= 9; d++) {
    int lhs = pp(10, d-1);
    while(sz(smallestp[d]) < 2) {
      if(p(lhs)) {
        smallestp[d].pb(lhs);
      }
      lhs++;
    }
  }
}
void solve() {
  init();
  int t;
  cin >> t;
  for(int a = 1; a <= t; a++) {
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