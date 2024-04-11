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
  int n;
  scanf("%d", &n);
  set<int> ret;
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    ret.insert(t);
  }
  while(true) {
    set<int>::iterator it = ret.end();
    it--;
    int now = *it;
    int curr = now;
    while(curr > 0) {
      if(ret.count(curr) == 0) {
        break;
      }
      curr /= 2;
    }
    if(curr == 0) break;
    ret.erase(now);
    ret.insert(curr);
  }
  for(set<int>::iterator it = ret.begin(); it != ret.end();) {
    printf("%d", *it);
    it++;
    if(it == ret.end()) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}