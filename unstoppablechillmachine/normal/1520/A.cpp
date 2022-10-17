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
    string s;
    cin >> s;
    bool ok = true;
    for (int l = 0; l < n; l++) {
      for (int mid = l + 1; mid < n; mid++) {
        for (int r = mid + 1; r < n; r++) {
          if (s[l] == s[r] && s[l] != s[mid]) {
            ok = false;
          }
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}