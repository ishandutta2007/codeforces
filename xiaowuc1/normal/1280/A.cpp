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

const int MOD = 1000000007;

void rsolve() {
  int x;
  cin >> x;
  string s;
  cin >> s;
  vector<int> v;
  ll len = sz(s);
  for(int i = 0; i < sz(s); i++) v.push_back(s[i] - '1');
  for(int i = 0; i < x; i++) {
    assert(i < sz(v));
    int cp = v[i];
    ll lhs = i+1;
    ll rhs = len-1;
    len += cp * (MOD + rhs-lhs+1);
    len %= MOD;
    for(int a = 0; a < cp; a++) {
      for(int b = lhs; b <= rhs && sz(v) <= x; b++) v.push_back(v[b]);
    }
  }
  cout << len << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}