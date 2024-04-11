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

int g[105][105];
int dp[1000005];
int par[1000005];
int l[1000005];
void solve() {
  int n;
  cin >> n;
  memset(g, 1, sizeof(g));
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j++) {
      if(s[j] == '1') g[i][j] = 1;
    }
    g[i][i] = 0;
  }
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  int k;
  cin >> k;
  for(int i = 0; i < k; i++) {
    cin >> l[i];
    l[i]--;
  }
  memset(dp, 1, sizeof(dp));
  dp[0] = 0;
  for(int i = 1; i < k; i++) {
    dp[i] = dp[i-1];
    par[i] = i-1;
    for(int d = 2; d <= i && d <= n; d++) {
      if(g[l[i-d]][l[i]] == d) {
        if(dp[i-d] < dp[i]) {
          dp[i] = dp[i-d];
          par[i] = i-d;
        }
      }
      else {
        break;
      }
    }
    dp[i]++;
  }
  vector<int> ret;
  int curr = k-1;
  while(curr) {
    ret.pb(curr);
    curr = par[curr];
  }
  ret.pb(0);
  reverse(all(ret));
  cout << sz(ret) << "\n";
  for(int i = 0; i < sz(ret); i++) cout << (l[ret[i]]+1) << " \n"[i == sz(ret)-1];
}

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