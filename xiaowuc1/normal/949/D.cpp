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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;

int n, d, b;
int l[100005];
int pref[100005];

bool solve(int maxAllowed) {
  for(int i = 0; i < n/2; i++) {
    if(i >= maxAllowed) {
      ll prefLatest = min((ll)n, (i+1) + d*(ll)(i+1));
      ll suffLatest = max((ll)0, (n-1-i) - (d*(ll)(i+1)));
      if(pref[prefLatest] < (i-maxAllowed+1LL)*b) {
        return false;
      }
      if(pref[n] - pref[suffLatest] < (i-maxAllowed+1LL)*b) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d%d%d", &n, &d, &b);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
    pref[i+1] = pref[i] + l[i];
  }
  int lhs = 0;
  int rhs = n/2+1;
  while(lhs != rhs) {
    int mid = (lhs+rhs)/2;
    if(solve(mid)) {
      rhs = mid;
    }
    else {
      lhs = mid+1;
    }
  }
  printf("%d\n", lhs);
}