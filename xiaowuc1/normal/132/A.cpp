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
const double PI = 2 * acos(0);
const int MOD = 1000000007;

char buf[250];
int ret[250];

int rev(int x) {
  int ret = 0;
  for(int i = 0; i < 8; i++) {
    if(x&(1<<i)) {
      ret |= 1 << (7-i);
    }
  }
  return ret;
}

void solve() {
  gets(buf);
  int n = strlen(buf);
  for(int i = 0; i < n; i++) {
    int prev = i == 0 ? 0 : buf[i-1];
    prev = rev(prev);
    for(int j = 0; j < 256; j++) {
      if(rev((prev-j+256)%256) == buf[i]) {
        ret[i] = j;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%d\n", ret[i]);
  }
}

int main() {
  solve();
  return 0;
}