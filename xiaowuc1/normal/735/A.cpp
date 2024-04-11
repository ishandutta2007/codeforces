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

int n, k;

char buf[105];
bool can[105];

void solve() {
  scanf("%d%d\n", &n, &k);
  gets(buf);
  int goal = 0;
  for(int i = 0; i < n; i++) {
    if(buf[i] == 'G') {
      can[i] = true;
    }
    if(buf[i] == 'T') goal = i;
  }
  while(true) {
    bool upd = false;
    for(int i = 0; i < n; i++) {
      if(can[i] && i >= k && !can[i-k] && buf[i-k] != '#') {
        can[i-k] = true;
        upd = true;
      }
      if(can[i] && i + k < n && !can[i+k] && buf[i+k] != '#') {
        can[i+k] = true;
        upd = true;
      }

    }
    if(!upd) break;
  }
  if(can[goal]) printf("YES\n");
  else printf("NO\n");
}

int main() {
  solve();
  return 0;
}