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

int n;
int to[200005];
int ret[200005];

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &to[i]);
    to[i]--;
    ret[i] = 1e9;
  }
  ret[0] = 0;
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    if(ret[to[curr]] == 1e9) {
      ret[to[curr]] = ret[curr] + 1;
      q.push(to[curr]);
    }
    if(curr > 0 && ret[curr-1] == 1e9) {
      ret[curr-1] = ret[curr] + 1;
      q.push(curr-1);
    }
    if(curr < n-1 && ret[curr+1] == 1e9) {
      ret[curr+1] = ret[curr] + 1;
      q.push(curr+1);
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%d", ret[i]);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}