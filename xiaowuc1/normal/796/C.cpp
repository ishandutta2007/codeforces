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
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

int n;
int l[1000005];
vector<int> edges[1000005];
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> l[i];
    l[i] += 2;
  }
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].pb(b);
    edges[b].pb(a);
  }
  int ret = 2e9;
  map<int, int> dp;
  for(int i = 1; i <= n; i++) dp[l[i]]++;
  for(int i = 1; i <= n; i++) {
    map<int, int> deltas;
    deltas[l[i]]--;
    deltas[l[i]-2]++;
    for(int out: edges[i]) {
      deltas[l[out]]--;
      deltas[l[out]-1]++;
    }
    int v = max(dp.rbegin()->f, dp.begin()->f);
    while(true) {
      if(dp[v] + deltas[v] > 0) {
        ret = min(ret, v);
        break;
      }
      v--;
    }
  }
  cout << ret << "\n";
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