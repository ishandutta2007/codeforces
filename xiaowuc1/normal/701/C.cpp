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

int n;
char buf[100005];

int have[256];

void solve() {
  scanf("%d\n", &n);
  gets(buf);
  int need = 0;
  {
    set<char> disti;
    for(int i = 0; i < n; i++) {
      disti.insert(buf[i]);
    }
    need = disti.size();
  }
  int curr = 0;
  int lhs = 0;
  int ret = n;
  for(int i = 0; i < n; i++) {
    if(have[buf[i]]++ == 0) {
      curr++;
    }
    while(curr == need) {
      ret = min(ret, i-lhs + 1);
      if(--have[buf[lhs++]] == 0) {
        curr--;
      }
    }
  }
  printf("%d\n", ret);
}

int main() {
  solve();
  return 0;
}