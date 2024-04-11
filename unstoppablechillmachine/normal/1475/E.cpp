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

const int MOD = 1e9 + 7; 
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


const int N = 1010;
int C[N][N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  C[0][0] = 1;
  for (int i = 1; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j]);
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[-x]++;
    }
    int ans = 0;
    for (auto it : cnt) {
      if (it.S >= k) {
        ans = C[it.S][k];
        break;
      }
      else {
        k -= it.S;
      }
    }
    cout << ans << '\n';
  }
}