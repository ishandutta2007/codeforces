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
const double PI = 2 * acos(0);
const int MOD = 1000000007;

bool can[2][505][505];

void solve() {
  int n, want;
  scanf("%d%d", &n, &want);
  can[0][0][0] = true;
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    int j = i&1;
    int k = 1^j;
    memset(can[k], 0, sizeof(can[k]));
    for(int a = 0; a <= want; a++) {
      for(int b = 0; b <= a; b++) {
        if(!can[j][a][b]) continue;
        can[k][a][b] |= can[j][a][b];
        if(a+t <= want) {
          can[k][a+t][b] |= can[j][a][b];
          can[k][a+t][b+t] |= can[j][a][b];
        }
      }
    }
  }
  vector<int> ret;
  for(int a = 0; a <= want; a++) {
    if(can[n&1][want][a]) {
      ret.push_back(a);
    }
  }
  printf("%d\n", ret.size());
  for(int i = 0; i < ret.size(); i++) {
    printf("%d", ret[i]);
    if(i+1 == ret.size()) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}