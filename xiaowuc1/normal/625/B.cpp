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
const double PI = 2 * acos(0);
const int MOD = 1000000007;

char buf[100005];
char t[35];

void solve() {
  gets(buf);
  gets(t);
  int bufLen = strlen(buf);
  int tLen = strlen(t);
  int ret = 0;
  for(int i = 0; i + tLen <= bufLen; i++) {
    int m = 0;
    for(int j = 0; j < tLen; j++) {
      if(buf[i+j] == t[j]) {
        m++;
      }
    }
    if(m == tLen) {
      buf[i+tLen-1] = 0;
      ret++;
    }
  }
  printf("%d\n", ret);
}

int main() {
  solve();
  return 0;
}