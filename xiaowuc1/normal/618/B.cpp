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

int g[55][55];

int ret[55];

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    ret[i] = n;
    for(int j = 0; j < n; j++) {
      scanf("%d", &g[i][j]);
      if(g[i][j] == 0) g[i][j] = 1e9;
    }
  }
  for(int a = 1; a < n; a++) {
    int minIn = 1e9;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        minIn = min(minIn, g[i][j]);
      }
    }
    int seen[55];
    memset(seen, 0, sizeof(seen));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(g[i][j] == minIn) {
          seen[i]++;
          seen[j]++;
        }
      }
    }
    int best = 0;
    for(int i = 1; i < n; i++) {
      if(seen[i] > seen[best]) {
        best = i;
      }
    }
    ret[best] = a;
    for(int i = 0; i < n; i++) {
      g[i][best] = 1e9;
      g[best][i] = 1e9;
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%d ", ret[i]);
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