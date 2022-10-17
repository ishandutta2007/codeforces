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
    string s;
    cin >> s;
    for (int i = 0; i < SZ(s); +i++) {
      if (i % 2 == 0) {
        if (s[i] != 'a') {
          s[i] = 'a';
        }
        else {
          s[i] = 'b';
        }
      }
      else {
        if (s[i] != 'z') {
          s[i] = 'z';
        }
        else {
          s[i] = 'y';
        }
      }
    }
    cout << s << '\n';
  }
}