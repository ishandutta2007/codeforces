/**
 *    author:  wxhtzdy
 *    created: 01.02.2022 14:55:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool ok = true;   
    for (int i = 0; i < k; i++) {
      bool zero = false, one = false;
      for (int j = i; j < n; j += k) {
        if (s[j] == '0') {
          zero = true;
        }
        if (s[j] == '1') {
          one = true;
        }
      }
      if (zero && one) {
        ok = false;
        break;
      }        
      for (int j = i; j < n; j += k) {
        if (s[j] == '?') {
          if (zero) {
            s[j] = '0';
          }
          if (one) {
            s[j] = '1';
          }
        }
      }
    }         
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    int cnt = 0, bal = 0;    
    for (int i = 0; i < k; i++) {
      if (s[i] == '?') {
        cnt += 1;
      } else {
        bal += (s[i] == '0' ? -1 : +1);
      }
    }
    bal = abs(bal);
    cout << (cnt >= bal ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}