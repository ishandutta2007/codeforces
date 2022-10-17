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
 
const int inf = 1e9 + 10;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    while (!t.empty() && !s.empty()) {
      if (s.back() == t.back()) {
        t.pop_back();
        s.pop_back();
      } else if (SZ(s) >= 2) {
        s.pop_back();
        s.pop_back();
      } else {
        break;
      }
    }
    if (t.empty()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}