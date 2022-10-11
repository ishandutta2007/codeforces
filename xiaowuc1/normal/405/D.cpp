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
typedef pair<int, pii> pipii;

const int MOD = 1000000007;

bool canUse[1000005];

bool theirs[1000005];

void solve() {
  int n;
  scanf("%d", &n);
  for(int a = 1; a <= 1000000; a++) {
    canUse[a] = true;
  }
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    canUse[t] = false;
    theirs[t] = true;
  }
  vector<int> ret;
  int lhs = 1;
  for(int i = 1; i <= 1000000; i++) {
    if(theirs[i]) {
      if(!canUse[1000001-i]) {
        theirs[1000001-i] = false;
        while(!canUse[lhs] || !canUse[1000001-lhs]) {
          lhs++;
        }
        canUse[lhs] = false;
        canUse[1000001-lhs] = false;
        ret.push_back(lhs);
        ret.push_back(1000001-lhs);
      }
      else {
        canUse[1000001-i] = false;
        ret.push_back(1000001-i);
      }
    }
  }
  printf("%d\n", ret.size());
  for(int i = 0; i < ret.size(); i++) {
    printf("%d", ret[i]);
    if(i == ret.size()-1) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}