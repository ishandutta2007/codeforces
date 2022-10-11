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

char buf[105];

void solve() {
  vector<int> all;
  all.push_back(-1);
  gets(buf);
  for(int i = 0; i < strlen(buf); i++) {
    bool okay = false;
    okay |= buf[i] == 'A';
    okay |= buf[i] == 'E';
    okay |= buf[i] == 'O';
    okay |= buf[i] == 'I';
    okay |= buf[i] == 'U';
    okay |= buf[i] == 'Y';
    if(okay) all.push_back(i);
  }
  all.push_back(strlen(buf));
  int ret = all[1] - all[0];
  for(int i = 2; i < all.size(); i++) {
    ret = max(ret, all[i] - all[i-1]);
  }
  printf("%d\n", ret);
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