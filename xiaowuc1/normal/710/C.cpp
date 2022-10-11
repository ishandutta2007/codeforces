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

int ret[50][50];

int main() {
  int n;
  scanf("%d", &n);
  int val = 1;
  int x = 0;
  int y = n/2;
  while(val <= n*n) {
    ret[x][y] = val++;
    if(ret[(x+n-1)%n][(y+1)%n]) {
      x++;
      x %= n;
    }
    else {
      x += n-1;
      x %= n;
      y++;
      y %= n;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d", ret[i][j]);
      if(j == n-1) printf("\n");
      else printf(" ");
    }
  }
  return 0;
}