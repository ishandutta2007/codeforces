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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact = mult(fact, i);
  }
  vector<vector<int>> d(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> d[i][j];
    }
  }
  int ans = mult(m, fact);
  for (int j = 0; j < m; j++) {
    int bad = 1;
    for (int pos = 0; pos < n; pos++) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (d[i][j] <= n - pos) {
          cnt++;
        }
      } 
      bad = mult(bad, max(0, n - cnt - pos));
    }
    sub(ans, bad);
  }
  cout << mult(ans, inv(fact)) << '\n';
}