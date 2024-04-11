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

int appear[100005];
int cnt[100005];

unordered_map<int, int> cache[100005];

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int curr;
    scanf("%d", &curr);
    unordered_map<int, int> &m = cache[curr];
    if(m.size() == 0) {
      for(int a = 0; true; a++) {
        if((curr >> a) == 0) break;
        int now = curr >> a;
        if(appear[now] < i) continue;
        for(int b = 0; now <= 100000; b++) {
          if(!m.count(now)) {
            m[now] = a+b;
          }
          else {
            break;
          }
          now <<= 1;
        }
      }
    }
    for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
      appear[it->first]++;
      cnt[it->first] += it->second;
    }
  }
  int ret = 1e9;
  for(int i = 1; i <= 100000; i++) {
    if(appear[i] == n) {
      ret = min(ret, cnt[i]);
    }
  }
  printf("%d\n", ret);
}

int main() {
  solve();
  return 0;
}