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
typedef pair<ll, ll> pllll;

int main() {
  ll x;
  scanf("%lld", &x);
  ll lastBig = x;
  set<pllll> ret;
  for(ll i = 1; i <= 2000000; i++) {
    ll low = i;
    ll high = lastBig;
    ll t2 = (i-1L)*(i)/2L;
    ll t3 = (i*(i-1L)*(2L*i-1))/6;
    while(low <= high) {
      ll n = (low+high)/2;
      ll mid = n;
      ll term1 = i*i*n;
      ll term2 = t2*(i+mid);
      ll term3 = t3;
      if(term1-term2+term3 == x) {
        lastBig = mid-1;
        ret.insert(pllll(i, mid));
        ret.insert(pllll(mid, i));
        break;
      }
      else if(term1-term2+term3 < x) {
        low = mid+1;
      }
      else {
        high = mid-1;
        lastBig = mid-1;
      }
    }
  }
  printf("%d\n", ret.size());
  for(set<pllll>::iterator it = ret.begin(); it != ret.end(); it++) {
    printf("%lld %lld\n", it->first, it->second);
  }
  return 0;
}