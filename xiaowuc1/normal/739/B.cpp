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

int n;
ll w[200005];
int anc[200005][20];
ll len[200005][20];

vector<int> children[200005];

int ret[200005];

void dfs(int curr) {
  for(int i = 0; i < children[curr].size(); i++) {
    dfs(children[curr][i]);
    ret[curr] += ret[children[curr][i]];
  }
}

int main() {
  scanf("%d", &n);

  for(int i = 1; i <= n; i++) {
    scanf("%lld", &w[i]);
  }
  anc[1][0] = 0;
  len[1][0] = 1e18;
  children[0].push_back(1);
  for(int i = 2; i <= n; i++) {
    scanf("%d %lld", &anc[i][0], &len[i][0]);
    children[anc[i][0]].push_back(i);
  }
  for(int d = 1; d < 20; d++) {
    for(int i = 1; i <= n; i++) {
      anc[i][d] = anc[anc[i][d-1]][d-1];
      len[i][d] = len[i][d-1] + len[anc[i][d-1]][d-1];
    }
  }

  for(int i = 1; i <= n; i++) {
    ret[anc[i][0]]++;
    int curr = i;
    int scale = 19;
    ll left = w[i];
    while(scale >= 0) {
      if(len[curr][scale] <= left) {
        left -= len[curr][scale];
        curr = anc[curr][scale];
      }
      else {
        scale--;
      }
    }
    ret[anc[curr][0]]--;
  }

  dfs(0);

  for(int i = 1; i <= n; i++) {
    printf("%d ", ret[i]);
  }
  printf("\n");
  return 0;
}