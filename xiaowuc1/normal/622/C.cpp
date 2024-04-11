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
typedef pair<int, pii> pipii;

const int MOD = 1000000007;

int n;
int minTree[1000000];
int maxTree[1000000];

int l[200005];

set<int> indices[1000005];

void init(int index, int lI, int rI) {
  if(lI == rI) {
    minTree[index] = l[lI];
    maxTree[index] = l[lI];
  }
  else {
    int m = (lI+rI)/2;
    init(2*index, lI, m);
    init(2*index+1, m+1, rI);
    minTree[index] = min(minTree[2*index], minTree[2*index+1]);
    maxTree[index] = max(maxTree[2*index], maxTree[2*index+1]);
  }
}

pii query(int index, int l, int r, int leftIndex, int rightIndex) {
  if(l > rightIndex || r < leftIndex) {
    return pii(1e9, -1e9);
  }
  if(l >= leftIndex && r <= rightIndex) {
    return pii(minTree[index], maxTree[index]);
  }
  int m = (l+r)/2;
  pii lhs = query(2*index, l, m, leftIndex, rightIndex);
  pii rhs = query(2*index+1, m+1, r, leftIndex, rightIndex);
  return pii(min(lhs.first, rhs.first), max(lhs.second, rhs.second));
}

pii query(int l, int r) {
  return query(1, 0, n-1, l, r);
}

void solve() {
  int m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
    indices[l[i]].insert(i+1);
  }
  init(1, 0, n-1);
  while(m--) {
    int l, r, v;
    scanf("%d%d%d", &l, &r, &v);
    l--;
    r--;
    pii rangeRet = query(l, r);
    if(rangeRet.first != v) {
      printf("%d\n", *indices[rangeRet.first].upper_bound(l));
    }
    else if(rangeRet.second != v) {
      printf("%d\n", *indices[rangeRet.second].upper_bound(l));
    }
    else {
      printf("-1\n");
    }
  }
}

int main() {
  solve();
  return 0;
}