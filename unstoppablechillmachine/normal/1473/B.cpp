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
    string s, t;
    cin >> s >> t;
    int len = SZ(s) * SZ(t) / __gcd(SZ(s), SZ(t));
    string ans, ans2;
    while (SZ(ans) < len) {
      ans += s;
    }
    while (SZ(ans2) < len) {
      ans2 += t;
    }
    if (ans == ans2) {
      cout << ans << '\n';
    }
    else {
      cout << -1 << '\n';
    }
  }
}