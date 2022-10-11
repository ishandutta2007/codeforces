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
typedef pair<int, ll> pill;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

const int MOD = 998244353;

ll dp[205][2];
ll ndp[205][2];

void first() {
  int k;
  scanf("%d", &k);
  if(k == -1) {
    for(int i = 1; i <= 200; i++) {
      dp[i][1] = 1;
    }
  }
  else {
    dp[k][1] = 1;
  }
  for(int a = 1; a <= 200; a++) {
    dp[a][1] += dp[a-1][1];
    dp[a][0] += dp[a-1][0];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  n--;
  // dp[i][1] means that i must be less than or equal to the other value
  // dp[i][0] means that it's already been dominated
  // prefix sums
  first();
  while(n--) {
    int t;
    memset(ndp, 0, sizeof(ndp));
    scanf("%d", &t);
    if(t == -1) {
      for(int a = 1; a <= 200; a++) {
        ndp[a][1] = dp[a-1][1] + (dp[a-1][0]);
        ndp[a][0] = (dp[a][1] - dp[a-1][1]) + (dp[200][0] - dp[a-1][0]);
      }
    }
    else {
      ndp[t][1] = dp[t-1][1] + (dp[t-1][0]);
      ndp[t][0] = (dp[t][1] - dp[t-1][1]) + (dp[200][0] - dp[t-1][0]);
    }
    memcpy(dp, ndp, sizeof(ndp));
    for(int i = 1; i <= 200; i++) {
      dp[i][0] += dp[i-1][0];
      dp[i][0] %= MOD;
      dp[i][0] += MOD;
      dp[i][1] += dp[i-1][1];
      dp[i][1] %= MOD;
      dp[i][1] += MOD;
    }
  }
  printf("%lld\n", dp[200][0] % MOD);
}