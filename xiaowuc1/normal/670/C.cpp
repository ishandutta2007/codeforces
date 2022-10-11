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

int x[200005];
int y[200005];

void solve() {
  int n;
  scanf("%d", &n);
  map<int, int> m;
  while(n--) {
    int x;
    scanf("%d", &x);
    m[x]++;
  }
  int s;
  scanf("%d", &s);
  int ret = 0;
  int a = -1;
  int b = -1;
  for(int i = 1; i <= s; i++) {
    scanf("%d", &x[i]);
  }
  for(int i = 1; i <= s; i++) {
    scanf("%d", &y[i]);
  }
  for(int i = 1; i <= s; i++) {
    if(m[x[i]] > a || (m[x[i]] == a && m[y[i]] > b)) {
      ret = i;
      a = m[x[i]];
      b = m[y[i]];
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