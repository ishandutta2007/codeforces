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

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> edges[100005];

int dp[100005];

set<int> bad[100005];

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    edges[a].push_back(pii(b, d));
    edges[b].push_back(pii(a, d));
  }
  for(int i = 1; i <= n; i++) {
    int amt;
    scanf("%d", &amt);
    while(amt--) {
      int t;
      scanf("%d", &t);
      bad[i].insert(t);
    }
  }
  for(int i = 1; i <= n; i++) {
    dp[i] = 2e9;
  }
  dp[1] = 0;
  priority_queue<pii> q;
  q.push(pii(0, 1));
  while(!q.empty()) {
    pii curr = q.top();
    q.pop();
    int currLoc = curr.second;
    int currWeight = -curr.first;
    if(dp[currLoc] != currWeight) {
      continue;
    }
    int actualStart = currWeight;
    while(bad[currLoc].count(actualStart)) {
      actualStart++;
    }
    for(int i = 0; i < edges[currLoc].size(); i++) {
      int nextLoc = edges[currLoc][i].first;
      int nextW = actualStart + edges[currLoc][i].second;
      if(nextW < dp[nextLoc]) {
        dp[nextLoc] = nextW;
        q.push(pii(-nextW, nextLoc));
      }
    }
  }
  if(dp[n] == 2e9) dp[n] = -1;
  printf("%d\n", dp[n]);
}

int main() {
  solve();
  return 0;
}