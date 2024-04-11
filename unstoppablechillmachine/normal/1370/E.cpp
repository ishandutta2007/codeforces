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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<char> fuck;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cnt1++;
    }
    if (t[i] == '1') {
      cnt2++;
    }
    if (s[i] != t[i]) {
      fuck.pb(s[i]);
    }
  }  
  if (cnt1 != cnt2) {
    cout << -1 << '\n';
    exit(0);
  }
  int c0 = 0, c1 = 0;
  for (auto it : fuck) {
    if (it == '1') {
      if (c0 == 0) {
        c1++;
      }
      else {
        c0--;
        c1++;
      }
    }
    else {
      if (c1 == 0) {
        c0++;
      }
      else {
        c1--;
        c0++;
      }
    }
  }
  cout << c0 + c1 << '\n';
}