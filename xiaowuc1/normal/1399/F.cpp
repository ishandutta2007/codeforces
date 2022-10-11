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

short dp[6000][6000];
short id[6000][6000];
short casenum;

vector<int> validrhs[6000];
short solve(int lhs, int rhs) {
  if(lhs > rhs) return 0;
  if(id[lhs][rhs] == casenum) return dp[lhs][rhs];
  id[lhs][rhs] = casenum;
  dp[lhs][rhs] = solve(lhs+1, rhs);
  bool has = false;
  for(int out: validrhs[lhs]) {
    has |= out == rhs;
    if(out < rhs) dp[lhs][rhs] = max(dp[lhs][rhs], (short)(solve(lhs, out) + solve(out+1, rhs)));
  }
  dp[lhs][rhs] += has;
  return dp[lhs][rhs];
}

void rsolve() {
  casenum++;
  vector<int> lhs, rhs, all;
  int n;
  cin >> n;
  while(n--) {
    int a, b;
    cin >> a >> b;
    lhs.push_back(a);
    rhs.push_back(b);
    all.push_back(a);
    all.push_back(b);
  }
  sort(all(all));
  all.resize(unique(all(all)) - all.begin());
  for(int& out: lhs) out = lower_bound(all(all), out) - all.begin();
  for(int& out: rhs) out = lower_bound(all(all), out) - all.begin();
  for(int i = 0; i < sz(all); i++) validrhs[i].clear();
  for(int i = 0; i < sz(lhs); i++) validrhs[lhs[i]].push_back(rhs[i]);
  cout << solve(0, sz(all)-1) << "\n";
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