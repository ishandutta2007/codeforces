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
const double PI = 2 * acos(0);
const int MOD = 1000000007;

int r, c;

int grid[25][25];

void swapCol(int x, int y) {
  for(int i = 0; i < r; i++) {
    grid[i][x] ^= grid[i][y];
    grid[i][y] ^= grid[i][x];
    grid[i][x] ^= grid[i][y];
  }
}

bool valid() {
  for(int i = 0; i < r; i++) {
    int bad = 0;
    for(int j = 0; j < c; j++) {
      if(grid[i][j] != j) bad++;
    }
    if(bad > 2) return false;
  }
  return true;
}

void solve() {
  scanf("%d%d", &r, &c);
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      scanf("%d", &grid[i][j]);
      grid[i][j]--;
    }
  }
  if(valid()) {
    printf("YES\n");
    return;
  }
  for(int j = 0; j < c; j++) {
    for(int k = j+1; k < c; k++) {
      swapCol(j, k);
      if(valid()) {
        printf("YES\n");
        return;
      }
      swapCol(j, k);
    }
  }
  printf("NO\n");
}

int main() {
  solve();
  return 0;
}