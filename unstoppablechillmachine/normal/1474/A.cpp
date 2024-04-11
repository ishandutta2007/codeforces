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
    int lst = 0;
    string ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (lst != 2) {
          ans.pb('1');
          lst = 2;
        }
        else {
          ans.pb('0');
          lst = 1;
        }
      }
      else {
        if (lst != 1) {
          ans.pb('1');
          lst = 1;
        }
        else {
          ans.pb('0');
          lst = 0;
        }
      }
    }
    cout << ans << '\n';
  }
}