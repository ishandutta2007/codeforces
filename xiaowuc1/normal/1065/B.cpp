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

int main() {
  ll n, m;
  scanf("%lld%lld", &n, &m);
  ll lhs = max(0LL, n-2LL*m);
  ll maxS = 0;
  if(m) maxS = 2;
  while(maxS * (maxS-1) / 2 < m) maxS++;
  printf("%lld %lld\n", lhs, n-maxS);
}