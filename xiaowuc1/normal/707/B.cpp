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

int minW[100005];

int lhs[100005];
int rhs[100005];
int w[100005];

bool safe[100005];

void solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= n; i++) {
    minW[i] = 2e9;
  }
  for(int i = 0; i < m; i++) {
    scanf("%d", &lhs[i]);
    scanf("%d", &rhs[i]);
    scanf("%d", &w[i]);
  }
  for(int i = 0; i < k; i++) {
    int t;
    scanf("%d", &t);
    safe[t] = true;
  }
  for(int i = 0; i < m; i++) {
    if(!safe[lhs[i]] || !safe[rhs[i]]) {
      minW[lhs[i]] = min(minW[lhs[i]], w[i]);
      minW[rhs[i]] = min(minW[rhs[i]], w[i]);
    }
  }
  int ret = 2e9;
  for(int i = 1; i <= n; i++) {
    if(safe[i])
      ret = min(ret, minW[i]);
  }
  if(ret == 2e9) ret = -1;
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