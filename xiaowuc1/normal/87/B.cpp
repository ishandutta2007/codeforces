#include <algorithm>
#include <array>
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

map<string, pll> dp;

pll parse(string& s) {
  int lhs = 0;
  int rhs = sz(s) - 1;
  int amp = 0;
  int ast = 0;
  while(s[lhs] == '&') {
    amp++;
    lhs++;
  }
  while(s[rhs] == '*') {
    ast++;
    rhs--;
  }
  s = s.substr(lhs, rhs + 1 - lhs);
  if(!dp.count(s)) dp[s] = {-1, 0};
  else {
    pll cand = dp[s];
    cand.s += ast - amp;
    if(cand.s < 0) {
      cand.s = 0;
      cand.f = -1;
    }
    return cand;
  }
  return dp[s];
}

void solve() {
  dp["void"] = {0, 0};
  dp["errtype"] = {-1, 0};
  int q;
  cin >> q;
  while(q--) {
    string t;
    cin >> t;
    if(t == "typedef") {
      string a, b;
      cin >> a >> b;
      dp[b] = parse(a);
    }
    else {
      string b;
      cin >> b;
      pll x = parse(b);
      if(x.f == -1) cout << "errtype\n";
      else {
        cout << "void";
        for(int i = 0; i < x.s; i++) cout << "*";
        cout << "\n";
      }
    }
  }
}

// !editcommand?
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points
// are you not using modint when you should

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}