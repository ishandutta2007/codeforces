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
typedef pair<pii, int> ppiii;

const int MOD = 1000000007;

vector<int> edges[100005];
int treesize[100005];

void dfs(int curr) {
  for(int i = 0; i < edges[curr].size(); i++) {
    dfs(edges[curr][i]);
    treesize[curr] += treesize[edges[curr][i]];
  }
  treesize[curr]++;
}

double ret[100005];
void dfsAgain(int curr, double t) {
  ret[curr] = t;
  for(int i = 0; i < edges[curr].size(); i++) {
    int inOur = treesize[edges[curr][i]];
    int out = treesize[curr] - 1 - inOur;
    dfsAgain(edges[curr][i], t + 1 + .5 * out);
  }
}

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    edges[p].push_back(i);
  }
  dfs(0);
  dfsAgain(0, 1);
  for(int i = 0; i < n; i++) {
    printf("%.9f", ret[i]);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}