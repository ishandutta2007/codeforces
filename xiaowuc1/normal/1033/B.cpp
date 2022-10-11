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

void solve() {
  ll a, b;
  scanf("%lld %lld", &a, &b);
  if(a-b != 1) {
    printf("NO\n");
    return;
  }
  ll n = a+b;
  for(ll i = 2; i * i <= n; i++) {
    if(n%i==0) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}

int main() {
  int qq;
  scanf("%d", &qq);
  while(qq--) solve();
}