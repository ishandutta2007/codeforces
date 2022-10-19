#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
const int mod = 1e9 + 7;
const int I2 = (mod + 1) / 2;

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
  int Pow(int x, int y = mod - 2) {
    int res = 1;
    for(; y; y >>= 1, x = 1LL * x * x % mod) {
      if(y & 1)
	res = 1LL * res * x % mod;
    }
    return res;
  }
}

int n, m, x, y, dp[N], B[N];
char s[N];

int main() {
  cin >> n;
  scanf("%s", s);
  for(int i = 0; i < (1 << n); ++ i) dp[i] = s[i] - '0';
  for(int i = 0; i < n; ++ i) {
    for(int j = 0; j < (1 << n); j += (1 << (i + 1)))
      for(int k = j; k < j + (1 << i); ++ k) {
      int L = dp[k], R = dp[k + (1 << i)];
      dp[k] = add(L + R);
      dp[k + (1 << i)] = sub(L - R);
    }
  }
  for(int i = 0; i < (1 << n); ++ i) dp[i] = 1LL * dp[i] * dp[i] % mod;
  for(int i = 0; i < n; ++ i) {
    for(int j = 0; j < (1 << n); j += (1 << (i + 1)))
      for(int k = j; k < j + (1 << i); ++ k) {
      int L = dp[k], R = dp[k + (1 << i)];
      dp[k] = 1LL * I2 * add(L + R) % mod;
      dp[k + (1 << i)] = 1LL * I2 * sub(L - R) % mod;
    }
  }
  int ans = 0;
  for(int i = 0; i < (1 << n); ++ i) {
    B[i] = (B[i >> 1]) + (i & 1);
    Add(ans, (1LL << (n - B[i])) * dp[i] % mod);
  }
  cout << 3LL * ans % mod << endl;
}