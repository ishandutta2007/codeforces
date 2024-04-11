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
  int n;
  cin >> n;
  vector<int> x(n), y(n), s(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> s[i];
  }
  int answer = (x.back() + 1) % MOD;
  set<pair<int, int>> active_guys;
  int csum = 0;
  for (int i = n - 1; i >= 0; i--) {
    while (!active_guys.empty() && -active_guys.begin()->F > x[i]) {
      sub(csum, active_guys.begin()->S);
      active_guys.erase(active_guys.begin());
    }
    int cur = sum(csum, s[i]);
    add(answer, mult(cur, (x[i] - y[i]) % MOD));
    active_guys.insert({-y[i], cur});
    add(csum, cur);
  }
  cout << answer << '\n';
}