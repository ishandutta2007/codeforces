#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int MOD = 998244353;
 
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}

inline int sum(int a, int b) {
  add(a, b);
  return a;
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
  int cur = a, ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = mult(ans, cur);
    }
    b >>= 1;
    cur = mult(cur, cur);
  }  
  return ans;
}

int inv(int a) {
  return b_pow(a, MOD - 2);
}

const int N = 1e6 + 10;  
int dp[N], p[N], cnt_divs[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  for (int i = 2; i <= 1e6; i++) {
    if (!p[i]) {
      p[i] = i;
      for (int j = i * i; j <= 1e6; j += i) {
        p[j] = i;
      }
    }
  }
  cnt_divs[1] = 1;
  for (int i = 2; i <= 1e6; i++) {
    if (p[i] == i) {
      cnt_divs[i] = 2;
    }
    else {
      int cur = i, st = 0;
      while (cur % p[i] == 0) {
        st++;
        cur /= p[i];
      }
      cnt_divs[i] = cnt_divs[cur] * (st + 1);
    }
  }
  int n;
  cin >> n;
  dp[0] = dp[1] = 1;
  int current_sum = 2;
  for (int i = 2; i <= n; i++) {
    add(dp[i], current_sum);
    add(dp[i], cnt_divs[i] - 1);
    add(current_sum, dp[i]);
  }
  cout << dp[n] << '\n';
}