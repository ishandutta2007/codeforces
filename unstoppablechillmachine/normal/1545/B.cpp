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
int f[N], rf[N];

int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  return mult(f[n], mult(rf[n - k], rf[k]));
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  f[0] = rf[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = mult(f[i - 1], i);
    rf[i] = inv(f[i]);
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<char> a(n);
    int cnt_zeros = 0, cnt_pars = 0;
    bool prv = false;
    for (auto &c : a) {
      cin >> c;
      if (c == '1') {
        if (prv) {
          cnt_pars++;
          prv = false;
        } else {
          prv = true;
        }
      } else {
        cnt_zeros++;
        prv = false;
      }
    }
    cout << C(cnt_zeros + cnt_pars, cnt_pars) << '\n';
  }
}