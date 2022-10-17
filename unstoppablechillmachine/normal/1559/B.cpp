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
    string ans = s;
    int start = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        start = i;
        break;
      }
    }
    if (start == -1) {
      for (int i = 0; i < n; i++) {
        cout << (i & 1 ? 'R' : 'B');
      }
      cout << '\n';
      continue;
    }
    char prv = s[start];
    for (int i = start - 1; i >= 0; i--) {
      if (prv == 'B') {
        prv = 'R';
      } else {
        prv = 'B';
      }
      ans[i] = prv;
    }
    ans[start] = s[start];
    prv = s[start];
    for (int i = start + 1; i < n; i++) {
      if (s[i] == '?') {
        if (prv == 'B') {
          ans[i] = 'R';
        } else {
          ans[i] = 'B';
        }
      } else {
        ans[i] = s[i];
      }
      prv = ans[i];
    }
    cout << ans << '\n';
  }
}