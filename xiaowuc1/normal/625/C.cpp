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

int grid[505][505];

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  k--;
  int curr = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < k; j++) {
      grid[i][j] = ++curr;
    }
  }
  int ret = 0;
  for(int i = 0; i < n; i++) {
    for(int j = k; j < n; j++) {
      grid[i][j] = ++curr;
    }
    ret += grid[i][k];
  }
  printf("%d\n", ret);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int qq = 1;
  //int qq = 1e9;
  //int qq; scanf("%d\n", &qq);
  for(int casenum = 1; casenum <= qq; casenum++) {
    solve();
  }
  return 0;
}