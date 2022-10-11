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
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

const double PI = 2 * acos(0);
typedef long long ll;
typedef pair<int, int> pii;

unordered_map<int, int> m;

void solve() {
  int n;
  scanf("%d", &n);
  while(n--) {
    int a;
    scanf("%d", &a);
    m[a]++;
  }
  ll ret = 0;
  for(int amt = 1; amt <= 30; amt++) {
    int goal = 1 << amt;
    for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
      int curr = it->first;
      int other = goal - curr;
      if(curr > other) continue;
      if(curr == other) {
        ll go = it->second;
        ret += go*(go-1)/2;
      }
      else {
        if(m.count(other))
          ret += it->second * m[other];
      }
    }
  }
  printf("%lld\n", ret);
}

int main() {
  solve();
  return 0;
}