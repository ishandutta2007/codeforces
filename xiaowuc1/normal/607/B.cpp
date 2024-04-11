#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

typedef long long ll;
typedef pair<int, int> pii;
const double PI = 2 * acos(0);
const int MOD = 1000000007;

int n;

int list[505];
int dp[505][505];
int dpMatch[505][505];

int match(int l, int r);
int solve(int l, int r);


int match(int l, int r) {
  if(l >= r) return 0;
  if(dpMatch[l][r] >= 0) return dpMatch[l][r];
  dpMatch[l][r] = 1 + match(l+1, r);
  for(int i = l+1; i <= r; i++) {
    if(list[i] == list[l]) {
      dpMatch[l][r] = min(dpMatch[l][r], match(l+1, i-1) + solve(i+1, r));
    }
  }
  return dpMatch[l][r];
}

int solve(int l, int r) {
  if(l > r) return 0;
  if(l == r) return 1;
  if(dp[l][r] >= 0) return dp[l][r];
  dp[l][r] = 1+solve(l+1, r);
  for(int i = l+1; i <= r; i++) {
    if(list[l] == list[i]) {
      dp[l][r] = min(dp[l][r], 1 + match(l, i) + solve(i+1, r));
    }
  }
  return dp[l][r];
}

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &list[i]);
    for(int j = i; j < n; j++) {
      dp[i][j] = -1;
      dpMatch[i][j] = -1;
    }
  }
  printf("%d\n", solve(0, n-1));
}

int main() {
  solve();
  return 0;
}