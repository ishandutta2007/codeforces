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
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

const double PI = 2 * acos(0);
typedef long long ll;
typedef pair<int, int> pii;

// DID YOU FIX GLOBAL STATE

int dp[100005];
pii l[100005];

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    l[i] = pii(x, y);
  }
  l[0] = pii(-1000000000, 0);
  sort(l, l+n+1);
  int ret = n;
  for(int i = 1; i <= n; i++) {
    int leftI = 0;
    int rightI = i-1;
    while(leftI < rightI) {
      int mid = (leftI+rightI+1)/2;
      if(l[mid].first < l[i].first - l[i].second) {
        leftI = mid;
      }
      else {
        rightI = mid-1;
      }
    }
    dp[i] = (i-leftI-1) + dp[leftI];
    ret = min(ret, dp[i] + n-i);
  }
  printf("%d\n", ret);
}

int main() {
  solve();
  return 0;
}