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

const double PI = 2 * acos(0);

char grid[105][105];

int have[105];

int n;

bool can() {
  for(int i = 0; i < n; i++) {
    if(have[i] == 0) return true;
  }
  return false;
}

void solve() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++) {
    gets(grid[i]);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &have[i]);
  }
  vector<int> ret;
  while(can()) {
    int index = 0;
    while(have[index] != 0) index++;
    ret.push_back(index);
    for(int i = 0; i < n; i++) {
      if(grid[index][i] == '1' || index == i) have[i]--;
    }
  }
  printf("%d\n", ret.size());
  if(ret.empty()) {
    printf("\n");
    return;
  }
  for(int i = 0; i < ret.size(); i++) {
    printf("%d", ret[i]+1);
    if(i+1 == ret.size()) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}