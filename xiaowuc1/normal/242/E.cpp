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

int tree[20][400009];
bool lazy[20][400009];

void pushDown(int treeIndex, int posIndex, int l, int r) {
  if(lazy[treeIndex][posIndex]) {
    lazy[treeIndex][2*posIndex] = !lazy[treeIndex][2*posIndex];
    lazy[treeIndex][2*posIndex+1] = !lazy[treeIndex][2*posIndex+1];
    lazy[treeIndex][posIndex] = false;
  }
}

int eval(int treeIndex, int posIndex, int l, int r) {
  int totalAmt = r-l+1;
  int now = tree[treeIndex][posIndex];
  if(lazy[treeIndex][posIndex]) {
    now = totalAmt - now;
  }
  return now;
}

void pullUp(int treeIndex, int posIndex, int l, int r) {
  int m = (l+r)/2;
  tree[treeIndex][posIndex] = eval(treeIndex, 2*posIndex, l, m);
  tree[treeIndex][posIndex] += eval(treeIndex, 2*posIndex+1, m+1, r);
}

void flip(int treeIndex, int posIndex, int lI, int rI, int lhs, int rhs) {
  if(rhs < lI || lhs > rI) return;
  if(lI >= lhs && rI <= rhs) {
    lazy[treeIndex][posIndex] = !lazy[treeIndex][posIndex];
    return;
  }
  pushDown(treeIndex, posIndex, lI, rI);
  int mI = (lI + rI) / 2;
  flip(treeIndex, 2*posIndex, lI, mI, lhs, rhs);
  flip(treeIndex, 2*posIndex+1, mI+1, rI, lhs, rhs);
  pullUp(treeIndex, posIndex, lI, rI);
}

void flip(int treeIndex, int l, int r) {
  flip(treeIndex, 1, 0, n-1, l, r);
}

int query(int treeIndex, int posIndex, int lI, int rI, int lhs, int rhs) {
  if(rhs < lI || lhs > rI) return 0;
  if(lI >= lhs && rI <= rhs) {
    return eval(treeIndex, posIndex, lI, rI);
  }
  pushDown(treeIndex, posIndex, lI, rI);
  int mI = (lI + rI) / 2;
  int ret = query(treeIndex, 2*posIndex, lI, mI, lhs, rhs);
  ret += query(treeIndex, 2*posIndex+1, mI+1, rI, lhs, rhs);
  pullUp(treeIndex, posIndex, lI, rI);
  return ret;
}

int query(int treeIndex, int l, int r) {
  return query(treeIndex, 1, 0, n-1, l, r);
}

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    for(int a = 0; a < 20; a++) {
      if(t&(1<<a)) {
        flip(a, i, i);
      }
    }
  }
  int qqq;
  scanf("%d", &qqq);
  while(qqq--) {
    int op;
    scanf("%d", &op);
    if(op == 1) {
      int lhs, rhs;
      scanf("%d%d", &lhs, &rhs);
      lhs--;
      rhs--;
      ll ret = 0;
      for(int a = 0; a < 20; a++) {
        ret += (1LL << a) * query(a, lhs, rhs);
      }
      printf("%lld\n", ret);
    }
    else {
      int lhs, rhs, val;
      scanf("%d%d%d", &lhs, &rhs, &val);
      lhs--;
      rhs--;
      for(int a = 0; a < 20; a++) {
        if(val&(1<<a)) {
          flip(a, lhs, rhs);
        }
      }
    }
  }
}

int main() {
  solve();
  return 0;
}