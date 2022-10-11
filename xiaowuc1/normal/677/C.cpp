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

ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r *= b;
      r %= m;
    }
    b *= b;
    b %= m;
    e /= 2;
  }
  return r;
}

char buf[100005];

void solve() {
  gets(buf);
  int ret = 0;
  int len = strlen(buf);
  for(int i = 0; i < len; i++) {
    int curr = 0;
    if(buf[i] >= '0' && buf[i] <= '9') curr = buf[i] - '0' + 0;
    if(buf[i] >= 'A' && buf[i] <= 'Z') curr = buf[i] - 'A' + 10;
    if(buf[i] >= 'a' && buf[i] <= 'z') curr = buf[i] - 'a' + 36;
    if(buf[i] == '-') curr = 62;
    if(buf[i] == '_') curr = 63;
    for(int a = 0; a < 6; a++) {
      if((curr&(1<<a)) == 0) ret++;
    }
  }
  printf("%lld\n", modpow(3, ret, MOD));
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