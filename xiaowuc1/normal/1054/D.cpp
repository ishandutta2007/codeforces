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

int n, k;
int l[200005];
int main() {
  scanf("%d%d", &n, &k);
  int maxV = (1<<k) - 1;
  map<int, int> dp;
  dp[0]++;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &l[i]);
    l[i] ^= l[i-1];
    int val = min(l[i], l[i] ^ maxV);
    dp[val]++;
  }
  ll total = n*(n+1LL) / 2;
  for(auto out: dp) {
    int rhs = out.second;
    int v = rhs/2;
    int w = rhs-v;
    total -= v*(v-1LL)/2;
    total -= w*(w-1LL)/2;
  }
  printf("%lld\n", total);
}