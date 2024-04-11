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
typedef pair<pii, int> ppiii;
const double PI = 2 * acos(0);
const int MOD = 1000000007;
const int HASH = 3137;

int l[105];

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  k--;
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  int ret = 0;
  if(l[k]) ret++;
  int i = k;
  for(int d = 1; d <= n; d++) {
    if(i-d >= 0 && i+d < n && l[i-d] && l[i+d]) {
      ret += 2;
    }
    else if(i-d >= 0 && i+d >= n && l[i-d]) {
      ret++;
    }
    else if(i-d < 0 && i+d < n && l[i+d]) {
      ret++;
    }
  }
  printf("%d\n", ret);
}

int main() {
  /*
  freopen("integral.in","r",stdin);
  freopen("integral.out","w",stdout);
  */
  int qq = 1;
  //int qq = 1e9;
  //int qq; scanf("%d\n", &qq);
  for(int casenum = 1; casenum <= qq; casenum++) {
    solve();
  }
  return 0;
}