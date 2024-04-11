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

int grid[5005][5005];

int t[100005];
int x[100005];
int cc[100005];

int lastRow[5005];
int lastCol[5005];

void solve() {
  int r, c;
  scanf("%d%d", &r, &c);
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d%d%d", &t[i], &x[i], &cc[i]);
    if(t[i] == 1) {
      lastRow[--x[i]] = i;
    }
    else {
      lastCol[--x[i]] = i;
    }
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      int tt = max(lastRow[i], lastCol[j]);
      if(tt == 0) printf("0 ");
      else printf("%d ", cc[tt]);
    }
    printf("\n");
  }
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