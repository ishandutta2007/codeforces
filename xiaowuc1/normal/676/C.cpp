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

char buf[100005];

int n, k;

void solve() {
  scanf("%d%d\n", &n, &k);
  gets(buf);
  vector<int> v;
  int ret = 0;
  for(int i = 0; i < n;) {
    int j = i+1;
    while(j < n && buf[i] == buf[j]) {
      j++;
    }
    v.push_back(j-i);
    ret = max(ret, j-i);
    i = j;
  }
  // good are even
  {
    int added = 0;
    int converted = 0;
    int lhs = 0;
    for(int i = 0; i < v.size(); i++) {
      if(i % 2 == 0) {
        added += v[i];
      }
      else {
        converted += v[i];
        while(converted > k) {
          if(lhs % 2 == 0) {
            added -= v[lhs];
          }
          else {
            converted -= v[lhs];
          }
          lhs++;
        }
      }
      ret = max(ret, added + k);
    }
  }
  // good are odd
  {
    int added = 0;
    int converted = 0;
    int lhs = 0;
    for(int i = 0; i < v.size(); i++) {
      if(i%2 == 1) {
        added += v[i];
      }
      else {
        converted += v[i];
        while(converted > k) {
          if(lhs % 2 == 1) {
            added -= v[lhs];
          }
          else {
            converted -= v[lhs];
          }
          lhs++;
        }
      }
      ret = max(ret, added + k);
    }
  }
  printf("%d\n", min(ret, n));
}

int main() {
  solve();
  return 0;
}