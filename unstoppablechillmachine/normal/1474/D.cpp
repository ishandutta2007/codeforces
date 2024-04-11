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
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> pref(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++) {
      if (pref[i - 1] == -1) {
        pref[i] = -1;
      }
      else {
        pref[i] = a[i] - pref[i - 1];
        if (pref[i] < 0) {
          pref[i] = -1;
        }
      }
    }
    for (int i = n; i >= 1; i--) {
      if (suf[i + 1] == -1) {
        suf[i] = -1;
      }
      else {
        suf[i] = a[i] - suf[i + 1];
        if (suf[i] < 0) {
          suf[i] = -1;
        }  
      }
    }
    auto f = [&](int a, int b, int c, int d) {
      //cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
      b -= a;
      if (b < 0) {
        return -1ll;
      }
      c -= b;
      if (c < 0) {
        return -1ll;
      }
      return d - c;
    };
    bool ok = (pref[n] == 0);
    for (int pos = 1; pos < n; pos++) {
      if (pref[pos - 1] != -1 && suf[pos + 2] != -1 && f(pref[pos - 1], a[pos + 1], a[pos], suf[pos + 2]) == 0) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}