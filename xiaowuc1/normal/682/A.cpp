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

ll amt[2][5];

void solve() {
  for(int i = 0; i < 2; i++) {
    int t;
    scanf("%d", &t);
    for(int a = 1; a <= t; a++) {
      amt[i][a%5]++;
    }
  }
  ll ret = 0;
  ret += amt[0][0] * amt[1][0];
  ret += amt[0][1] * amt[1][4];
  ret += amt[0][2] * amt[1][3];
  ret += amt[0][3] * amt[1][2];
  ret += amt[0][4] * amt[1][1];
  printf("%lld\n", ret);
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