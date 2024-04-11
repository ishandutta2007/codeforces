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
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    bool ok = false;
    for (int start = 0; start < SZ(s); start++) {
      for (int r = 0; r + start < SZ(s); r++) {
        if (r >= SZ(t) || s[start + r] != t[r]) {
          break;
        }
        //cout << start << ' ' << r << '\n';
        bool good = true;
        for (int i = r + 1; i < SZ(t); i++) {
          int pos = start + 2 * r - i;
          if (pos < 0 || s[pos] != t[i]) {
            good = false;
            break;
          }
        }
        if (good) {
          ok = true;
          break;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n'; 
  }
}