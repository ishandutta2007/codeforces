#include <iostream>
#include <memory>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;

int n;

int a[1005];
int b[1005];

bool indexUsed[1005];
bool valUsed[1005];

int ret[1005];

bool match() {
  int aError = 0;
  int bError = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] != ret[i]) aError++;
    if(b[i] != ret[i]) bError++;
  }
  return aError == 1 && bError == 1;
}

void solveOne() {
  int idx = 0;
  while(indexUsed[idx]) idx++;
  int val = 1;
  while(valUsed[val]) val++;
  ret[idx] = val;
}

void solveTwo() {
  int lowIdx = 0;
  while(indexUsed[lowIdx]) lowIdx++;
  int highIdx = lowIdx+1;
  while(indexUsed[highIdx]) highIdx++;

  int lowVal = 1;
  while(valUsed[lowVal]) lowVal++;
  int highVal = lowVal+1;
  while(valUsed[highVal]) highVal++;

  ret[lowIdx] = lowVal;
  ret[highIdx] = highVal;
  if(!match()) {
    ret[lowIdx] = highVal;
    ret[highIdx] = lowVal;
  }
  assert(match());
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  for(int i = 0; i < n; i++) scanf("%d", &b[i]);
  int errors = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == b[i]) {
      ret[i] = a[i];
      indexUsed[i] = true;
      valUsed[a[i]] = true;
    }
    else {
      errors++;
    }
  }
  assert(errors == 1 || errors == 2);
  if(errors == 1) {
    solveOne();
  }
  else {
    solveTwo();
  }
  for(int i = 0; i < n; i++) {
    printf("%d", ret[i]);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
  return 0;
}