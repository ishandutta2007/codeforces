#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool assertGood(vector<int> v, int k) {
  for(int len = 1; len <= k; len++) {
    map<int, int> dp;
    bool unique = false;
    for(int i = 0; i + len <= v.size(); i++) {
      int curr = 0;
      for(int a = 0; a < len; a++) {
        curr *= 2;
        curr += v[i+a];
      }
      dp[curr]++;
    }
    for(auto x: dp) {
      if(x.second == 1) unique = true;
    }
    if(unique) {
      if(len < k) return false;
      if(len == k) return true;
    }
  }
  return false;
}

/*
int slow(int n, int k) {
  for(int mask = 0; mask < (1<<n); mask++) {
    bool good = false;
    for(int len = 1; len <= k; len++) {
      map<int, int> dp;
      int t = mask;
      for(int i = 0; i <= n-len; i++) {
        dp[t&(-1+(1<<len))]++;
        t /= 2;
      }
      bool unique = false;
      for(auto x: dp) {
        if(x.second == 1) unique = true;
      }
      if(unique) {
        if(len < k) break;
        if(len == k) good = true;
      }
    }
    if(good) return mask;
  }
  return -1;
}
*/

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v;
  int step = (n-k+2)/2;
  v.resize(n);
  if(k == 1) {
    v[0] = 1;
  }
  else {
    int curr = 0;
    while(curr < v.size()) {
      v[curr] = 1;
      curr += step;
    }
  }
  for(int out: v) cout << out;
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}