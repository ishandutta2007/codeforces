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
    bool all_right = true, all_left = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '>') {
        all_left = false;
      }
      if (s[i] == '<') {
        all_right = false;
      }
    } 
    if (all_right || all_left) {
      cout << n << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '-' || s[(i - 1 + n) % n] == '-') {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}