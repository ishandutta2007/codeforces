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

char grid[505][505];

int hDP[505][505];
int vDP[505][505];

void solve() {
  int r, c;
  scanf("%d %d\n", &r, &c);
  for(int i = 0; i < r; i++) {
    gets(grid[i]);
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      hDP[i+1][j+1] = hDP[i+1][j] + hDP[i][j+1] - hDP[i][j];
      if(grid[i][j] == '.' && grid[i][j+1] == '.') hDP[i+1][j+1]++;
      vDP[i+1][j+1] = vDP[i+1][j] + vDP[i][j+1] - vDP[i][j];
      if(grid[i][j] == '.' && grid[i+1][j] == '.') vDP[i+1][j+1]++;
    }
  }
  int qq;
  scanf("%d", &qq);
  while(qq--) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int ret = 0;
    ret += hDP[r2][c2-1] - hDP[r1-1][c2-1] - hDP[r2][c1-1] + hDP[r1-1][c1-1];
    ret += vDP[r2-1][c2] - vDP[r1-1][c2] - vDP[r2-1][c1-1] + vDP[r1-1][c1-1];
    printf("%d\n", ret);
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