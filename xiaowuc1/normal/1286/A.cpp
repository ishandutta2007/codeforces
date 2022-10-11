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

int l[105];
int dp[105][105][2];
int ndp[105][105][2];

void solve() {
  int n;
  cin >> n;
  memset(dp, 1, sizeof(dp));
  for(int i = 0; i < n; i++) cin >> l[i];
  int odd = 0;
  int even = 0;
  for(int i = 1; i <= n; i++) {
    if(i%2) odd++;
    else even++;
  }
  for(int i = 0; i < n; i++) {
    if(l[i] != 0) {
      if(l[i]%2) odd--;
      else even--;
    }
  }
  if(l[0] == 0) {
    if(odd > 0) dp[odd-1][even][1] = 0;
    if(even > 0) dp[odd][even-1][0] = 0;
  }
  else {
    dp[odd][even][l[0]%2] = 0;
  }
  for(int i = 1; i < n; i++) {
    memset(ndp, 1, sizeof(ndp));
    for(int a = 0; a <= odd; a++) {
      for(int b = 0; b <= even; b++) {
        for(int c = 0; c < 2; c++) {
          if(l[i] == 0) {
            if(a > 0) {
              ndp[a-1][b][1] = min(ndp[a-1][b][1], dp[a][b][c] + (c==0));
            }
            if(b > 0) {
              ndp[a][b-1][0] = min(ndp[a][b-1][0], dp[a][b][c] + (c==1));
            }
          }
          else {
            ndp[a][b][l[i]%2] = min(ndp[a][b][l[i]%2], dp[a][b][c] + (c != (l[i]%2)));
          }
        }
      }
    }
    memcpy(dp, ndp, sizeof(dp));
  }
  cout << min(dp[0][0][0], dp[0][0][1]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}