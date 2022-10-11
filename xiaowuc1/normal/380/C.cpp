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

int retTree[4000009];
int openTree[4000009];
int closeTree[4000009];

char buf[1000005];
int bufLen;

pipii combine(pipii l, pipii r) {
  int ret = l.first + r.first;
  int canAdd = min(l.second.first, r.second.second);
  ret += canAdd;
  int opens = l.second.first + r.second.first - canAdd;
  int closes = l.second.second + r.second.second - canAdd;
  return pipii(ret, pii(opens, closes));
}

void init(int index, int l, int r) {
  if(l == r) {
    if(buf[l] == '(') {
      openTree[index] = 1;
    }
    else {
      closeTree[index] = 1;
    }
  }
  else {
    int m = (l + r) / 2;
    init(2*index, l, m);
    init(2*index+1, m+1, r);
    pipii ret = combine(
      pipii(retTree[2*index], pii(openTree[2*index], closeTree[2*index])),
      pipii(retTree[2*index+1], pii(openTree[2*index+1], closeTree[2*index+1]))
    );
    retTree[index] = ret.first;
    openTree[index] = ret.second.first;
    closeTree[index] = ret.second.second;
  }
}

pipii query(int index, int l, int r, int leftIndex, int rightIndex) {
  if(l > rightIndex || r < leftIndex) {
    return pipii(0, pii(0, 0));
  }
  if(l >= leftIndex && r <= rightIndex) {
    return pipii(retTree[index], pii(openTree[index], closeTree[index]));
  }
  int m = (l+r)/2;
  return combine(
    query(2*index, l, m, leftIndex, rightIndex),
    query(2*index+1, m+1, r, leftIndex, rightIndex)
  );
}

int query(int l, int r) {
  return query(1, 0, bufLen-1, l, r).first;
}

void solve() {
  gets(buf);
  bufLen = strlen(buf);
  init(1, 0, bufLen-1);
  int qqq;
  scanf("%d", &qqq);
  while(qqq--) {
    int lhs, rhs;
    scanf("%d%d", &lhs, &rhs);
    printf("%d\n", 2 * query(--lhs, --rhs));
  }
}

int main() {
  solve();
  return 0;
}