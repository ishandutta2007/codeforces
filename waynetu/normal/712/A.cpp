#include <cstdio>
#define ll long long int
using namespace std;

inline ll rit() {
  ll t = 0, k = 1;
  char c;
  do {
    c = getchar();
    if (c == '-') k = -1;
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar();
  } while (c >= '0' && c <= '9');
  return t * k;
}

int main() {
  ll n;
  ll a[100000];
  ll b[100000];
  n = rit();
  // printf("%lld", n);
  for (ll i = 0; i < n; ++i) {
    a[i] = rit();
  }
  b[n - 1] = a[n - 1];
  for (ll i = n - 2; i >= 0; --i) {
    b[i] = a[i + 1] + a[i];
  }
  for (ll i = 0; i < n; ++i) printf("%lld ", b[i]);
  return 0;
}