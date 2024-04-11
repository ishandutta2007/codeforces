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

const int N = 2e5 + 10;
int f[N], inv_f[N];

int C(int n, int k) {
  if (k > n) {
    return 0;
  }
  return mult(f[n], mult(inv_f[k], inv_f[n - k]));
}

int a[N], pos[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  f[0] = 1;
  inv_f[0] = 1;
  for (int i = 1; i <= 2e5; i++) {
    f[i] = mult(f[i - 1], i);
    inv_f[i] = inv(f[i]);
  }
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  int delim = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] + 1 < n && a[i + 1] + 1 < n) {
      if (pos[a[i] + 1] > pos[a[i + 1] + 1]) {
        delim++;
      }
    } else if (a[i + 1] == n - 1) {
      delim++;
    }
  }
  int answer = 0;
  for (int all_delim = delim; all_delim < k; all_delim++) {
    add(answer, mult(C(k, all_delim + 1), C(n - 1 - delim, all_delim - delim)));
  }
  cout << answer << '\n';
}