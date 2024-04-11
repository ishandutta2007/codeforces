#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> grid(1001, vector<int>(1001));
vector<ll> fact(2001), invfact(2001);
ll MOD = 1e9 + 7;
ll inv(ll b, ll p = MOD - 2) {
  if(p == 0) return 1LL;
  ll x = inv(b, p/2);
  x = x*x%MOD;
  if(p%2) x = x*b%MOD;
  return x;
}
ll choose(int x, int y) {
  if(y > x) return 0LL;
  return fact[x]*invfact[y]%MOD*invfact[x-y]%MOD;
}
int get(int a, int b, int c, int d) { //subrectangle [c...a][d...b]
  a = min(a, 1000);
  b = min(b, 1000);
  c = max(c, 1);
  d = max(d, 1);
  return grid[a][b] - grid[c-1][b] - grid[a][d-1] + grid[c-1][d-1];
}
int get(int X, int Y, int R) {
  int a = X + R, b = Y + R, c = X - R, d = Y - R;
  return get(a, b, c, d);
}
int main() {
  int N, M, R; cin >> N >> M >> R;
  vector<int> X(N), Y(N), B(N);
  fact[0] = 1LL, invfact[0] = 1LL;
  for(int i=1;i<=2000;i++) fact[i] = i*1LL*fact[i-1] % MOD, invfact[i] = inv(fact[i]);
  ll S = 0LL;
  for(int i=0;i<N;i++) {
    cin >> X[i] >> Y[i] >> B[i];
    ++grid[X[i]][Y[i]];
    S += B[i]*1LL*B[i];
  }
  for(int i=1;i<=1000;i++) {
    for(int j=1;j<=1000;j++) {
      grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
    }
  }
  vector<vector<int>> num(N, vector<int>(N));
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(min(Y[i], Y[j]) + R >= max(Y[i], Y[j]) - R && min(X[i], X[j]) + R >= max(X[i], X[j]) - R) {
        int a = min(X[i], X[j]) + R, c = max(X[i], X[j]) - R;
        int b = min(Y[i], Y[j]) + R, d = max(Y[i], Y[j]) - R;
        num[i][j] = get(a, b, c, d);
      }
    }
  }
  vector<vector<ll>> f(N, vector<ll>(N));
  //f[i][j] is the number of subsets that kill both i and j
  ll tot = choose(N, M);
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      int numBoth = num[i][i] + num[j][j] - num[i][j];
      f[i][j] = tot - choose(N - num[i][i], M) - choose(N - num[j][j], M) + choose(N - numBoth, M);
      f[i][j] %= MOD;
    }
  }
  ll ans = 0LL;
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      ans += B[i]*1LL*B[j]%MOD*f[i][j]%MOD;
      ans %= MOD;
    }
  }
  if(ans < 0) ans += MOD;
  cout << ans << "\n";
}