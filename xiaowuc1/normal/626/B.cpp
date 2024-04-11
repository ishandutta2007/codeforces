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

char buf[205];
int n;

void solve() {
  int r=0;
  int g=0;
  int b=0;
  bool rO = false;
  bool gO = false;
  bool bO = false;
  bool rE = false;
  bool gE = false;
  bool bE = false;
  scanf("%d\n", &n);
  gets(buf);
  for(int i = 0; i < n; i++) {
    if(buf[i] == 'R') r++;
    if(buf[i] == 'G') g++;
    if(buf[i] == 'B') b++;
  }
  if(r == 0) rE = true;
  else if(r == 1) rO = true;
  else {rE = true; rO = true;}

  if(g == 0) gE = true;
  else if(g == 1) gO = true;
  else {gE = true; gO = true;}

  if(b == 0) bE = true;
  else if(b == 1) bO = true;
  else {bE = true; bO = true;}

  bool bRet = false;
  bool gRet = false;
  bool rRet = false;
  if(rE && bO && gO) rRet = true;
  if(rO && bE && gE) rRet = true;
  if(gE && bO && rO) gRet = true;
  if(gO && bE && rE) gRet = true;
  if(bE && rO && gO) bRet = true;
  if(bO && rE && gE) bRet = true;

  if(rO && gO && bO) {
    bRet = true;
    gRet = true;
    rRet = true;
  }

  if(bRet) printf("B");
  if(gRet) printf("G");
  if(rRet) printf("R");

  printf("\n");
}

int main() {
  solve();
  return 0;
}