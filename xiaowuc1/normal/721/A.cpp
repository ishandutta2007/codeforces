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
  vector<int> ret;
  int n;
  scanf("%d\n", &n);
  gets(buf);
  for(int i = 0; i < n; i++) {
    if(buf[i] == 'W') continue;
    int j = i;
    int ans = 0;
    while(j < n && buf[j] == 'B') {
      ans++;
      j++;
    }
    i = --j;
    ret.push_back(ans);
  }
  printf("%d\n", ret.size());
  for(int i = 0; i < ret.size(); i++) {
    printf("%d", ret[i]);
    if(i == ret.size()-1) printf("\n");
    else printf(" ");
  }
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