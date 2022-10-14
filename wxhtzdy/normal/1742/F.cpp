/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 16:50:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    const int A = 26;
    vector<long long> s(A);
    vector<long long> t(A);
    s[0] = 1;
    t[0] = 1; 
    int q;
    cin >> q;
    while (q--) {
      int op;
      cin >> op;
      if (op == 1) {
        int k;
        cin >> k;
        string x;
        cin >> x;       
        for (int i = 0; i < (int) x.size(); i++) {
          int c = (int) (x[i] - 'a');
          s[c] += k;
        }
      } else {
        int k;
        cin >> k;
        string x;
        cin >> x;       
        for (int i = 0; i < (int) x.size(); i++) {
          int c = (int) (x[i] - 'a');
          t[c] += k;
        }
      }
      bool ok = false;
      for (int i = 0; i < A; i++) {
        bool only = true;
        for (int j = 0; j < A; j++) {
          if (i != j && s[j] > 0) {
            only = false;
          }
        }
        if (!only) {
          continue;
        }                   
        if (s[i] < t[i] && accumulate(t.begin(), t.end(), 0LL) == t[i]) {
          ok = true;
        }
      }
      for (int i = 0; i < A; i++) {
        if (s[i] > 0) {
          for (int j = A - 1; j > i; j--) {
            if (t[j] > 0) {
              ok = true;
              break;
            }
          }
          break;
        }
      }       
      cout << (ok ? "YES" : "NO") << '\n';
    }
  }                                                                    
  return 0;
}