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
  ll s, a, b, c;
  scanf("%lld %lld %lld %lld", &s, &a, &b, &c);
  ll amt = s/c;
  ll ret = amt + (amt / a) * b;
  printf("%lld\n", ret);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}