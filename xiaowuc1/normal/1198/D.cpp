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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

string g[50];
int dp[50][50][50][50];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> g[i];
    for(int j = 0; j < n; j++) {
      if(g[i][j] == '#') dp[i][j][i][j] = 1;
    }
  }
  for(int xb = 0; xb < n; xb++) {
    for(int xa = xb; xa >= 0; xa--) {
      for(int yb = 0; yb < n; yb++) {
        for(int ya = yb; ya >= 0; ya--) {
          if(xa == xb && ya == yb) continue;
          dp[xa][ya][xb][yb] = max(xb-xa, yb-ya) + 1;
          for(int x = xa; x < xb; x++) {
            dp[xa][ya][xb][yb] = min(dp[xa][ya][xb][yb], dp[xa][ya][x][yb] + dp[x+1][ya][xb][yb]);
          }
          for(int y = ya; y < yb; y++) {
            dp[xa][ya][xb][yb] = min(dp[xa][ya][xb][yb], dp[xa][ya][xb][y] + dp[xa][y+1][xb][yb]);
          }
        }
      }
    }
  }
  cout << dp[0][0][n-1][n-1] << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}