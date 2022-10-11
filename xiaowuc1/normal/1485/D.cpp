#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
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
#define derr if(0) cerr
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

int g[500][500];
int ret[500][500];
int r, c;
set<int> p4;

bool dfs(int i, int j) {
  if(r == i) return true;
  if(c == j) return dfs(i+1, 0);
  if(ret[i][j]) return dfs(i, j+1);
  int src = -1;
  if(i) src = ret[i-1][j];
  else src = ret[i][j-1];
  for(int out: p4) {
    for(int delta = -1; delta <= 1; delta += 2) {
      int cand = src + out * delta;
      if(cand < 1 || cand > 1e6 || cand % g[i][j]) continue;
      if(i && !p4.count(abs(cand - ret[i-1][j]))) continue;
      if(j && !p4.count(abs(cand - ret[i][j-1]))) continue;
      ret[i][j] = cand;
      if(dfs(i, j+1)) return true;
      ret[i][j] = 0;
    }
  }
  return false;
}

void solve() {
  for(int a = 1; a*a*a*a <= 1e6; a++) p4.insert(a*a*a*a);
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> g[i][j];
    }
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(i%2 == j%2) ret[i][j] = 720720;
    }
  }
  assert(dfs(0, 1));
  for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cout << ret[i][j] << " \n"[j == c-1];
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