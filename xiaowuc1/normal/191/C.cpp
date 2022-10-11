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

typedef long long ll;
typedef pair<int, int> pii;

const int MAX_DEPTH = 18;

int lca[100005][MAX_DEPTH];
int depth[100005];

vector<pii> edges[100005];

int dp[100005];
int ret[100005];
int numChildren[100005];

queue<int> q;

int n;

void dfs(int curr, int par) {
  int children = 0;
  for(int i = 0; i < edges[curr].size(); i++) {
    int cand = edges[curr][i].first;
    if(lca[curr][0] == cand) continue;
    numChildren[curr]++;
    depth[cand] = depth[curr] + 1;
    lca[cand][0] = curr;
    dfs(cand, curr);
  }
  if(numChildren[curr] == 0) {
    q.push(curr);
  }
}

int getLCA(int a, int b) {
  if(depth[a] > depth[b]) return getLCA(b, a);
  for(int d = MAX_DEPTH-1; d >= 0; d--) {
    while(depth[b] - (1<<d) >= depth[a]) {
      b = lca[b][d];
    }
  }
  for(int d = MAX_DEPTH-1; d >= 0; d--) {
    while(lca[a][d] != lca[b][d]) {
      a = lca[a][d];
      b = lca[b][d];
    }
  }
  while(a != b) {
    a = lca[a][0];
    b = lca[b][0];
  }
  return a;
}

bool solve() {
  scanf("%d", &n);
  for(int i = 0; i < n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    edges[a].push_back(pii(b, i));
    edges[b].push_back(pii(a, i));
  }
  lca[1][0] = 1;
  dfs(1, -1);
  for(int d = 1; d < MAX_DEPTH; d++) {
    for(int i = 1; i <= n; i++) {
      lca[i][d] = lca[lca[i][d-1]][d-1];
    }
  }
  int qqq;
  scanf("%d", &qqq);
  while(qqq--) {
    int a, b;
    scanf("%d%d", &a, &b);
    dp[getLCA(a,b)]-=2;
    dp[a]++;
    dp[b]++;
  }
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(int i = 0; i < edges[curr].size(); i++) {
      int cand = edges[curr][i].first;
      if(cand == lca[curr][0]) {
        ret[edges[curr][i].second] = dp[curr];
        dp[edges[curr][i].first] += dp[curr];
        if(--numChildren[edges[curr][i].first] == 0) {
          q.push(edges[curr][i].first);
        }
      }
    }
  }
  for(int i = 0; i < n-1; i++) {
    printf("%d", ret[i]);
    if(i == n-2) printf("\n");
    else printf(" ");
  }
  return false;
}

int main() {
  while(solve());
  return 0;
}