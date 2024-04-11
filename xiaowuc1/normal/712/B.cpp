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

char buf[1000005];

void solve() {
  gets(buf);
  int len = strlen(buf);
  if(len%2 == 1) {
    printf("-1\n");
    return;
  }
  int dx = 0;
  int dy = 0;
  for(int i = 0; i < len; i++) {
    if(buf[i] == 'L') dx++;
    if(buf[i] == 'R') dx--;
    if(buf[i] == 'D') dy++;
    if(buf[i] == 'U') dy--;
  }
  if(dx < 0) dx = -dx;
  if(dy < 0) dy = -dy;
  printf("%d\n", (dx+dy)/2);
}

int main() {
  solve();
  return 0;
}