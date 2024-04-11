#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
const int mod = 998244353;

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
  int Pow(int x, int y) {
    int res = 1;
    for(; y; y >>= 1, x = 1LL * x * x % mod) {
      if(y & 1) {
	res = 1LL* res * x % mod;
      }
    }
    return res;
  }
}

int A[N][N], f[N], fac[N], n, dp[N][N];

#define lowbit(x) (x & (-x))

namespace BIT {
  int S[N];
  void init() {
    memset(S, 0, sizeof(S));
  }

  void add(int x, int v) {
    for(int i = x; i < N; i += lowbit(i))
      S[i] += v;
  }

  int Sum(int x) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i))
      res += S[i];
    return res;
  }
}

namespace BIT3 {
  int S[N];
  void init() {
    memset(S, 0, sizeof(S));
  }

  void add(int x, int v) {
    for(int i = x; i < N; i += lowbit(i))
      S[i] += v;
  }

  int Sum(int x) {
    int res = 0;
    for(int i = x; i; i -= lowbit(i))
      res += S[i];
    return res;
  }
}

bool vis[N];

void Add(int x) {
  if(vis[x]) return;
  BIT3 :: add(x, -1);
  vis[x] = 1;
}

int calc(int *P, int *L) {
  int res = 0;
  if(!L[1]) {
    BIT :: init();
    for(int i = 1; i <= n; ++ i) {
      int now = P[i] - 1 - BIT :: Sum(P[i] - 1);
      Add(res, 1LL * now * fac[n - i] % mod);
      BIT :: add(P[i], 1);
    }
    return res;
  }
  BIT :: init();
  BIT3 :: init();
  memset(vis, 0, sizeof(vis));
  for(int i = 1; i <= n; ++ i) BIT3 :: add(i, 1);
  for(int i = 1; i <= n; ++ i) {
    int now = P[i] - 1 - BIT :: Sum(P[i] - 1);
    Add(L[i]);
    if(BIT :: Sum(L[i]) - BIT :: Sum(L[i] - 1) != 1 && L[i] < P[i]) {
      -- now;
    }

    int now2 = BIT3 :: Sum(P[i] - 1); int Oth = BIT3 :: Sum(n);
    if(Oth) Add(res, 1LL * now2 * dp[n - i][Oth - 1] % mod);
    Add(res, 1LL * (now - now2) * dp[n - i][Oth] % mod);
      
    BIT :: add(P[i], 1);
    Add(P[i]);
  }
  
  return res;
}

int main() {
  cin >> n;
  fac[0] = 1;
  for(int i = 1; i <= n; ++ i) fac[i] = 1LL * i * fac[i - 1] % mod;
  dp[1][0] = fac[1]; dp[0][0] = 1;
  for(int i = 2; i <= n; ++ i) {
    dp[i][0] = fac[i];
    for(int j = 1; j <= i; ++ j) {
      Add(dp[i][j], 1LL * dp[i - 1][j - 1] * (i - j) % mod);
      Add(dp[i][j], 1LL * dp[i - 1][j - 1] * (j - 1) % mod);
      if(j > 1) Add(dp[i][j], 1LL * dp[i - 2][j - 2] * (j - 1) % mod);
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      scanf("%d", &A[i][j]);
    }
    Add(ans, 1LL * calc(A[i], A[i - 1]) * Pow(dp[n][n], n - i) % mod);
  }
  cout << ans << endl;
}