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
    int cnta = 0, cntb = 0;
    for (auto it : s) {
      if (it == 'B') {
        if (cnta > 0) {
          cnta--;
        }
        else {
          cntb++;
        }
      }
      else {
        cnta++;
      }
    }
    cout << (cntb % 2) + cnta << '\n'; 
  }
}