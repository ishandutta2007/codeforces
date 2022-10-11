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

const double PI = 2 * acos(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

const int MOD = 1000000007;

void solve() {
  int x, y;
  scanf("%d%d", &x, &y);
  int n;
  scanf("%d", &n);
  double ret = 1e9;
  while(n--) {
    int xx, yy, vv;
    scanf("%d%d%d", &xx, &yy, &vv);
    double xxx = x - xx;
    double yyy = y - yy;
    ret = min(ret, sqrt(xxx*xxx+yyy*yyy)/vv);
  }
  printf("%.9f\n", ret);
}

int main() {
  solve();
  return 0;
}