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
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

const double PI = 2 * acos(0);
typedef long long ll;
typedef pair<int, int> pii;

char buf[200005];

int cnt[256];

void solve() {
  gets(buf);
  int len = strlen(buf);
  for(int i = 0; i < len; i++) {
    cnt[buf[i]]++;
  }
  int l = 0;
  int r = 255;
  while(l < r) {
    if(cnt[l] % 2 == 0) {
      l++;
    }
    else if(cnt[r] % 2 == 0) {
      r--;
    }
    else {
      cnt[l++]++;
      cnt[r--]--;
    }
  }
  l = 0;
  r = len-1;
  int m = (l+r)/2;
  for(int i = 0; i < 256; i++) {
    if(cnt[i] % 2 == 1) {
      cnt[i]--;
      buf[m] = i;
    }
    while(cnt[i] > 0) {
      cnt[i] -= 2;
      buf[l++] = i;
      buf[r--] = i;
    }
  }
  printf("%s\n", buf);
}

int main() {
  solve();
  return 0;
}