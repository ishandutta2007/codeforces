#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;

int l[100005];
int n, qq;

set<pii> rages[20];

ll insert(int idx, int val) {
  ll ret = 1;
  rages[idx].insert(pii(val, 1));
  // merge above
  {
    set<pii>::iterator it = rages[idx].upper_bound(pii(val, 1));
    if(it != rages[idx].end() && it->first == val+1) {
      int newLen = it->second + 1;
      ret -= 1;
      ret -= (it->second) * (it->second+1LL) / 2;
      ret += (it->second+1LL) * (it->second+2LL) / 2;
      rages[idx].erase(it);
      rages[idx].erase(pii(val, 1));
      rages[idx].insert(pii(val, newLen));
    }
  }
  // merge below
  {
    set<pii>::iterator it = rages[idx].lower_bound(pii(val, 1));
    if(it != rages[idx].begin()) {
      pii orig = *it;
      it--;
      if(it->first + it->second == val) {
        ret -= (orig.second) * (orig.second+1LL) / 2;
        ret -= (it->second) * (it->second+1LL) / 2;
        int newLen = orig.second + it->second;
        ret += (newLen) * (newLen+1LL) / 2;
        int newFirst = it->first;
        rages[idx].erase(it);
        rages[idx].erase(orig);
        rages[idx].insert(pii(newFirst, newLen));
      }
    }
  }
  return ret;
}

ll erase(int idx, int val) {
  set<pii>::iterator it = rages[idx].upper_bound(pii(val, 1e9));
  it--;
  if(it->first == val) {
    if(it->second == 1) {
      rages[idx].erase(it);
      return -1;
    }
    int origLen = it->second;
    int origFirst = it->first;
    rages[idx].erase(it);
    rages[idx].insert(pii(origFirst+1, origLen-1));
    return -origLen;
  }
  if(it->first + it->second - 1 == val) {
    if(it->second == 1) {
      rages[idx].erase(it);
      return -1;
    }
    int origLen = it->second;
    int origFirst = it->first;
    rages[idx].erase(it);
    rages[idx].insert(pii(origFirst, origLen-1));
    return -origLen;
  }
  int origFirst = it->first;
  int origLen = it->second;
  ll ret = -(origLen) * (origLen + 1LL) / 2;
  rages[idx].erase(it);
  {
    // lhs
    rages[idx].insert(pii(origFirst, val - origFirst));
    ret += (val - origFirst) * (val - origFirst + 1LL) / 2;
  }
  {
    // rhs
    rages[idx].insert(pii(val+1, origLen - (val - origFirst) - 1));
    ret += (origLen - (val - origFirst) - 1LL) * (origLen - (val - origFirst)) / 2;
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &qq);
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
    for(int a = 0; a < 18; a++) {
      if(l[i] & (1<<a)) {
        ret += (1 << a) * insert(a, i);
      }
    }
  }
  while(qq--) {
    int idx, val;
    scanf("%d%d", &idx, &val);
    idx--;
    for(int a = 0; a < 18; a++) {
      if((l[idx] & (1<<a)) && (val & (1<<a)) == 0) {
        ret += (1 << a) * erase(a, idx);
      }
      else if((l[idx] & (1<<a)) == 0 && (val & (1<<a))) {
        ret += (1 << a) * insert(a, idx);
      }
    }
    l[idx] = val;
    printf("%lld\n", ret);
  }
  return 0;
}