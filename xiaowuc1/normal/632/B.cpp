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
const double PI = 2 * acos(0);
const int MOD = 1000000007;

char buf[500005];
ll score[500005];

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &score[i]);
  }
  gets(buf);
  gets(buf);
  ll bScoreOrig = 0;
  for(int i = 0; i < n; i++) {
    if(buf[i] == 'B') bScoreOrig += score[i];
  }
  ll ret = bScoreOrig;
  ll pref = bScoreOrig;
  for(int i = 0; i <n; i++) {
    if(buf[i] == 'A') {
      pref += score[i];
      ret = max(ret, pref);
    }
    else {
      pref -= score[i];
    }
  }
  pref = bScoreOrig;
  for(int i = 0; i <n; i++) {
    if(buf[n-1-i] == 'A') {
      pref += score[n-1-i];
      ret = max(ret, pref);
    }
    else {
      pref -= score[n-1-i];
    }
  }
  printf("%lld\n", ret);
}

int main() {
  solve();
  return 0;
}