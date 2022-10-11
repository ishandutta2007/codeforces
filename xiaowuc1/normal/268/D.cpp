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

#include <unordered_map>

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

const int MOD = 1000000009;

int dp[2][31][31][31];
int ndp[2][31][31][31];

void solve() {
  int n, h;
  cin >> n >> h;
  dp[1][0][0][0]++;
  while(n--) {
    memset(ndp, 0, sizeof(dp));
    for(int a = 0; a < 2; a++) {
      for(int b = 0; b <= h; b++) {
        for(int c = 0; c <= h; c++) {
          for(int d = 0; d <= h; d++) {
            // increment a
            {
              int na = a;
              int nb = min(b+1, h);
              int nc = min(c+1, h);
              int nd = min(d+1, h);
              ndp[na][nb][nc][nd] += dp[a][b][c][d];
              if(ndp[na][nb][nc][nd] >= MOD) ndp[na][nb][nc][nd] -= MOD;
            }
            // swap with b
            {
              int na = (b < h);
              int nb = a ? 1 : h;
              int nc = min(c+1, h);
              int nd = min(d+1, h);
              ndp[na][nb][nc][nd] += dp[a][b][c][d];
              if(ndp[na][nb][nc][nd] >= MOD) ndp[na][nb][nc][nd] -= MOD;
            }
            // swap with c
            {
              int na = (c < h);
              int nb = min(b+1, h);
              int nc = a ? 1 : h;
              int nd = min(d+1, h);
              ndp[na][nb][nc][nd] += dp[a][b][c][d];
              if(ndp[na][nb][nc][nd] >= MOD) ndp[na][nb][nc][nd] -= MOD;
            }
            // swap with d
            {
              int na = (d < h);
              int nb = min(b+1, h);
              int nc = min(c+1, h);
              int nd = a ? 1 : h;
              ndp[na][nb][nc][nd] += dp[a][b][c][d];
              if(ndp[na][nb][nc][nd] >= MOD) ndp[na][nb][nc][nd] -= MOD;
            }
          }
        }
      }
    }
    memcpy(dp, ndp, sizeof(dp));
  }
  int ret = 0;
  for(int a = 0; a < 2; a++) {
    for(int b = 0; b <= h; b++) {
      for(int c = 0; c <= h; c++) {
        for(int d = 0; d <= h; d++) {
          if(a > 0 || b < h || c < h || d < h) {
            ret += dp[a][b][c][d];
            if(ret >= MOD) ret -= MOD;
          }
        }
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}