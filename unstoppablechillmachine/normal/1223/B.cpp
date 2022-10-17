#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s1, s2;
    cin >> s1 >> s2;
    vector<bool> u1(26), u2(26);
    for (auto it : s1) {
      u1[it - 'a'] = true;
    }
    for (auto it : s2) {
      u2[it - 'a'] = true;
    }
    bool ok =  false;
    for (int i = 0; i < 26; i++) {
      if (u1[i] && u2[i]) {
        ok = true;
      }
    }
    if (ok) {
      cout << "yes\n";
    }
    else {
      cout << "no\n";
    }
  }    
}