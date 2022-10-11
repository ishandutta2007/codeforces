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

char buf[100005];

void solve() {
  int n;
  scanf("%d\n", &n);
  gets(buf);
  int bo = 0;
  int be = 0;
  int ro = 0;
  int re = 0;
  for(int i = 0; i < n; i+=2) {
    if(buf[i] == 'b') be++;
    else re++;
  }
  for(int i = 1; i < n; i+=2) {
    if(buf[i] == 'b') bo++;
    else ro++;
  }
  printf("%d\n", min(max(be, ro), max(bo, re)));
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