#include <algorithm>
#include <cassert>
// #include <chrono>
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
// #include <random>
#include <set>
#include <stack>
#include <string>
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
typedef pair<string, string> pss;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

int l[1000000];

int main() {
  int n, g;
  scanf("%d%d", &n, &g);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  sort(l, l+n);
  ll ret = (ll)abs(l[n/2] - g);
  l[n/2] = g;
  for(int i = n/2-1; i >= 0; i--) {
    if(l[i] > l[i+1]) {
      ret += l[i] - l[i+1];
      l[i] = l[i+1];
    }
    else {
      break;
    }
  }
  for(int i = n/2+1; i < n; i++) {
    if(l[i] < l[i-1]) {
      ret += l[i-1] - l[i];
      l[i] = l[i-1];
    }
    else {
      break;
    }
  }
  printf("%lld\n", ret);
}