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

inline int sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}

inline int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

inline int b_pow(int a, int p) {
  int cur = a, ans = 1;
  while (p > 0) {
    if (p & 1) {
      ans = mult(ans, cur);
    }
    p /= 2;
    cur = mult(cur, cur); 
  }
  return ans;
}

const int lim = 1e6;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, p;
    cin >> n >> p;
    if (p == 1) {
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
      }
      cout << (n & 1) << '\n';
      continue;
    }
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    auto it = --cnt.end();
    int ans = 0, need = 0;
    for (;;) {
      if (it->S >= need) {
        it->S -= need;
        need = 0;
        ans = 0;  
      }
      else {
        sub(ans, mult(it->S, b_pow(p, it->F)));
        need -= it->S;
        it->S = 0;
      }
      //cout << it->S << ' ' << need << '\n';
      if (it->S & 1) {
        need = 1;
        ans = b_pow(p, it->F);
      }
      //cout << it->S << ' ' << need << '\n';
      if (it == cnt.begin()) {
        break;
      }
      else {
        int was = it->F;
        it--;
        if (need > 0) {
          while (need < 1e6 && was != it->F) {
            need *= p;
            was--;
          }
        }
        //cout << "C " << need << '\n';
      }
    }
    cout << ans << '\n';
  }  
}