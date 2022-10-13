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

const double PI = 2 * acos(0);
typedef long long ll;
typedef pair<int, int> pii;

// DID YOU FIX GLOBAL STATE

int n, a, b;
bool can[105];
int p[105];

char buf[105];

void solve() {
  scanf("%d%d%d", &n, &a, &b);
  can[0] = true;
  gets(buf);
  gets(buf);
  for(int i = 0; i <= n; i++) {
    if(can[i] && i+a <= n) {
      can[i+a] = true;
      p[i+a] = a;
    }
    if(can[i] && i+b <= n) {
      can[i+b] = true;
      p[i+b] = b;
    }
  }
  if(!can[strlen(buf)]) {
    printf("-1\n");
    return;
  }
  vector<pii> v;
  int now = strlen(buf);
  while(now > 0) {
    v.push_back(pii(now-p[now], now));
    now -= p[now];
  }
  printf("%d\n", v.size());
  for(int i = v.size()-1; i >= 0; i--) {
    for(int a = v[i].first; a < v[i].second; a++) {
      printf("%c", buf[a]);
    }
    printf("\n");
  }
}

int main() {
  solve();
  return 0;
}