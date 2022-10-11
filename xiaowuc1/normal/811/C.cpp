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

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

int l[5005];
int firstappear[5005];
int lastappear[5005];
int intxor[5005][5005];
int dp[5005];
bool seen[5005];
void solve() {
  int n;
  cin >> n;
  memset(firstappear, -1, sizeof(firstappear));
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    if(firstappear[l[i]] == -1) firstappear[l[i]] = i;
    lastappear[l[i]] = i;
    for(int j = 0; j < n; j++) intxor[i][j] = -1e9;
  }
  for(int i = 0; i < n; i++) {
    memset(seen, 0, sizeof(seen));
    int curr = 0;
    int maxallowed = -1;
    for(int j = i; j < n; j++) {
      if(firstappear[l[j]] < i) break;
      maxallowed = max(maxallowed, lastappear[l[j]]);
      if(!seen[l[j]]) {
        seen[l[j]] = true;
        curr ^= l[j];
      }
      if(maxallowed <= j) intxor[i][j] = curr;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      dp[j+1] = max(dp[j+1], dp[i] + intxor[i][j]);
    }
    dp[i+1] = max(dp[i], dp[i+1]);
  }
  cout << dp[n] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}