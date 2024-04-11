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

void win(int x) {
  cout << x << "\n";
  exit(0);
}

int covered;
int r, c;
string g[1005];
int dp[1005][1005];

bool full(int x, int y, int a, int b) {
  // a by b tl at x,y is full
  return dp[x+a][y+b] - dp[x][y+b] - dp[x+a][y] + dp[x][y] == a*b;
}

bool valid(int x, int y, int a, int b) {
  if(!full(x, y, a, b)) return false;
  int have = a*b;
  while(true) {
    if(!full(x+1, y, a, b) && !full(x, y+1, a, b)) break;
    if(full(x+1, y, a, b) && full(x, y+1, a, b)) return false;
    if(full(x+1, y, a, b)) {
      x++;
      have += b;
    }
    else {
      assert(full(x, y+1, a, b));
      y++;
      have += a;
    }
  }
  return have == covered;
}

void solve() {
  cin >> r >> c;
  for(int i = 1; i <= r; i++) {
    cin >> g[i-1];
    for(int j = 1; j <= c; j++) {
      dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
      if(g[i-1][j-1] == 'X') {
        dp[i][j]++;
        covered++;
      }
    }
  }
  int sx = -1;
  int sy = -1;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c && sx < 0; j++) {
      if(g[i][j] == 'X') {
        sx = i;
        sy = j;
      }
    }
  }
  assert(sx >= 0);
  int ret = 1e9;
  for(int a = 1; sx + a <= r; a++) {
    for(int b = 1; a*b < ret && sy + b <= c; b++) {
      if(valid(sx, sy, a, b)) {
        ret = a*b;
      }
    }
  }
  if(ret == 1e9) ret = -1;
  win(ret);

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