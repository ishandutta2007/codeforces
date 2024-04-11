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

void solve() {
  int d, h, v, e;
  scanf("%d%d%d%d", &d, &h, &v, &e);
  double dec = v;
  dec -= e / 4.0 * d * d * PI;
  if(dec <= 0) {
    printf("NO\n");
    return;
  }
  double amt = d*1.0*d/4 * PI * h;
  printf("YES\n%.9f\n", amt / dec);
}

int main() {
  solve();
  return 0;
}