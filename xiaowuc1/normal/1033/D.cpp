#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

map<ll, int> semiprimes;
map<ll, int> primeToPower;

ll gcd(ll a, ll b) {
  return a%b==0 ? b : gcd(b, a%b);
}

void genAll() {
  for(auto x: semiprimes) {
    for(auto y: semiprimes) {
      if(x.first == y.first) break;
      ll gg = gcd(x.first, y.first);
      if(gg != 1) {
        primeToPower[gg] = primeToPower[gg];
        primeToPower[x.first/gg] = primeToPower[x.first/gg];
        primeToPower[y.first/gg] = primeToPower[y.first/gg];
      }
    }
  }
}

bool fourth(ll x) {
  ll lhs = 1;
  ll rhs = 50000;
  while(lhs <= rhs) {
    ll mid = (lhs+rhs)/2;
    ll c = mid*mid*mid*mid;
    if(c == x) {
      primeToPower[mid] += 4;
      return true;
    }
    if(c > x) rhs = mid-1;
    else lhs = mid+1;
  }
  return false;
}

bool third(ll x) {
  ll lhs = 1;
  ll rhs = 2000000;
  while(lhs <= rhs) {
    ll mid = (lhs+rhs)/2;
    ll c = mid*mid*mid;
    if(c == x) {
      primeToPower[mid] += 3;
      return true;
    }
    if(c > x) rhs = mid-1;
    else lhs = mid+1;
  }
  return false;
}

bool second(ll x) {
  ll lhs = 1;
  ll rhs = 2000000000;
  while(lhs <= rhs) {
    ll mid = (lhs+rhs)/2;
    ll c = mid*mid;
    if(c == x) {
      primeToPower[mid] += 2;
      return true;
    }
    if(c > x) rhs = mid-1;
    else lhs = mid+1;
  }
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    ll x;
    scanf("%lld", &x);
    if(fourth(x)) continue;
    if(third(x)) continue;
    if(second(x)) continue;
    semiprimes[x]++;
  }
  genAll();
  vector<ll> allP;
  for(auto x: primeToPower) {
    allP.push_back(x.first);
  }
  ll ret = 1;
  for(auto v: semiprimes) {
    ll t = v.first;
    int scale = v.second;
    bool divided = false;
    for(ll out: allP) {
      while(t%out == 0) {
        t /= out;
        divided = true;
        primeToPower[out] += scale;
      }
      if(out == 1) break;
    }
    if(t > 1) {
      if(divided) {
        ret *= (scale+1);
      }
      else {
        ret *= (scale+1);
        ret %= 998244353;
        ret *= (scale+1);
      }
      ret %= 998244353;
    }
  }
  for(auto x: primeToPower) {
    ret *= x.second + 1;
    ret %= 998244353;
  }
  printf("%lld\n", ret);
}