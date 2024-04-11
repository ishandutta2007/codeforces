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
typedef pair<pii, pii> state;

const int MOD = 1000000007;

string g[500];
int r, c;
int dx[2]{1,0};
int dy[2]{0,1};

int dp[500][500];
int ndp[500][500];

void solve() {
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    cin >> g[i];
  }
  if(g[0][0] != g[r-1][c-1]) {
    cout << "0\n";
    return;
  }
  dp[0][r-1] = 1;
  int ret = 0;
  int lhssum = 0;
  int rhssum = r-1 + c-1;
  while(rhssum - lhssum >= 0) {
    memset(ndp, 0, sizeof(dp));
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < r; j++) {
        if(dp[i][j] == 0) continue;
        pii lhs = {i, lhssum-i};
        pii rhs = {j, rhssum-j};
        if(lhs.first > rhs.first || lhs.second > rhs.second) continue;
        if(abs(lhs.first-rhs.first) + abs(lhs.second-rhs.second) <= 1) {
          ret += dp[i][j];
          if(ret >= MOD) ret -= MOD;
        }
        else {
          for(int a = 0; a < 2; a++) {
            for(int b = 0; b < 2; b++) {
              pii nlhs = {lhs.first + dx[a], lhs.second + dy[a]};
              pii nrhs = {rhs.first - dx[b], rhs.second - dy[b]};
              if(nlhs.first < 0 || nlhs.first >= r || nlhs.second < 0 || nlhs.second >= c) continue;
              if(nrhs.first < 0 || nrhs.first >= r || nrhs.second < 0 || nrhs.second >= c) continue;
              if(g[nlhs.first][nlhs.second] != g[nrhs.first][nrhs.second]) continue;
              ndp[nlhs.first][nrhs.first] += dp[i][j];
              if(ndp[nlhs.first][nrhs.first] >= MOD) ndp[nlhs.first][nrhs.first] -= MOD;
            }
          }
        }
      }
    }
    memcpy(dp, ndp, sizeof(dp));
    lhssum++;
    rhssum--;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}