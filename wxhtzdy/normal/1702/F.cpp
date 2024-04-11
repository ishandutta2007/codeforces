/**
 *    author:  wxhtzdy
 *    created: 13.07.2022 15:50:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      while (a[i] % 2 == 0) {
        a[i] /= 2;
      }
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    multiset<int> st;
    for (int i = 0; i < n; i++) {
      st.insert(a[i]);
    }
    sort(b.rbegin(), b.rend());   
    for (int i = 0; i < n; i++) {
      while (b[i] >= 1) {
        if (st.find(b[i]) != st.end()) {
          st.erase(st.find(b[i]));
          break;          
        }
        b[i] /= 2;
      }
    }
    cout << (st.empty() ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}