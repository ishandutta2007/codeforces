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

int dp[3005][3005];
int l[3005];
void rsolve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    l[i]--;
    for(int a = 0; a < n; a++) {
      dp[a][i+1] = dp[a][i];
    }
    dp[l[i]][i+1]++;
  }
  ll ret = 0;
  for(int i = 1; i < n; i++) {
    for(int j = i+1; j+1 < n; j++) {
      ret += dp[l[j]][i] * (dp[l[i]][n] - dp[l[i]][j+1]);
    }
  }
  cout << ret << "\n";
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