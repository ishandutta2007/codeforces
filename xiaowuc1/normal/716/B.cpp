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

char buf[50005];

void solve() {
  gets(buf);
  int len = strlen(buf);
  bool ret = false;
  for(int i = 0; i + 26 <= len; i++) {
    set<char> x;
    bool bad = false;
    for(int a = 0; a < 26; a++) {
      if(buf[i+a] == '?') continue;
      if(x.count(buf[i+a])) {
        bad = true;
      }
      x.insert(buf[i+a]);
    }
    if(bad) continue;
    ret = true;
    char next = 'A';
    for(int a = 0; a < 26; a++) {
      if(buf[i+a] == '?') {
        while(x.count(next)) next++;
        x.insert(next);
        buf[i+a] = next++;
      }
    }
  }
  for(int i = 0; i < len; i++) {
    if(buf[i] == '?') buf[i] = 'A';
  }
  if(!ret) printf("-1\n");
  else printf("%s\n", buf);
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