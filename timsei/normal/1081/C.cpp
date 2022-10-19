#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
const int mod = 998244353;

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
  int Pow(int x, int y = mod - 2) {
    int res = 1;
    for(; y; y >>= 1, x = 1LL * x * x % mod) {
      if(y & 1) {
	res = 1LL * res * x % mod;
      }
    }
    return res;
  }
}

int dp[N][N], n, m, k, C[N][N];

int main() {
  C[0][0] = 1;
  for(int i = 1; i < N; ++ i) {
    C[i][0] = 1;
    for(int j = 1; j < N; ++ j)
      C[i][j] = add(C[i - 1][j - 1] + C[i - 1][j]);
  }
  cin >> n >> m >> k;
  cout << 1LL * C[n - 1][k] * m % mod * Pow(m - 1, k) % mod << endl;
}