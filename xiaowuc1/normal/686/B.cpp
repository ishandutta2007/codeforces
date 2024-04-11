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

int l[101];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &l[i]);
  }
  while(true) {
    bool upd = false;
    for(int i = 1; i < n; i++) {
      if(l[i] > l[i+1]) {
        printf("%d %d\n", i, i+1);
        l[i] ^= l[i+1];
        l[i+1] ^= l[i];
        l[i] ^= l[i+1];
        upd = true;
      }
    }
    if(!upd) break;
  }
  return 0;
}