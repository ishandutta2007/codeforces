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
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;

ll gcd(ll a, ll b) {
  if(a==0) return b;
  if(b==0) return a;
  return gcd(b, a%b);
}

inline ll mult(ll a, ll b, ll m) {
  a %= m;
  b %= m;
  ll r = 0;
  while(b > 0) {
    if(b%2==1) {
      r += a;
      if(r >= m) r -= m;
    }
    a *= 2;
    if(a >= m) a -= m;
    b /= 2;
  }
  return r;
}

inline ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r = mult(r, b, m);
    }
    b = mult(b, b, m);
    e/=2;
  }
  return r;
}
void solve() {
  ll p, q, b;
  scanf("%lld %lld %lld", &p, &q, &b);
  ll g = gcd(p, q);
  p /= g;
  q /= g;
  if(p == 0 || q == 1) {
    printf("Finite\n");
    return;
  }
  ll other = modpow(b, 64, q);
  if(other){
    printf("Infinite\n");
  }
  else {
    printf("Finite\n");
  }
}

int main() {
  int qq;
  scanf("%d", &qq);
  while(qq--) solve();
}