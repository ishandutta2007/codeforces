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

int row[105];
int col[105];

void solve() {
  int n;
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    gets(buf);
    for(int j = 0; j < n; j++) {
      if(buf[j] == 'C') {
        row[i]++;
        col[j]++;
      }
    }
  }
  int ret = 0;
  for(int i = 0; i < n; i++) {
    ret += (row[i] * (row[i] - 1)) / 2;
    ret += (col[i] * (col[i] - 1)) / 2;
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