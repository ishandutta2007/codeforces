#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <memory>
#include <complex>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int r, c, k;
char grid[55][55];
int amt[50][50];
bool seen[50][50];

void clear(int x, int y, int k) {
  if(x < 1 || x >= r-1 || y < 1 || y >= c-1) return;
  if(grid[x][y] != '.') return;
  amt[x][y] = 0;
  grid[x][y] = '*';
  clear(x+1,y,k);
  clear(x-1,y,k);
  clear(x,y-1,k);
  clear(x,y+1,k);
}

void setSize(int x, int y, int k) {
  if(x < 1 || x >= r-1 || y < 1 || y >= c-1) return;
  if(grid[x][y] != '.') return;
  assert(amt[x][y] == 0 || amt[x][y] == k);
  if(amt[x][y] == k) return;
  amt[x][y] = k;
  setSize(x+1,y,k);
  setSize(x-1,y,k);
  setSize(x,y-1,k);
  setSize(x,y+1,k);
}

int getSize(int x, int y) {
  if(x < 0 || x >= r || y < 0 || y >= c) return 0;
  if(grid[x][y] == '*') return 0;
  if(seen[x][y]) return 0;
  seen[x][y] = true;
  int ret = 1;
  if(x == 0 || x == r-1 || y == 0 || y == c-1) {
    ret = -10000;
  }
  ret += getSize(x-1, y);
  ret += getSize(x+1, y);
  ret += getSize(x, y-1);
  ret += getSize(x, y+1);
  return ret;
}

int main() {
  scanf("%d%d%d\n", &r, &c, &k);
  for(int i = 0; i < r; i++) {
    scanf("%s", grid[i]);
    for(int j = 0; j < c; j++) {
      assert(grid[i][j] == '*' || grid[i][j] == '.');
    }
  }
  vector<int> compSizes;
  for(int i = 1; i < r-1; i++) {
    for(int j = 1; j < c-1; j++) {
      if(seen[i][j]) continue;
      if(grid[i][j] == '*') continue;
      int sz = getSize(i, j);
      if(sz > 0) {
        compSizes.push_back(sz);
        setSize(i, j, sz);
      }
    }
  }
  int ans = 0;
  sort(compSizes.begin(), compSizes.end());
  for(int qq = 0; qq + k < compSizes.size(); qq++) {
    ans += compSizes[qq];
    bool found = false;
    for(int i = 1; !found && i < r-1; i++) {
      for(int j = 1; !found && j < c-1; j++) {
        if(amt[i][j] == compSizes[qq]) {
          clear(i, j, amt[i][j]);
          found = true;
        }
      }
    }
    assert(found);
  }
  printf("%d\n", ans);
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
  return 0;
}