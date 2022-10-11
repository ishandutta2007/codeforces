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

ll g[505][505];

void solve() {
  int n;
  scanf("%d", &n);
  if(n == 1) {
    printf("1\n");
    return;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%lld", &g[i][j]);
    }
  }
  ll expectedSum = 0;
  for(int i = 0; i < n; i++) {
    int seen = 0;
    ll curr = 0;
    for(int j = 0; j < n; j++) {
      if(g[i][j]) {
        seen++;
        curr += g[i][j];
      }
    }
    if(seen == n) {
      expectedSum = curr;
    }
  }
  ll ans = -1;
  for(int i = 0; i < n; i++) {
    int seen = 0;
    ll curr = 0;
    for(int j = 0; j < n; j++) {
      if(g[i][j]) {
        seen++;
        curr += g[i][j];
      }
    }
    if(seen == n-1) {
      if(curr >= expectedSum) {
        printf("-1\n");
        return;
      }
      for(int j = 0; j < n; j++) {
        if(g[i][j] == 0) {
          g[i][j] = expectedSum - curr;
          ans = g[i][j];
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    ll row = 0;
    ll col = 0;
    for(int j = 0; j < n; j++) {
      row += g[i][j];
      col += g[j][i];
    }
    if(row != expectedSum || col != expectedSum) {
      printf("-1\n");
      return;
    }
  }
  ll diag1 = 0;
  ll diag2 = 0;
  for(int i = 0; i < n; i++) {
    diag1 += g[i][i];
    diag2 += g[n-1-i][i];
  }
  if(diag1 != expectedSum || diag2 != expectedSum) {
    printf("-1\n");
    return;
  }
  printf("%lld\n", ans);
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