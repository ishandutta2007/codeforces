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

vector<int> edges[100005];
char ret[100005];

int treesize[100005];

bool invalid[100005];

void dfsSize(int curr, int par) {
  treesize[curr] = 1;
  for(int i = 0; i < edges[curr].size(); i++) {
    int cand = edges[curr][i];
    if(cand == par || invalid[cand]) continue;
    dfsSize(cand, curr);
    treesize[curr] += treesize[cand];
  }
}

void dfsSolve(int curr, int depth) {
  assert(depth <= 26);
  assert(!invalid[curr]);
  dfsSize(curr, -1);
  if(treesize[curr] == 1) {
    ret[curr] = (char)('A' + depth);
    return;
  }
  int par = curr;
  int rootedat = curr;
  int fullsize = treesize[curr];
  while(true) {
    bool upd = false;
    for(int i = 0; i < edges[curr].size(); i++) {
      int cand = edges[curr][i];
      if(cand == par || invalid[cand]) continue;
      if(2*treesize[cand] >= fullsize) {
        par = curr;
        curr = cand;
        upd = true;
        break;
      }
    }
    if(!upd) break;
  }
  ret[curr] = (char)('A' + depth);
  invalid[curr] = true;
  for(int i = 0; i < edges[curr].size(); i++) {
    int cand = edges[curr][i];
    if(!invalid[cand]) {
      dfsSolve(cand, depth+1);
    }
  }
}

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  dfsSolve(0, 0);
  for(int i = 0; i < n; i++) {
    printf("%c", ret[i]);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}