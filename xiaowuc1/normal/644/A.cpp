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

void solve() {
  int n;
  scanf("%d", &n);
  int r, c;
  scanf("%d%d", &r, &c);
  if(n > r*c) {
    printf("-1\n");
    return;
  }
  vector<int> odd;
  vector<int> even;
  for(int i = 1; i <= n; i++) {
    if(i%2) odd.push_back(i);
    else even.push_back(i);
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      vector<int>& choose = i%2 == j%2 ? odd : even;
      if(choose.size()) {
        int x = choose[choose.size()-1];
        choose.pop_back();
        printf("%d ", x);
      }
      else {
        printf("0 ");
      }
    }
    printf("\n");
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