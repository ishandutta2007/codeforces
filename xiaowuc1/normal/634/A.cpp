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
const double PI = 2 * acos(0);
const int MOD = 1000000007;

void io(int n, vector<int>& v) {
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if(t) {
      v.push_back(t);
    }
  }
}

void solve() {
  int n;
  vector<int> a, b;
  scanf("%d", &n);
  io(n, a);
  io(n, b);
  int ai = 0;
  int bi = 0;
  while(a[ai] != 1) ai++;
  while(b[bi] != 1) bi++;
  int m = 0;
  for(int i = 0; i < a.size(); i++) {
    if(a[(ai+i)%a.size()] == b[(bi+i)%b.size()]) m++;
  }
  if(m == n-1) printf("YES\n");
  else printf("NO\n");
}

int main() {
  solve();
  return 0;
}