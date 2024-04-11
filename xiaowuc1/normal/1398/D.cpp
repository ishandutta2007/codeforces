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

int amt[3];
int g[3][200];
int dp[201][201][201];
int solve(int a, int b, int c) {
  if(dp[a][b][c] >= 0) return dp[a][b][c];
  dp[a][b][c] = 0;
  if(a > 0 && b > 0) dp[a][b][c] = max(dp[a][b][c], solve(a-1, b-1, c) + g[0][a-1] * g[1][b-1]);
  if(a > 0 && c > 0) dp[a][b][c] = max(dp[a][b][c], solve(a-1, b, c-1) + g[0][a-1] * g[2][c-1]);
  if(b > 0 && c > 0) dp[a][b][c] = max(dp[a][b][c], solve(a, b-1, c-1) + g[1][b-1] * g[2][c-1]);
  return dp[a][b][c];
}
void init() {
  for(int i = 0; i < 3; i++) cin >> amt[i];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < amt[i]; j++) cin >> g[i][j];
    sort(g[i], g[i]+amt[i]);
  }
}
void solve() {
  init();
  memset(dp, -1, sizeof(dp));
  cout << solve(amt[0], amt[1], amt[2]) << "\n";
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