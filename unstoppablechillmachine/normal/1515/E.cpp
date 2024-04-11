#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

int MOD;

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

const int N = 410;
int C[N][N], dp[N][N], calc[N];
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n >> MOD;
  for (int i = 0; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j]);
    }
  }
  for (int len = 1; len <= n; len++) {
    for (int pos = 1; pos <= len; pos++) {
      add(calc[len], C[len - 1][len - pos]);
    }
  }
  for (int len = 1; len <= n; len++) {
    dp[len][len] = calc[len];
    for (int cnt_open = 1; cnt_open < len; cnt_open++) {
      for (int first_seg_len = 1; first_seg_len < len; first_seg_len++) {
        int coef = calc[first_seg_len];
        add(dp[len][cnt_open], mult(coef, mult(dp[len - first_seg_len - 1][cnt_open - first_seg_len], C[cnt_open][first_seg_len])));
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    add(ans, dp[n][i]);
  }
  cout << ans << '\n';
}