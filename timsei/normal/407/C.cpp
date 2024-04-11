#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 500;
const int mod = 1e9 + 7;
const int K = 105;

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
  int Pow(int x, int y) {
    int res = 1;
    for(; y; y >>= 1, x = 1LL * x * x % mod) {
      if(y & 1) {
	res = 1LL * res * x % mod;
      }
    }
    return res;
  }
}

int n, m, l, r, k, S[K][N], fac[N], inv[N];

void prework(int n) {
  fac[0] = 1;
  for(int i = 1; i <= n; ++ i)
    fac[i] = 1LL * i * fac[i - 1] % mod;
  inv[n] = Pow(fac[n], mod - 2);
  //cerr << inv[n] << endl;
  for(int i = n - 1; i >= 0; -- i)
    inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
  //for(int i = 0; i <= n; ++ i) {
    //assert(1LL * inv[i] * fac[i] % mod == 1);
  //}
}

int C(int x, int y) {
  return 1LL * fac[x] * inv[y] % mod * inv[x - y] % mod;
}

int main() {
  //freopen("sequence.in", "r", stdin);
  //freopen("sequence.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n; ++ i) scanf("%d", &S[0][i]);
  prework(1e5 + 100);
  //cerr << C(5, 3) << endl;
  for(int i = 1; i <= m; ++ i) {
    scanf("%d%d%d", &l, &r, &k);
    ++ k;
    Add(S[k][l], 1);
    ++ r;
    -- k;
    for(int j = 1; j <= k + 1; ++ j) {
      Sub(S[j][r + j - 1], C(r - l + k, k - j + 1));
    }
  }
  for(int j = 101; j >= 1; -- j) {
    for(int p = 1; p <= n; ++ p)
      Add(S[j][p], S[j][p - 1]),
	Add(S[j - 1][p], S[j][p]);
  }
  for(int i = 1; i <= n; ++ i) printf("%d\n", S[0][i]);
}