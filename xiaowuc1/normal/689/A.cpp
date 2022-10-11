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

char buf[105];

void solve() {
  vector<pii> v;
  gets(buf);
  gets(buf);
  for(int i = 0; i < strlen(buf); i++) {
    int val = buf[i] - '0';
    if(val == 0) {
      v.push_back(pii(3, 1));
    }
    else {
      val--;
      v.push_back(pii(val/3, val%3));
    }
  }
  for(int dx = -3; dx <= 3; dx++) {
    for(int dy = -1; dy <= 3; dy++) {
      if(dx == 0 && dy == 0) continue;
      int can = 0;
      for(int i = 0; i < v.size(); i++) {
        int nx = v[i].first + dx;
        int ny = v[i].second + dy;
        if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
          can++;
        }
        else if(nx == 3 && ny == 1) can++;
      }
      if(can == v.size()) {
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n");
}

int main() {
  solve();
  return 0;
}