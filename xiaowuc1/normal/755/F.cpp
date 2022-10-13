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
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, pii> pdpii;
const double PI = 2 * acos(0);
const int MOD = 1000000007;
const int HASH = 3137;

int to[1000005];
bool seen[1000005];

bool dp[1000005];

int minSolve(vector<int>& sizes, int k) {
  sort(sizes.begin(), sizes.end());
  int ret = 0;
  dp[0] = true;
  for(int i = 0; i < sizes.size();) {
    int j = i+1;
    while(j < sizes.size() && sizes[j] == sizes[i]) {
      j++;
    }
    int amt = j-i;
    int nextAmt = 1;
    while(amt > 0) {
      int actual = min(amt, nextAmt);
      amt -= actual;
      for(int a = k; a >= actual * sizes[i]; a--) {
        dp[a] |= dp[a - actual * sizes[i]];
      }
      if(dp[k]) return k;
      nextAmt *= 2;
    }
    i = j;
  }
  return k+1;
}

int maxSolve(vector<int>& sizes, int k) {
  int odd = 0;
  int oddNum = 0;
  int even = 0;
  for(int i = 0; i < sizes.size(); i++) {
    if(sizes[i] % 2 == 0) {
      even += sizes[i];
    }
    else {
      odd += sizes[i];
      oddNum++;
    }
  }
  int ret = 0;
  while(k) {
    k--;
    if(even > 0) {
      even -= 2;
      ret += 2;
    }
    else if(odd > oddNum) {
      odd -= 2;
      ret += 2;
    }
    else if(odd > 0) {
      odd--;
      oddNum--;
      ret++;
    }
    else {
      break;
    }
  }
  return ret;
}

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> sizes;
  for(int i = 0; i < n; i++) {
    scanf("%d", &to[i]);
    to[i]--;
  }
  for(int i = 0; i < n; i++) {
    if(seen[i]) continue;
    int currSize = 1;
    seen[i] = true;
    int curr = to[i];
    while(!seen[curr]) {
      seen[curr] = true;
      currSize++;
      curr = to[curr];
    }
    sizes.push_back(currSize);
  }
  int minRet = minSolve(sizes, k);
  int maxRet = maxSolve(sizes, k);
  printf("%d %d\n", minRet, maxRet);
}

int main() {
  solve();
  return 0;
}