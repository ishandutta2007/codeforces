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

int lhs[100005];
int rhs[100005];

void solve() {
  int n;
  scanf("%d", &n);
  int lSum = 0;
  int rSum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &lhs[i], &rhs[i]);
    lSum += lhs[i];
    rSum += rhs[i];
  }
  int beauty = max(lSum, rSum) - min(lSum, rSum);
  int ret = 0;
  for(int i = 0; i < n; i++) {
    int lNew = lSum - lhs[i] + rhs[i];
    int rNew = rSum - rhs[i] + lhs[i];
    if(max(lNew, rNew) - min(lNew, rNew) > beauty) {
      beauty = max(lNew, rNew) - min(lNew, rNew);
      ret = i+1;
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