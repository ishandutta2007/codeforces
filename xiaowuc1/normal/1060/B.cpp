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

ll fast(ll n) {
  int len = 0;
  ll ret = 0;
  int dec = 0;
  int finalDec = 0;
  bool orig = true;
  while(n) {
    ret += n%10;
    if(n%10 == 9) dec++;
    else {
      if(orig) finalDec = dec;
      orig = false;
    }
    len++;
    n /= 10;
  }
  if(orig) finalDec = dec-1;
  ret += 9*(len-1);
  ret -= 9 * finalDec;
  return ret;
}

int s(ll n) {
  int r = 0;
  while(n) {
    r += n%10;
    n/=10;
  }
  return r;
}

ll slow(ll n) {
  ll ret = s(n);
  for(int i = 1; 2*i <= n; i++) {
    ret = max(ret, (ll)s(i) + s(n-i));
  }
  return ret;
}

int main() {
  ll n;
  scanf("%lld", &n);
  printf("%lld\n", fast(n));
}