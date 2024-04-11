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
typedef pair<int, pii> pipii;
typedef vector<int> vi;

// NO SAD
vector<int> numDP[100005];
vector<int> modDP[7];
int dp[5001][5001];
int sdp[5001];
int l[5001];
int n;

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    numDP[l[i]].push_back(i);
    modDP[l[i]%7].push_back(i);
  }
  for(int x = 0; x < n; x++) {
    sdp[x] = max(sdp[x], 1);
    {
      auto it = upper_bound(modDP[l[x]%7].begin(), modDP[l[x]%7].end(), x);
      if(it != modDP[l[x]%7].end()) {
        sdp[*it] = max(sdp[*it], sdp[x] + 1);
      }
    }
    for(int dx = -1; dx <= 1; dx += 2) {
      auto it = upper_bound(numDP[l[x] + dx].begin(), numDP[l[x] + dx].end(), x);
      if(it != numDP[l[x] + dx].end()) {
        sdp[*it] = max(sdp[*it], sdp[x] + 1);
      }
    }
  }
  int ret = 0;
  for(int y = 1; y < n; y++) {
    for(int x = 0; x < y; x++) {
      ret = max(ret, dp[x][y] = max(dp[x][y], max(2, sdp[x] + 1)));
      {
        auto it = upper_bound(modDP[l[x]%7].begin(), modDP[l[x]%7].end(), y);
        if(it != modDP[l[x]%7].end()) {
          dp[y][*it] = max(dp[y][*it], dp[x][y] + 1);
        }
      }
      for(int dx = -1; dx <= 1; dx += 2) {
        auto it = upper_bound(numDP[l[x] + dx].begin(), numDP[l[x] + dx].end(), y);
        if(it != numDP[l[x] + dx].end()) {
          dp[y][*it] = max(dp[y][*it], dp[x][y] + 1);
        }
      }
      {
        auto it = upper_bound(modDP[l[y]%7].begin(), modDP[l[y]%7].end(), y);
        if(it != modDP[l[y]%7].end()) {
          dp[x][*it] = max(dp[x][*it], dp[x][y] + 1);
        }
      }
      for(int dx = -1; dx <= 1; dx += 2) {
        auto it = upper_bound(numDP[l[y] + dx].begin(), numDP[l[y] + dx].end(), y);
        if(it != numDP[l[y] + dx].end()) {
          dp[x][*it] = max(dp[x][*it], dp[x][y] + 1);
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