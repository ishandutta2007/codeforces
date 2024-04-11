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

queue<ll> lhs;
queue<ll> rhs;

bool check(ll x, ll p, ll n) {
  // is x^p <= n
  ll curr = 1;
  while(p--) {
    ll above = n/x;
    if(curr > above) return false;
    curr *= x;
  }
  return curr <= n;
}

ll solve(ll p, ll n, ll rhs) {  
  // x^p <= n, how many x?
  ll lhs = 1;
  while(lhs != rhs) {
    ll mid = (lhs+rhs+1)/2;
    if(check(mid, p, n)) {
      lhs = mid;
    }
    else {
      rhs = mid-1;
    }
  }
  return lhs;
}

bool sqfree[100];
int numP[100];

void init() {
  for(int a = 1; a <= 60; a++) {
    sqfree[a] = true;
  }
  for(int i = 2; i < 100; i++) {
    for(int j = i*i; j < 100; j += i*i) {
      sqfree[j] = false;
    }
    if(numP[i] == 0) {
      for(int j = i; j < 100; j+=i) {
        numP[j]++;
      }
    }
  }
}

ll actual[65];

void solve() {
  ll n;
  scanf("%lld", &n);
  ll ret = n-1; // do not count 1!
  ll last = actual[1];
  for(int i = 2; i <= 60; i++) {
    if(!sqfree[i]) continue;
    actual[i] = solve(i, n, last);
    last = actual[i];
  }
  for(int p = 2; p <= 60; p++) {
    if(!sqfree[p]) continue;
    if(numP[p]%2)
      ret -= actual[p] - 1; // do not count 1!
    else
      ret += actual[p] - 1; // do not count 1!
  }
  printf("%lld\n", ret);
}

int main() {
  init();
  actual[1] = 1000000000;
  int qq;
  scanf("%d", &qq);
  while(qq--) solve();
}