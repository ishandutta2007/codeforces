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

vector<pii> queries;

void makesame(vector<int>& v) {
  if(sz(v) == 2) {
    queries.eb(v[0], v[1]);
    return;
  }
  int amt = sz(v);
  assert((amt&(amt-1)) == 0);
  vector<int> lhs, rhs;
  for(int i = 0; i < sz(v); i += 2) {
    lhs.pb(v[i]);
    rhs.pb(v[i+1]);
  }
  makesame(lhs);
  makesame(rhs);
  for(int i = 0; i < sz(lhs); i++) {
    queries.eb(lhs[i], rhs[i]);
  }
}

void solve() { 
  int n;
  cin >> n;
  if(n <= 2) {
    cout << "0\n";
    return;
  }
  int amt = 1;
  while(2*amt < n) amt *= 2;
  vector<int> orig;
  for(int i = 1; i <= amt; i++) orig.pb(i);
  makesame(orig);
  orig.clear();
  for(int i = 1; i <= amt; i++) orig.pb(n+1-i);
  makesame(orig);
  cout << sz(queries) << "\n";
  for(auto out: queries) cout << out.f << " " << out.s << "\n";
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