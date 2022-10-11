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

int amt[15][15];

int n, t;

void pour(int x, int y, int k) {
  if(x >= n || k == 0) return;
  int use = min(k, 1024 - amt[x][y]);
  amt[x][y] += use;
  k -= use;
  pour(x+1, y, k/2);
  pour(x+1, y+1, k/2);
}

void solve() {
  scanf("%d%d", &n, &t);
  while(t--) {
    pour(0, 0, 1024);
  }
  int ret = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
      if(amt[i][j] == 1024) {
        ret++;
      }
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