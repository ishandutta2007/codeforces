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

char a[1000005];
char b[1000005];

void solve() {
  gets(a);
  gets(b);
  int aLen = strlen(a);
  int bLen = strlen(b);
  int aStart = 0;
  int bStart = 0;
  while(aStart < aLen && a[aStart] == '0') aStart++;
  if(aStart == aLen) aStart--;
  while(bStart < bLen && b[bStart] == '0') bStart++;
  if(bStart == bLen) bStart--;
  if(aLen-aStart != bLen-bStart) {
    if(aLen-aStart > bLen-bStart) {
      printf(">\n");
      return;
    }
    printf("<\n");
    return;
  }
  while(aStart != aLen) {
    int diff = a[aStart++] - b[bStart++];
    if(diff < 0) {
      printf("<\n");
      return;
    }
    if(diff > 0) {
      printf(">\n");
      return;
    }
  }
  printf("=\n");
}

int main() {
  solve();
  return 0;
}